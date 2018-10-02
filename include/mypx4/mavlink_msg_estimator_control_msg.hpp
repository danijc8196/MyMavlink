// MESSAGE ESTIMATOR_CONTROL_MSG support class

#pragma once

namespace mavlink {
namespace mypx4 {
namespace msg {

/**
 * @brief ESTIMATOR_CONTROL_MSG message
 *
 * Control commands for the PX4 estimator module
 */
struct ESTIMATOR_CONTROL_MSG : mavlink::Message {
    static constexpr msgid_t MSG_ID = 999;
    static constexpr size_t LENGTH = 3;
    static constexpr size_t MIN_LENGTH = 3;
    static constexpr uint8_t CRC_EXTRA = 2;
    static constexpr auto NAME = "ESTIMATOR_CONTROL_MSG";


    uint8_t target_system; /*<  System ID */
    uint8_t target_component; /*<  Component ID */
    uint8_t command; /*<  Command */


    inline std::string get_name(void) const override
    {
            return NAME;
    }

    inline Info get_message_info(void) const override
    {
            return { MSG_ID, LENGTH, MIN_LENGTH, CRC_EXTRA };
    }

    inline std::string to_yaml(void) const override
    {
        std::stringstream ss;

        ss << NAME << ":" << std::endl;
        ss << "  target_system: " << +target_system << std::endl;
        ss << "  target_component: " << +target_component << std::endl;
        ss << "  command: " << +command << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << target_system;                 // offset: 0
        map << target_component;              // offset: 1
        map << command;                       // offset: 2
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> target_system;                 // offset: 0
        map >> target_component;              // offset: 1
        map >> command;                       // offset: 2
    }
};

} // namespace msg
} // namespace mypx4
} // namespace mavlink
