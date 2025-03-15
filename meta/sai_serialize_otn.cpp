#include "sai_serialize_otn.h"
#include "meta/sai_serialize.h"

std::string sai_serialize_otn_attenuator_attr(
        _In_ const sai_otn_attenuator_attr_t counter)
{
    SWSS_LOG_ENTER();

    return sai_serialize_enum(counter, &sai_metadata_enum_sai_otn_attenuator_attr_t);
}

void sai_deserialize_otn_attenuator_attr(
        _In_ const std::string& s,
        _Out_ sai_otn_attenuator_attr_t& attr)
{
    SWSS_LOG_ENTER();

    sai_deserialize_enum(s, &sai_metadata_enum_sai_otn_attenuator_attr_t, (int32_t&)attr);
}

std::string sai_serialize_otn_oa_attr(
        _In_ const sai_otn_oa_attr_t counter)
{
    SWSS_LOG_ENTER();

    return sai_serialize_enum(counter, &sai_metadata_enum_sai_otn_oa_attr_t);
}

void sai_deserialize_otn_oa_attr(
        _In_ const std::string& s,
        _Out_ sai_otn_oa_attr_t& attr)
{
    SWSS_LOG_ENTER();

    sai_deserialize_enum(s, &sai_metadata_enum_sai_otn_oa_attr_t, (int32_t&)attr);
}

std::string sai_serialize_otn_ocm_attr(
        _In_ const sai_otn_ocm_attr_t counter)
{
    SWSS_LOG_ENTER();

    return sai_serialize_enum(counter, &sai_metadata_enum_sai_otn_ocm_attr_t);
}

void sai_deserialize_otn_ocm_attr(
        _In_ const std::string& s,
        _Out_ sai_otn_ocm_attr_t& attr)
{
    SWSS_LOG_ENTER();

    sai_deserialize_enum(s, &sai_metadata_enum_sai_otn_ocm_attr_t, (int32_t&)attr);
}


std::string sai_serialize_otn_ocm_channel_attr(
        _In_ const sai_otn_ocm_channel_attr_t counter)
{
    SWSS_LOG_ENTER();

    return sai_serialize_enum(counter, &sai_metadata_enum_sai_otn_ocm_channel_attr_t);
}

void sai_deserialize_otn_ocm_channel_attr(
        _In_ const std::string& s,
        _Out_ sai_otn_ocm_channel_attr_t& attr)
{
    SWSS_LOG_ENTER();

    sai_deserialize_enum(s, &sai_metadata_enum_sai_otn_ocm_channel_attr_t, (int32_t&)attr);
}

std::string sai_serialize_otn_osc_attr(
        _In_ const sai_otn_osc_attr_t counter)
{
    SWSS_LOG_ENTER();

    return sai_serialize_enum(counter, &sai_metadata_enum_sai_otn_osc_attr_t);
}

void sai_deserialize_otn_osc_attr(
        _In_ const std::string& s,
        _Out_ sai_otn_osc_attr_t& attr)
{
    SWSS_LOG_ENTER();

    sai_deserialize_enum(s, &sai_metadata_enum_sai_otn_osc_attr_t, (int32_t&)attr);
}
