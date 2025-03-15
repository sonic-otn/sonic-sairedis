#include "FlexCounterOtn.h"
#include "FlexCounter.h"

using namespace syncd;
using namespace std;


const std::string FlexCounterOtn::COUNTER_TYPE_OTN_ATTENUATOR_ATTR = "OTN Attenuator Attributes Counter";
const std::string FlexCounterOtn::COUNTER_TYPE_OTN_OA_ATTR = "OTN OA Attributes Counter";
const std::string FlexCounterOtn::COUNTER_TYPE_OTN_OCM_CHANNEL_ATTR = "OTN OCM Channel Attributes Counter";
const std::string FlexCounterOtn::COUNTER_TYPE_OTN_OSC_ATTR = "OTN OSC Attributes Counter";


FlexCounterOtn::FlexCounterOtn(
        std::function<std::shared_ptr<BaseCounterContext>(_In_ const std::string &name)> getCounterContext,
        std::function<bool(_In_ const std::string &name)> hasCounterContext):
m_getCounterContext(getCounterContext),
m_hasCounterContext(hasCounterContext)
{
    SWSS_LOG_ENTER();
}

FlexCounterOtn::~FlexCounterOtn()
{
    SWSS_LOG_ENTER();
}

bool FlexCounterOtn::addCounter(
        _In_ sai_object_id_t vid,
        _In_ sai_object_id_t rid,
        _In_ sai_object_type_t objectType,
        _In_ const std::string &field,
        _In_ const std::vector<std::string> &idStrings)
{
    SWSS_LOG_ENTER();

    sai_object_type_extensions_t extObjectType = (sai_object_type_extensions_t)objectType;
    if (extObjectType == SAI_OBJECT_TYPE_OTN_ATTENUATOR && field == OTN_ATTENUATOR_ATTR_ID_LIST)
    {
        m_getCounterContext(COUNTER_TYPE_OTN_ATTENUATOR_ATTR)->addObject(
                vid,
                rid,
                idStrings,
                "");
        return true;
    }

    if (extObjectType == SAI_OBJECT_TYPE_OTN_OA && field == OTN_OA_ATTR_ID_LIST)
    {
        m_getCounterContext(COUNTER_TYPE_OTN_OA_ATTR)->addObject(
                vid,
                rid,
                idStrings,
                "");
        return true;
    }

    if (extObjectType == SAI_OBJECT_TYPE_OTN_OCM_CHANNEL && field == OTN_OCM_CHANNEL_ATTR_ID_LIST)
    {
        m_getCounterContext(COUNTER_TYPE_OTN_OCM_CHANNEL_ATTR)->addObject(
                vid,
                rid,
                idStrings,
                "");
        return true;
    }

    if (extObjectType == SAI_OBJECT_TYPE_OTN_OSC && field == OTN_OSC_ATTR_ID_LIST)
    {
        m_getCounterContext(COUNTER_TYPE_OTN_OSC_ATTR)->addObject(
                vid,
                rid,
                idStrings,
                "");
        return true;
    }

    return false;
}

bool FlexCounterOtn::removeCounter(
        _In_ sai_object_id_t vid,
        _In_ sai_object_type_t objectType)
{
    SWSS_LOG_ENTER();

    sai_object_type_extensions_t extObjectType = (sai_object_type_extensions_t)objectType;
    if (extObjectType == SAI_OBJECT_TYPE_OTN_ATTENUATOR)
    {
        if (m_hasCounterContext(COUNTER_TYPE_OTN_ATTENUATOR_ATTR))
        {
            m_getCounterContext(COUNTER_TYPE_OTN_ATTENUATOR_ATTR)->removeObject(vid);
        }
        return true;
    }

    if (extObjectType == SAI_OBJECT_TYPE_OTN_OA)
    {
        if (m_hasCounterContext(COUNTER_TYPE_OTN_OA_ATTR))
        {
            m_getCounterContext(COUNTER_TYPE_OTN_OA_ATTR)->removeObject(vid);
        }
        return true;
    }

    if (extObjectType == SAI_OBJECT_TYPE_OTN_OCM_CHANNEL)
    {
        if (m_hasCounterContext(COUNTER_TYPE_OTN_OCM_CHANNEL_ATTR))
        {
            m_getCounterContext(COUNTER_TYPE_OTN_OCM_CHANNEL_ATTR)->removeObject(vid);
        }
        return true;
    }

    if (extObjectType == SAI_OBJECT_TYPE_OTN_OSC)
    {
        if (m_hasCounterContext(COUNTER_TYPE_OTN_OSC_ATTR))
        {
            m_getCounterContext(COUNTER_TYPE_OTN_OSC_ATTR)->removeObject(vid);
        }
        return true;
    }

    return false;
}

bool FlexCounterOtn::addCounterPlugin(
        _In_ const std::string &field,
        _In_ const std::vector<std::string> &shaStrings)
{
    SWSS_LOG_ENTER();

    if (field == OTN_ATTENUATOR_PLUGIN_FIELD)
    {
        m_getCounterContext(COUNTER_TYPE_OTN_ATTENUATOR_ATTR)->addPlugins(shaStrings);
        return true;
    }

    if (field == OTN_OA_PLUGIN_FIELD)
    {
        m_getCounterContext(COUNTER_TYPE_OTN_OA_ATTR)->addPlugins(shaStrings);
        return true;
    }

    if (field == OTN_OCM_CHANNEL_PLUGIN_FIELD)
    {
        m_getCounterContext(COUNTER_TYPE_OTN_OCM_CHANNEL_ATTR)->addPlugins(shaStrings);
        return true;
    }

    if (field == OTN_OSC_PLUGIN_FIELD)
    {
        m_getCounterContext(COUNTER_TYPE_OTN_OSC_ATTR)->addPlugins(shaStrings);
        return true;
    }

    return false;
}
