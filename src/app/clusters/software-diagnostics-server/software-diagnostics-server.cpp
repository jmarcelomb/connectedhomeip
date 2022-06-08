/**
 *
 *    Copyright (c) 2021 Project CHIP Authors
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

#include "software-diagnostics-server.h"
#include <app-common/zap-generated/attributes/Accessors.h>
#include <app-common/zap-generated/cluster-objects.h>
#include <app-common/zap-generated/ids/Attributes.h>
#include <app-common/zap-generated/ids/Clusters.h>
#include <app/AttributeAccessInterface.h>
#include <app/CommandHandler.h>
#include <app/ConcreteCommandPath.h>
#include <app/EventLogging.h>
#include <app/util/af.h>
#include <app/util/attribute-storage.h>
#include <lib/core/Optional.h>
#include <platform/DiagnosticDataProvider.h>

using namespace chip;
using namespace chip::app;
using namespace chip::app::Clusters;
using namespace chip::app::Clusters::SoftwareDiagnostics;
using namespace chip::app::Clusters::SoftwareDiagnostics::Attributes;
using chip::DeviceLayer::DiagnosticDataProvider;
using chip::DeviceLayer::GetDiagnosticDataProvider;

namespace {

class SoftwareDiagosticsAttrAccess : public AttributeAccessInterface
{
public:
    // Register for the SoftwareDiagnostics cluster on all endpoints.
    SoftwareDiagosticsAttrAccess() : AttributeAccessInterface(Optional<EndpointId>::Missing(), SoftwareDiagnostics::Id) {}

    CHIP_ERROR Read(const ConcreteReadAttributePath & aPath, AttributeValueEncoder & aEncoder) override;

private:
    CHIP_ERROR ReadIfSupported(CHIP_ERROR (DiagnosticDataProvider::*getter)(uint64_t &), AttributeValueEncoder & aEncoder);
    CHIP_ERROR ReadThreadMetrics(AttributeValueEncoder & aEncoder);
};

SoftwareDiagosticsAttrAccess gAttrAccess;

CHIP_ERROR SoftwareDiagosticsAttrAccess::Read(const ConcreteReadAttributePath & aPath, AttributeValueEncoder & aEncoder)
{
    if (aPath.mClusterId != SoftwareDiagnostics::Id)
    {
        // We shouldn't have been called at all.
        return CHIP_ERROR_INVALID_ARGUMENT;
    }

    switch (aPath.mAttributeId)
    {
    case CurrentHeapFree::Id:
        return ReadIfSupported(&DiagnosticDataProvider::GetCurrentHeapFree, aEncoder);
    case CurrentHeapUsed::Id:
        return ReadIfSupported(&DiagnosticDataProvider::GetCurrentHeapUsed, aEncoder);
    case CurrentHeapHighWatermark::Id:
        return ReadIfSupported(&DiagnosticDataProvider::GetCurrentHeapHighWatermark, aEncoder);
    case ThreadMetrics::Id:
        return ReadThreadMetrics(aEncoder);
    case Clusters::Globals::Attributes::FeatureMap::Id: {
        BitFlags<SoftwareDiagnosticsFeature> features;

        if (DeviceLayer::GetDiagnosticDataProvider().SupportsWatermarks())
        {
            features.Set(SoftwareDiagnosticsFeature::kWaterMarks);
        }

        return aEncoder.Encode(features);
    }
    default:
        break;
    }
    return CHIP_NO_ERROR;
}

CHIP_ERROR SoftwareDiagosticsAttrAccess::ReadIfSupported(CHIP_ERROR (DiagnosticDataProvider::*getter)(uint64_t &),
                                                         AttributeValueEncoder & aEncoder)
{
    uint64_t data;
    CHIP_ERROR err = (DeviceLayer::GetDiagnosticDataProvider().*getter)(data);
    if (err == CHIP_ERROR_UNSUPPORTED_CHIP_FEATURE)
    {
        data = 0;
    }
    else if (err != CHIP_NO_ERROR)
    {
        return err;
    }

    return aEncoder.Encode(data);
}

CHIP_ERROR SoftwareDiagosticsAttrAccess::ReadThreadMetrics(AttributeValueEncoder & aEncoder)
{
    CHIP_ERROR err = CHIP_NO_ERROR;
    DeviceLayer::ThreadMetrics * threadMetrics;

    if (DeviceLayer::GetDiagnosticDataProvider().GetThreadMetrics(&threadMetrics) == CHIP_NO_ERROR)
    {
        err = aEncoder.EncodeList([&threadMetrics](const auto & encoder) -> CHIP_ERROR {
            for (DeviceLayer::ThreadMetrics * thread = threadMetrics; thread != nullptr; thread = thread->Next)
            {
                ReturnErrorOnFailure(encoder.Encode(*thread));
            }

            return CHIP_NO_ERROR;
        });

        DeviceLayer::GetDiagnosticDataProvider().ReleaseThreadMetrics(threadMetrics);
    }
    else
    {
        err = aEncoder.EncodeEmptyList();
    }

    return err;
}

} // anonymous namespace

namespace chip {
namespace app {
namespace Clusters {

SoftwareDiagnosticsServer SoftwareDiagnosticsServer::instance;

/**********************************************************
 * SoftwareDiagnosticsServer Implementation
 *********************************************************/

SoftwareDiagnosticsServer & SoftwareDiagnosticsServer::Instance()
{
    return instance;
}

// Gets called when a software fault that has taken place on the Node.
void SoftwareDiagnosticsServer::OnSoftwareFaultDetect(const SoftwareDiagnostics::Structs::SoftwareFaultStruct::Type & softwareFault)
{
    ChipLogDetail(Zcl, "SoftwareDiagnosticsDelegate: OnSoftwareFaultDetected");

    for (auto endpoint : EnabledEndpointsWithServerCluster(SoftwareDiagnostics::Id))
    {
        // If Software Diagnostics cluster is implemented on this endpoint
        EventNumber eventNumber;
        Events::SoftwareFault::Type event{ softwareFault };

        if (CHIP_NO_ERROR != LogEvent(event, endpoint, eventNumber))
        {
            ChipLogError(Zcl, "SoftwareDiagnosticsDelegate: Failed to record SoftwareFault event");
        }
    }
}

} // namespace Clusters
} // namespace app
} // namespace chip

bool emberAfSoftwareDiagnosticsClusterResetWatermarksCallback(app::CommandHandler * commandObj,
                                                              const app::ConcreteCommandPath & commandPath,
                                                              const Commands::ResetWatermarks::DecodableType & commandData)
{
    EmberAfStatus status = EMBER_ZCL_STATUS_SUCCESS;

    // If implemented, the server SHALL set the value of the CurrentHeapHighWatermark attribute to the
    // value of the CurrentHeapUsed.
    if (DeviceLayer::GetDiagnosticDataProvider().ResetWatermarks() != CHIP_NO_ERROR)
    {
        status = EMBER_ZCL_STATUS_FAILURE;
    }

    emberAfSendImmediateDefaultResponse(status);

    return true;
}

void MatterSoftwareDiagnosticsPluginServerInitCallback()
{
    registerAttributeAccessOverride(&gAttrAccess);
}
