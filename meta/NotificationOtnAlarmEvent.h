#pragma once

#include "Notification.h"

namespace sairedis
{
    class NotificationOtnAlarmEvent:
        public Notification
    {
        public:

            NotificationOtnAlarmEvent(
                    _In_ const std::string& serializedNotification);

            virtual ~NotificationOtnAlarmEvent();

        public:

            virtual sai_object_id_t getSwitchId() const override;

            virtual sai_object_id_t getAnyObjectId() const override;

            virtual void processMetadata(
                    _In_ std::shared_ptr<saimeta::Meta> meta) const override;

            virtual void executeCallback(
                    _In_ const sai_switch_notifications_t& switchNotifications) const override;

        private:

            uint32_t m_count;

            sai_otn_alarm_event_data_t* m_otnAlarmEventData;
    };
}
