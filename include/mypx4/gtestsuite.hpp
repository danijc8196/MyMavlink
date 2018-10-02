/** @file
 *	@brief MAVLink comm testsuite protocol generated from mypx4.xml
 *	@see http://mavlink.org
 */

#pragma once

#include <gtest/gtest.h>
#include "mypx4.hpp"

#ifdef TEST_INTEROP
using namespace mavlink;
#undef MAVLINK_HELPER
#include "mavlink.h"
#endif


TEST(mypx4, ESTIMATOR_CONTROL_MSG)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::mypx4::msg::ESTIMATOR_CONTROL_MSG packet_in{};
    packet_in.target_system = 5;
    packet_in.target_component = 72;
    packet_in.command = 139;

    mavlink::mypx4::msg::ESTIMATOR_CONTROL_MSG packet1{};
    mavlink::mypx4::msg::ESTIMATOR_CONTROL_MSG packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.target_system, packet2.target_system);
    EXPECT_EQ(packet1.target_component, packet2.target_component);
    EXPECT_EQ(packet1.command, packet2.command);
}

#ifdef TEST_INTEROP
TEST(mypx4_interop, ESTIMATOR_CONTROL_MSG)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_estimator_control_msg_t packet_c {
         5, 72, 139
    };

    mavlink::mypx4::msg::ESTIMATOR_CONTROL_MSG packet_in{};
    packet_in.target_system = 5;
    packet_in.target_component = 72;
    packet_in.command = 139;

    mavlink::mypx4::msg::ESTIMATOR_CONTROL_MSG packet2{};

    mavlink_msg_estimator_control_msg_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.target_system, packet2.target_system);
    EXPECT_EQ(packet_in.target_component, packet2.target_component);
    EXPECT_EQ(packet_in.command, packet2.command);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif
