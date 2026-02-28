#include "MetaTestSaiInterface.h"
#include "NotificationOtnAlarmEvent.h"

#include "sairediscommon.h"
#include "sai_serialize.h"

#include <gtest/gtest.h>

#include <memory>

using namespace sairedis;
using namespace saimeta;

static std::string s = "["
                         "{"
                           "\"timestamp\":\"{"
                                   "\\\"tv_nsec\\\":\\\"28715881\\\","
                                   "\\\"tv_sec\\\":\\\"1700042919\\\""
                           "}\","
                           "\"object_id\":\"oid:0x123456789abcdef\","
                           "\"event_name\": \"OTN OA LOS\","
                           "\"severity\": \"SAI_OTN_ALARM_SEVERITY_CRITICAL\","
                           "\"action\": \"SAI_OTN_ALARM_ACTION_RAISE\","
                           "\"description\": \"OA input LOS, power -60dBm\","
                           "\"data\": \"0\""
                         "}"
                       "]";

static std::string null = "["
                           "{"
                             "\"timestamp\":\"{"
                                   "\\\"tv_nsec\\\":\\\"28715881\\\","
                                   "\\\"tv_sec\\\":\\\"1700042919\\\""
                             "}\","
                             "\"object_id\":\"oid:0x0\","
                             "\"event_name\": \"OTN OA LOS\","
                             "\"severity\": \"SAI_OTN_ALARM_SEVERITY_CRITICAL\","
                             "\"action\": \"SAI_OTN_ALARM_ACTION_RAISE\","
                             "\"description\": \"OA input LOS, power -60dBm\","
                             "\"data\": \"0\""
                           "}"
                         "]";

static std::string fullnull = "[]";

TEST(NotificationOtnAlarmEvent, otn_alarm)
{
    NotificationOtnAlarmEvent n(s);
}

TEST(NotificationOtnAlarmEvent, getSwitchId)
{
    NotificationOtnAlarmEvent n(s);

    EXPECT_EQ(n.getSwitchId(), SAI_NULL_OBJECT_ID);

    NotificationOtnAlarmEvent n2(null);

    EXPECT_EQ(n2.getSwitchId(), SAI_NULL_OBJECT_ID);

    NotificationOtnAlarmEvent n3(fullnull);

    EXPECT_EQ(n3.getSwitchId(), SAI_NULL_OBJECT_ID);
}

TEST(NotificationOtnAlarmEvent, getAnyObjectId)
{
    NotificationOtnAlarmEvent n(s);

    EXPECT_EQ(n.getAnyObjectId(), 0x123456789abcdef);

    NotificationOtnAlarmEvent n2(null);

    EXPECT_EQ(n2.getAnyObjectId(), SAI_NULL_OBJECT_ID);

    NotificationOtnAlarmEvent n3(fullnull);

    EXPECT_EQ(n3.getAnyObjectId(), SAI_NULL_OBJECT_ID);
}

TEST(NotificationOtnAlarmEvent, processMetadata)
{
    NotificationOtnAlarmEvent n(s);

    auto sai = std::make_shared<MetaTestSaiInterface>();
    auto meta = std::make_shared<Meta>(sai);

    n.processMetadata(meta);
}

static void on_otn_alarm_event(
        _In_ uint32_t count,
        _In_ const sai_otn_alarm_event_data_t *data)
{
    SWSS_LOG_ENTER();

    SWSS_LOG_NOTICE("received: on_otn_alarm_event");
}

TEST(NotificationOtnAlarmEvent, executeCallback)
{
    NotificationOtnAlarmEvent n(s);

    sai_switch_notifications_t switchNotifications;
    memset(&switchNotifications, 0, sizeof(switchNotifications));

    switchNotifications.on_otn_alarm_event = &on_otn_alarm_event;

    n.executeCallback(switchNotifications);
}
