/*
 *
 *    Copyright (c) 2022 Project CHIP Authors
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

// THIS FILE IS GENERATED BY ZAP

// Prevent multiple inclusion
#pragma once

#include <stdint.h>

#include <app/util/basic-types.h>
#include <lib/core/GroupId.h>
#include <lib/core/NodeId.h>
#include <lib/support/Span.h>
#include <protocols/interaction_model/Constants.h>

#include "enums.h"

// Struct for SimpleStruct
typedef struct _SimpleStruct
{
    uint8_t a;
    bool b;
    uint8_t c;
    chip::ByteSpan d;
    chip::CharSpan e;
    uint8_t f;
    float g;
    double h;
} SimpleStruct;

// Struct for TestFabricScoped
typedef struct _TestFabricScoped
{
    uint8_t fabricSensitiveInt8u;
    uint8_t optionalFabricSensitiveInt8u;
    uint8_t nullableFabricSensitiveInt8u;
    uint8_t nullableOptionalFabricSensitiveInt8u;
    chip::CharSpan fabricSensitiveCharString;
    SimpleStruct fabricSensitiveStruct;
    /* TYPE WARNING: array array defaults to */ uint8_t * fabricSensitiveInt8uList;
    chip::FabricIndex fabricIndex;
} TestFabricScoped;

// Struct for Dimension
typedef struct _Dimension
{
    double width;
    double height;
    uint8_t metric;
} Dimension;

// Struct for AdditionalInfo
typedef struct _AdditionalInfo
{
    chip::CharSpan name;
    chip::CharSpan value;
} AdditionalInfo;

// Struct for NullablesAndOptionalsStruct
typedef struct _NullablesAndOptionalsStruct
{
    uint16_t NullableInt;
    uint16_t OptionalInt;
    uint16_t NullableOptionalInt;
    chip::CharSpan NullableString;
    chip::CharSpan OptionalString;
    chip::CharSpan NullableOptionalString;
    SimpleStruct NullableStruct;
    SimpleStruct OptionalStruct;
    SimpleStruct NullableOptionalStruct;
    /* TYPE WARNING: array array defaults to */ uint8_t * NullableList;
    /* TYPE WARNING: array array defaults to */ uint8_t * OptionalList;
    /* TYPE WARNING: array array defaults to */ uint8_t * NullableOptionalList;
} NullablesAndOptionalsStruct;

// Struct for NestedStruct
typedef struct _NestedStruct
{
    uint8_t a;
    bool b;
    SimpleStruct c;
} NestedStruct;

// Struct for SemanticTag
typedef struct _SemanticTag
{
    uint16_t MfgCode;
    uint16_t Value;
} SemanticTag;

// Struct for ModeOptionStruct
typedef struct _ModeOptionStruct
{
    chip::CharSpan Label;
    uint8_t Mode;
    /* TYPE WARNING: array array defaults to */ uint8_t * SemanticTags;
} ModeOptionStruct;

// Struct for AttributeValuePair
typedef struct _AttributeValuePair
{
    chip::AttributeId AttributeId;
    /* TYPE WARNING: array array defaults to */ uint8_t * AttributeValue;
} AttributeValuePair;

// Struct for ExtensionFieldSet
typedef struct _ExtensionFieldSet
{
    chip::ClusterId ClusterId;
    /* TYPE WARNING: array array defaults to */ uint8_t * AttributeValueList;
} ExtensionFieldSet;

// Struct for NestedStructList
typedef struct _NestedStructList
{
    uint8_t a;
    bool b;
    SimpleStruct c;
    /* TYPE WARNING: array array defaults to */ uint8_t * d;
    /* TYPE WARNING: array array defaults to */ uint8_t * e;
    /* TYPE WARNING: array array defaults to */ uint8_t * f;
    /* TYPE WARNING: array array defaults to */ uint8_t * g;
} NestedStructList;

// Struct for DoubleNestedStructList
typedef struct _DoubleNestedStructList
{
    /* TYPE WARNING: array array defaults to */ uint8_t * a;
} DoubleNestedStructList;

// Struct for Parameter
typedef struct _Parameter
{
    uint8_t type;
    chip::CharSpan value;
    /* TYPE WARNING: array array defaults to */ uint8_t * externalIDList;
} Parameter;

// Struct for ContentSearch
typedef struct _ContentSearch
{
    /* TYPE WARNING: array array defaults to */ uint8_t * parameterList;
} ContentSearch;

// Struct for StyleInformation
typedef struct _StyleInformation
{
    chip::CharSpan imageUrl;
    chip::CharSpan color;
    Dimension size;
} StyleInformation;

