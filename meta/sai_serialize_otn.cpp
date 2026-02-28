#include "sai_serialize_otn.h"
#include "meta/sai_serialize.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;


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

std::string sai_serialize_otn_alarm_event_ntf(
        _In_ uint32_t count,
        _In_ const sai_otn_alarm_event_data_t* otn_alarm_event)
{
    SWSS_LOG_ENTER();

    if (otn_alarm_event == NULL)
    {
        SWSS_LOG_THROW("otn_alarm_event pointer is null");
    }

    json j = json::array();

    for (uint32_t i = 0; i < count; ++i)
    {
        json item;

        item["object_id"] = sai_serialize_object_id(otn_alarm_event[i].object_id);
        /* cast from uint8_t* to string */
        item["event_name"] = std::string((char*)otn_alarm_event[i].event_name.list, otn_alarm_event[i].event_name.count);
        item["timestamp"] = sai_serialize_timespec(otn_alarm_event[i].timestamp);
        item["severity"] = sai_serialize_enum(otn_alarm_event[i].severity, &sai_metadata_enum_sai_otn_alarm_severity_t);
        item["action"] = sai_serialize_enum(otn_alarm_event[i].action, &sai_metadata_enum_sai_otn_alarm_action_t);
        /* cast from uint8_t* to string */
        item["description"] = std::string((char*)otn_alarm_event[i].description.list, otn_alarm_event[i].description.count);
        /* cast from uint8_t* to hex binary */
        item["data"] = sai_serialize_hex_binary(otn_alarm_event[i].data.list, otn_alarm_event[i].data.count);
        j.push_back(item);
    }

    return j.dump();
}

void sai_deserialize_otn_alarm_event_ntf(
        _In_ const std::string& s,
        _Out_ uint32_t& count,
        _Out_ sai_otn_alarm_event_data_t** otn_alarm_event)
{
    SWSS_LOG_ENTER();

    json j = json::parse(s);

    count = (uint32_t)j.size();

    auto data = new sai_otn_alarm_event_data_t[count];

    for (uint32_t i = 0; i < count; ++i)
    {
        sai_deserialize_object_id(j[i]["object_id"], data[i].object_id);

        std::string s_event_name = j[i]["event_name"];
        data[i].event_name.count = (uint32_t)s_event_name.length();
        data[i].event_name.list = new uint8_t[data[i].event_name.count + 1];
        memcpy(data[i].event_name.list, s_event_name.c_str(), data[i].event_name.count + 1);

        sai_deserialize_timespec(j[i]["timestamp"], data[i].timestamp);

        int32_t val;
        sai_deserialize_enum(j[i]["severity"], &sai_metadata_enum_sai_otn_alarm_severity_t, val);
        data[i].severity = (sai_otn_alarm_severity_t)val;

        sai_deserialize_enum(j[i]["action"], &sai_metadata_enum_sai_otn_alarm_action_t, val);
        data[i].action = (sai_otn_alarm_action_t)val;

        std::string s_desc = j[i]["description"];
        data[i].description.count = (uint32_t)s_desc.length();
        data[i].description.list = new uint8_t[data[i].description.count + 1];
        memcpy(data[i].description.list, s_desc.c_str(), data[i].description.count + 1);

        std::string s_data = j[i]["data"];
        data[i].data.count = (uint32_t)s_data.length() / 2;
        data[i].data.list = new uint8_t[data[i].data.count];
        sai_deserialize_hex_binary(s_data, data[i].data.list, data[i].data.count);
    }

    *otn_alarm_event = data;
}

void sai_deserialize_free_otn_alarm_event_ntf(
        _In_ uint32_t count,
        _In_ sai_otn_alarm_event_data_t* otn_alarm_event)
{
    SWSS_LOG_ENTER();

    for (uint32_t i = 0; i < count; ++i)
    {
        delete[] otn_alarm_event[i].event_name.list;
        delete[] otn_alarm_event[i].description.list;
        delete[] otn_alarm_event[i].data.list;
    }

    delete[] otn_alarm_event;
}
