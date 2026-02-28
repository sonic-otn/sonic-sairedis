#include "NotificationOtnAlarmEvent.h"

#include "swss/logger.h"

#include "meta/sai_serialize_otn.h"

using namespace sairedis;

NotificationOtnAlarmEvent::NotificationOtnAlarmEvent(
        _In_ const std::string& serializeNotification):
    Notification(
        SAI_SWITCH_NOTIFICATION_TYPE_OTN_ALARM_EVENT,
        serializeNotification),
    m_otnAlarmEventData(nullptr)
{
    SWSS_LOG_ENTER();

    sai_deserialize_otn_alarm_event_ntf(
        serializeNotification,
        m_count,
        &m_otnAlarmEventData);
}

NotificationOtnAlarmEvent::~NotificationOtnAlarmEvent()
{
    SWSS_LOG_ENTER();

    sai_deserialize_free_otn_alarm_event_ntf(m_count, m_otnAlarmEventData);
}

sai_object_id_t NotificationOtnAlarmEvent::getSwitchId() const
{
    SWSS_LOG_ENTER();

    // Otn alarm event does not have switch id
    return SAI_NULL_OBJECT_ID;
}

sai_object_id_t NotificationOtnAlarmEvent::getAnyObjectId() const
{
    SWSS_LOG_ENTER();

    if (m_otnAlarmEventData == nullptr)
    {
        return SAI_NULL_OBJECT_ID;
    }

    for (uint32_t i = 0; i < m_count; ++i)
    {
        if (m_otnAlarmEventData[i].object_id != SAI_NULL_OBJECT_ID)
        {
            return m_otnAlarmEventData[i].object_id;
        }
    }

    return SAI_NULL_OBJECT_ID;
}

void NotificationOtnAlarmEvent::processMetadata(
        _In_ std::shared_ptr<saimeta::Meta> meta) const
{
    SWSS_LOG_ENTER();

    meta->meta_sai_on_otn_alarm_event(
            m_count,
            m_otnAlarmEventData);
}

void NotificationOtnAlarmEvent::executeCallback(
        _In_ const sai_switch_notifications_t& switchNotifications) const
{
    SWSS_LOG_ENTER();

    if(switchNotifications.on_otn_alarm_event)
    {
        switchNotifications.on_otn_alarm_event(
                m_count,
                m_otnAlarmEventData);
    }
}