// Struct for BrandingInformation
typedef struct _BrandingInformation
{
    chip::CharSpan providerName;
    StyleInformation background;
    StyleInformation logo;
    StyleInformation progressBar;
    StyleInformation splash;
    StyleInformation waterMark;
} BrandingInformation;

// Struct for Application
typedef struct _Application
{
    uint16_t catalogVendorId;
    chip::CharSpan applicationId;
} Application;

// Struct for ApplicationEP
typedef struct _ApplicationEP
{
    Application application;
    chip::EndpointId endpoint;
} ApplicationEP;

// Struct for Target
typedef struct _Target
{
    chip::ClusterId Cluster;
    chip::EndpointId Endpoint;
    chip::DeviceTypeId DeviceType;
} Target;

// Struct for AccessControlEntry
typedef struct _AccessControlEntry
{
    uint8_t Privilege;
    uint8_t AuthMode;
    /* TYPE WARNING: array array defaults to */ uint8_t * Subjects;
    /* TYPE WARNING: array array defaults to */ uint8_t * Targets;
    chip::FabricIndex FabricIndex;
} AccessControlEntry;

// Struct for ActionStruct
typedef struct _ActionStruct
{
    uint16_t ActionID;
    chip::CharSpan Name;
    uint8_t Type;
    uint16_t EndpointListID;
    uint16_t SupportedCommands;
    uint8_t Status;
} ActionStruct;

// Struct for ApplicationBasicApplication
typedef struct _ApplicationBasicApplication
{
    uint16_t catalogVendorId;
    chip::CharSpan applicationId;
} ApplicationBasicApplication;

// Struct for BasicCommissioningInfo
typedef struct _BasicCommissioningInfo
{
    uint16_t FailSafeExpiryLengthSeconds;
    uint16_t MaxCumulativeFailsafeSeconds;
} BasicCommissioningInfo;

// Struct for BatChargeFaultChangeType
typedef struct _BatChargeFaultChangeType
{
    /* TYPE WARNING: array array defaults to */ uint8_t * current;
    /* TYPE WARNING: array array defaults to */ uint8_t * previous;
} BatChargeFaultChangeType;

// Struct for BatFaultChangeType
typedef struct _BatFaultChangeType
{
    /* TYPE WARNING: array array defaults to */ uint8_t * current;
    /* TYPE WARNING: array array defaults to */ uint8_t * previous;
} BatFaultChangeType;

// Struct for CapabilityMinimaStruct
typedef struct _CapabilityMinimaStruct
{
    uint16_t CaseSessionsPerFabric;
    uint16_t SubscriptionsPerFabric;
} CapabilityMinimaStruct;

// Struct for ChannelInfo
typedef struct _ChannelInfo
{
    uint16_t majorNumber;
    uint16_t minorNumber;
    chip::CharSpan name;
    chip::CharSpan callSign;
    chip::CharSpan affiliateCallSign;
} ChannelInfo;

// Struct for DeviceType
typedef struct _DeviceType
{
    chip::DeviceTypeId type;
    uint16_t revision;
} DeviceType;

// Struct for DlCredential
typedef struct _DlCredential
{
    uint8_t CredentialType;
    uint16_t CredentialIndex;
} DlCredential;

// Struct for EndpointListStruct
typedef struct _EndpointListStruct
{
    uint16_t EndpointListID;
    chip::CharSpan Name;
    uint8_t Type;
    /* TYPE WARNING: array array defaults to */ uint8_t * Endpoints;
} EndpointListStruct;

// Struct for ExtensionEntry
typedef struct _ExtensionEntry
{
    chip::ByteSpan Data;
    chip::FabricIndex FabricIndex;
} ExtensionEntry;

// Struct for FabricDescriptor
typedef struct _FabricDescriptor
{
    chip::ByteSpan RootPublicKey;
    chip::VendorId VendorId;
    chip::FabricId FabricId;
    chip::NodeId NodeId;
    chip::CharSpan Label;
    chip::FabricIndex FabricIndex;
} FabricDescriptor;

// Struct for GroupInfoMapStruct
typedef struct _GroupInfoMapStruct
{
    chip::GroupId GroupId;
    /* TYPE WARNING: array array defaults to */ uint8_t * Endpoints;
    chip::CharSpan GroupName;
    chip::FabricIndex FabricIndex;
} GroupInfoMapStruct;

// Struct for GroupKeyMapStruct
typedef struct _GroupKeyMapStruct
{
    chip::GroupId GroupId;
    uint16_t GroupKeySetID;
    chip::FabricIndex FabricIndex;
} GroupKeyMapStruct;

