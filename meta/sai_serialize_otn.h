#pragma once

extern "C" {
#include "sai.h"
#include "saimetadata.h"
}

#include <string>

// OTN attenuator
std::string sai_serialize_otn_attenuator_attr(
        _In_ const sai_otn_attenuator_attr_t counter);

void sai_deserialize_otn_attenuator_attr(
        _In_ const std::string& s,
        _Out_ sai_otn_attenuator_attr_t& attr);

// OTN oa
std::string sai_serialize_otn_oa_attr(
        _In_ const sai_otn_oa_attr_t counter);

void sai_deserialize_otn_oa_attr(
        _In_ const std::string& s,
        _Out_ sai_otn_oa_attr_t& attr);

// OTN ocm
std::string sai_serialize_otn_ocm_attr(
        _In_ const sai_otn_ocm_attr_t counter);

void sai_deserialize_otn_ocm_attr(
        _In_ const std::string& s,
        _Out_ sai_otn_ocm_attr_t& attr);

// OTN ocm channel
std::string sai_serialize_otn_ocm_channel_attr(
        _In_ const sai_otn_ocm_channel_attr_t counter);

void sai_deserialize_otn_ocm_channel_attr(
        _In_ const std::string& s,
        _Out_ sai_otn_ocm_channel_attr_t& attr);

// OTN osc
std::string sai_serialize_otn_osc_attr(
        _In_ const sai_otn_osc_attr_t counter);

void sai_deserialize_otn_osc_attr(
        _In_ const std::string& s,
        _Out_ sai_otn_osc_attr_t& attr);

// OTN alarm event notification
std::string sai_serialize_otn_alarm_event_ntf(
        _In_ uint32_t count,
        _In_ const sai_otn_alarm_event_data_t *otn_alarm_event);

void sai_deserialize_otn_alarm_event_ntf(
        _In_ const std::string& s,
        _Out_ uint32_t& count,
        _Out_ sai_otn_alarm_event_data_t** otn_alarm_event);

void sai_deserialize_free_otn_alarm_event_ntf(
        _In_ uint32_t count,
        _In_ sai_otn_alarm_event_data_t* otn_alarm_event);
