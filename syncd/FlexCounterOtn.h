#pragma once

extern "C" {
#include "sai.h"
}

#include "meta/SaiInterface.h"
#include "meta/sai_serialize_otn.h"

#include <functional>
#include <memory>
#include <vector>

namespace syncd
{
    class BaseCounterContext;

    class FlexCounterOtn
    {
    public:
        FlexCounterOtn(
                std::function<std::shared_ptr<BaseCounterContext>(_In_ const std::string &name)> getCounterContext,
                std::function<bool(_In_ const std::string &name)> hasCounterContext);
        virtual ~FlexCounterOtn();

        bool addCounter(
                _In_ sai_object_id_t vid,
                _In_ sai_object_id_t rid,
                _In_ sai_object_type_t objectType,
                _In_ const std::string &field,
                _In_ const std::vector<std::string> &idStrings);

        bool removeCounter(
                _In_ sai_object_id_t vid,
                _In_ sai_object_type_t objectType);

        bool addCounterPlugin(
                _In_ const std::string &field,
                _In_ const std::vector<std::string> &shaStrings);

    public:
        static const std::string COUNTER_TYPE_OTN_ATTENUATOR_ATTR;
        static const std::string COUNTER_TYPE_OTN_OA_ATTR;
        static const std::string COUNTER_TYPE_OTN_OCM_CHANNEL_ATTR;
        static const std::string COUNTER_TYPE_OTN_OSC_ATTR;

    private:
        std::function<std::shared_ptr<BaseCounterContext>(_In_ const std::string &name)> m_getCounterContext;
        std::function<bool(_In_ const std::string &name)> m_hasCounterContext;
    };


    #define FLEX_COUNTER_OTN_IMPLEMENT()                            \
    std::shared_ptr<BaseCounterContext> createOtnCounterContext(    \
            _In_ const std::string &context_name,                   \
            _In_ const std::string &instance,                      \
            _In_ std::shared_ptr<sairedis::SaiInterface> vendorSai, \
            _In_ sai_stats_mode_t &statsMode)                       \
    {                                                               \
        SWSS_LOG_ENTER();                                           \
        if (context_name == FlexCounterOtn::COUNTER_TYPE_OTN_ATTENUATOR_ATTR)\
        {                                                           \
            return std::make_shared<AttrContext<sai_otn_attenuator_attr_t>>(context_name, instance, (sai_object_type_t)SAI_OBJECT_TYPE_OTN_ATTENUATOR, vendorSai.get(), statsMode);\
        }                                                           \
                                                                    \
        if (context_name == FlexCounterOtn::COUNTER_TYPE_OTN_OA_ATTR)\
        {                                                           \
            return std::make_shared<AttrContext<sai_otn_oa_attr_t>>(context_name, instance, (sai_object_type_t)SAI_OBJECT_TYPE_OTN_OA, vendorSai.get(), statsMode);\
        }                                                           \
                                                                    \
        if (context_name == FlexCounterOtn::COUNTER_TYPE_OTN_OCM_CHANNEL_ATTR)\
        {                                                           \
            return std::make_shared<AttrContext<sai_otn_ocm_channel_attr_t>>(context_name, instance, (sai_object_type_t)SAI_OBJECT_TYPE_OTN_OCM_CHANNEL, vendorSai.get(), statsMode);\
        }                                                           \
                                                                    \
        if (context_name == FlexCounterOtn::COUNTER_TYPE_OTN_OSC_ATTR)\
        {                                                           \
            return std::make_shared<AttrContext<sai_otn_osc_attr_t>>(context_name, instance, (sai_object_type_t)SAI_OBJECT_TYPE_OTN_OSC, vendorSai.get(), statsMode);\
        }                                                           \
                                                                    \
        return nullptr;                                             \
    }                                                               \
                                                                    \
    template <>                                                     \
    void deserializeAttr(                                           \
            _In_ const std::string &name,                           \
            _Out_ sai_otn_attenuator_attr_t &attr)                  \
    {                                                               \
        SWSS_LOG_ENTER();                                           \
        sai_deserialize_otn_attenuator_attr(name, attr);            \
    }                                                               \
                                                                    \
    template <>                                                     \
    void deserializeAttr(                                           \
            _In_ const std::string &name,                           \
            _Out_ sai_otn_oa_attr_t &attr)                          \
    {                                                               \
        SWSS_LOG_ENTER();                                           \
        sai_deserialize_otn_oa_attr(name, attr);                    \
    }                                                               \
                                                                    \
    template <>                                                     \
    void deserializeAttr(                                           \
            _In_ const std::string &name,                           \
            _Out_ sai_otn_ocm_channel_attr_t &attr)                 \
    {                                                               \
        SWSS_LOG_ENTER();                                           \
        sai_deserialize_otn_ocm_channel_attr(name, attr);           \
    }                                                               \
                                                                    \
    template <>                                                     \
    void deserializeAttr(                                           \
            _In_ const std::string &name,                           \
            _Out_ sai_otn_osc_attr_t &attr)                         \
    {                                                               \
        SWSS_LOG_ENTER();                                           \
        sai_deserialize_otn_osc_attr(name, attr);                   \
    }

}