// Struct for GroupKeySetStruct
typedef struct _GroupKeySetStruct
{
    uint16_t GroupKeySetID;
    uint8_t GroupKeySecurityPolicy;
    chip::ByteSpan EpochKey0;
    uint64_t EpochStartTime0;
    chip::ByteSpan EpochKey1;
    uint64_t EpochStartTime1;
    chip::ByteSpan EpochKey2;
    uint64_t EpochStartTime2;
} GroupKeySetStruct;

// Struct for InputInfo
typedef struct _InputInfo
{
    uint8_t index;
    uint8_t inputType;
    chip::CharSpan name;
    chip::CharSpan description;
} InputInfo;

// Struct for LabelStruct
typedef struct _LabelStruct
{
    chip::CharSpan label;
    chip::CharSpan value;
} LabelStruct;

// Struct for LineupInfo
typedef struct _LineupInfo
{
    chip::CharSpan operatorName;
    chip::CharSpan lineupName;
    chip::CharSpan postalCode;
    uint8_t lineupInfoType;
} LineupInfo;

// Struct for NOCStruct
typedef struct _NOCStruct
{
    chip::ByteSpan NOC;
    chip::ByteSpan ICAC;
    chip::FabricIndex FabricIndex;
} NOCStruct;

// Struct for NeighborTable
typedef struct _NeighborTable
{
    uint64_t ExtAddress;
    uint32_t Age;
    uint16_t Rloc16;
    uint32_t LinkFrameCounter;
    uint32_t MleFrameCounter;
    uint8_t LQI;
    int8_t AverageRssi;
    int8_t LastRssi;
    uint8_t FrameErrorRate;
    uint8_t MessageErrorRate;
    bool RxOnWhenIdle;
    bool FullThreadDevice;
    bool FullNetworkData;
    bool IsChild;
} NeighborTable;

// Struct for NetworkInfo
typedef struct _NetworkInfo
{
    chip::ByteSpan NetworkID;
    bool Connected;
} NetworkInfo;

// Struct for NetworkInterfaceType
typedef struct _NetworkInterfaceType
{
    chip::CharSpan Name;
    bool IsOperational;
    bool OffPremiseServicesReachableIPv4;
    bool OffPremiseServicesReachableIPv6;
    chip::ByteSpan HardwareAddress;
    /* TYPE WARNING: array array defaults to */ uint8_t * IPv4Addresses;
    /* TYPE WARNING: array array defaults to */ uint8_t * IPv6Addresses;
    uint8_t Type;
} NetworkInterfaceType;

// Struct for Notification
typedef struct _Notification
{
    uint16_t contentId;
    uint8_t statusFeedback;
} Notification;

// Struct for OperationalDatasetComponents
typedef struct _OperationalDatasetComponents
{
    bool ActiveTimestampPresent;
    bool PendingTimestampPresent;
    bool MasterKeyPresent;
    bool NetworkNamePresent;
    bool ExtendedPanIdPresent;
    bool MeshLocalPrefixPresent;
    bool DelayPresent;
    bool PanIdPresent;
    bool ChannelPresent;
    bool PskcPresent;
    bool SecurityPolicyPresent;
    bool ChannelMaskPresent;
} OperationalDatasetComponents;

// Struct for OutputInfo
typedef struct _OutputInfo
{
    uint8_t index;
    uint8_t outputType;
    chip::CharSpan name;
} OutputInfo;

// Struct for PlaybackPosition
typedef struct _PlaybackPosition
{
    uint64_t updatedAt;
    uint64_t position;
} PlaybackPosition;

// Struct for PowerProfileRecord
typedef struct _PowerProfileRecord
{
    uint8_t powerProfileId;
    uint8_t energyPhaseId;
    bool powerProfileRemoteControl;
    uint8_t powerProfileState;
} PowerProfileRecord;

// Struct for ProviderLocation
typedef struct _ProviderLocation
{
    chip::NodeId ProviderNodeID;
    chip::EndpointId Endpoint;
    chip::FabricIndex FabricIndex;
} ProviderLocation;

// Struct for ReadAttributeStatusRecord
typedef struct _ReadAttributeStatusRecord
{
    chip::AttributeId attributeId;
    uint8_t status;
    uint8_t attributeType;
    uint8_t * attributeLocation;
} ReadAttributeStatusRecord;

// Struct for ReadStructuredAttributeRecord
typedef struct _ReadStructuredAttributeRecord
{
    chip::AttributeId attributeId;
    uint8_t indicator;
    /* TYPE WARNING: array array defaults to */ uint8_t * indicies;
} ReadStructuredAttributeRecord;

// Struct for RouteTable
typedef struct _RouteTable
{
    uint64_t ExtAddress;
    uint16_t Rloc16;
    uint8_t RouterId;
    uint8_t NextHop;
    uint8_t PathCost;
    uint8_t LQIIn;
    uint8_t LQIOut;
    uint8_t Age;
    bool Allocated;
    bool LinkEstablished;
} RouteTable;

// Struct for ScheduledPhase
typedef struct _ScheduledPhase
{
    uint8_t energyPhaseId;
    uint16_t scheduledTime;
} ScheduledPhase;

// Struct for SecurityPolicy
typedef struct _SecurityPolicy
{
    uint16_t RotationTime;
    uint16_t Flags;
} SecurityPolicy;

// Struct for SoftwareFaultStruct
typedef struct _SoftwareFaultStruct
{
    uint64_t Id;
    chip::CharSpan Name;
    chip::ByteSpan FaultRecording;
} SoftwareFaultStruct;

// Struct for TargetInfo
typedef struct _TargetInfo
{
    uint8_t identifier;
    chip::CharSpan name;
} TargetInfo;

// Struct for TargetStruct
typedef struct _TargetStruct
{
    chip::NodeId Node;
    chip::GroupId Group;
    chip::EndpointId Endpoint;
    chip::ClusterId Cluster;
    chip::FabricIndex FabricIndex;
} TargetStruct;

// Struct for TestListStructOctet
typedef struct _TestListStructOctet
{
    uint64_t member1;
    chip::ByteSpan member2;
} TestListStructOctet;

// Struct for ThermostatScheduleTransition
typedef struct _ThermostatScheduleTransition
{
    uint16_t TransitionTime;
    int16_t HeatSetpoint;
    int16_t CoolSetpoint;
} ThermostatScheduleTransition;

// Struct for ThreadInterfaceScanResult
typedef struct _ThreadInterfaceScanResult
{
    uint16_t PanId;
    uint64_t ExtendedPanId;
    chip::CharSpan NetworkName;
    uint16_t Channel;
    uint8_t Version;
    chip::ByteSpan ExtendedAddress;
    int8_t RSSI;
    uint8_t LQI;
} ThreadInterfaceScanResult;

// Struct for ThreadMetrics
typedef struct _ThreadMetrics
{
    uint64_t Id;
    chip::CharSpan Name;
    uint32_t StackFreeCurrent;
    uint32_t StackFreeMinimum;
    uint32_t StackSize;
} ThreadMetrics;

// Struct for TransferredPhase
typedef struct _TransferredPhase
{
    uint8_t energyPhaseId;
    uint8_t macroPhaseId;
    uint16_t expectedDuration;
    uint16_t peakPower;
    uint16_t energy;
    uint16_t maxActivationDelay;
} TransferredPhase;

// Struct for WiFiInterfaceScanResult
typedef struct _WiFiInterfaceScanResult
{
    uint8_t Security;
    chip::ByteSpan SSID;
    chip::ByteSpan BSSID;
    uint16_t Channel;
    uint8_t WiFiBand;
    int8_t RSSI;
} WiFiInterfaceScanResult;

// Struct for WiredFaultChangeType
typedef struct _WiredFaultChangeType
{
    /* TYPE WARNING: array array defaults to */ uint8_t * current;
    /* TYPE WARNING: array array defaults to */ uint8_t * previous;
} WiredFaultChangeType;

// Struct for WriteAttributeRecord
typedef struct _WriteAttributeRecord
{
    chip::AttributeId attributeId;
    uint8_t attributeType;
    uint8_t * attributeLocation;
} WriteAttributeRecord;

// Struct for WriteAttributeStatusRecord
typedef struct _WriteAttributeStatusRecord
{
    uint8_t status;
    chip::AttributeId attributeId;
} WriteAttributeStatusRecord;

// Struct for WriteStructuredAttributeRecord
typedef struct _WriteStructuredAttributeRecord
{
    chip::AttributeId attributeId;
    uint8_t indicator;
    /* TYPE WARNING: array array defaults to */ uint8_t * indicies;
    uint8_t attributeType;
    uint8_t * attributeLocation;
} WriteStructuredAttributeRecord;

// Struct for WriteStructuredAttributeStatusRecord
typedef struct _WriteStructuredAttributeStatusRecord
{
    uint8_t status;
    chip::AttributeId attributeId;
    uint8_t indicator;
    /* TYPE WARNING: array array defaults to */ uint8_t * indicies;
} WriteStructuredAttributeStatusRecord;
