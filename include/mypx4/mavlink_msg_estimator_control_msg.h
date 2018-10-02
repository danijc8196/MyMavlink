#pragma once
// MESSAGE ESTIMATOR_CONTROL_MSG PACKING

#define MAVLINK_MSG_ID_ESTIMATOR_CONTROL_MSG 999

MAVPACKED(
typedef struct __mavlink_estimator_control_msg_t {
 uint8_t target_system; /*<  System ID*/
 uint8_t target_component; /*<  Component ID*/
 uint8_t command; /*<  Command*/
}) mavlink_estimator_control_msg_t;

#define MAVLINK_MSG_ID_ESTIMATOR_CONTROL_MSG_LEN 3
#define MAVLINK_MSG_ID_ESTIMATOR_CONTROL_MSG_MIN_LEN 3
#define MAVLINK_MSG_ID_999_LEN 3
#define MAVLINK_MSG_ID_999_MIN_LEN 3

#define MAVLINK_MSG_ID_ESTIMATOR_CONTROL_MSG_CRC 2
#define MAVLINK_MSG_ID_999_CRC 2



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_ESTIMATOR_CONTROL_MSG { \
    999, \
    "ESTIMATOR_CONTROL_MSG", \
    3, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_estimator_control_msg_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_estimator_control_msg_t, target_component) }, \
         { "command", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_estimator_control_msg_t, command) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_ESTIMATOR_CONTROL_MSG { \
    "ESTIMATOR_CONTROL_MSG", \
    3, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_estimator_control_msg_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_estimator_control_msg_t, target_component) }, \
         { "command", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_estimator_control_msg_t, command) }, \
         } \
}
#endif

/**
 * @brief Pack a estimator_control_msg message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system  System ID
 * @param target_component  Component ID
 * @param command  Command
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_estimator_control_msg_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t target_system, uint8_t target_component, uint8_t command)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ESTIMATOR_CONTROL_MSG_LEN];
    _mav_put_uint8_t(buf, 0, target_system);
    _mav_put_uint8_t(buf, 1, target_component);
    _mav_put_uint8_t(buf, 2, command);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ESTIMATOR_CONTROL_MSG_LEN);
#else
    mavlink_estimator_control_msg_t packet;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.command = command;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ESTIMATOR_CONTROL_MSG_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ESTIMATOR_CONTROL_MSG;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_ESTIMATOR_CONTROL_MSG_MIN_LEN, MAVLINK_MSG_ID_ESTIMATOR_CONTROL_MSG_LEN, MAVLINK_MSG_ID_ESTIMATOR_CONTROL_MSG_CRC);
}

/**
 * @brief Pack a estimator_control_msg message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system  System ID
 * @param target_component  Component ID
 * @param command  Command
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_estimator_control_msg_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t target_system,uint8_t target_component,uint8_t command)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ESTIMATOR_CONTROL_MSG_LEN];
    _mav_put_uint8_t(buf, 0, target_system);
    _mav_put_uint8_t(buf, 1, target_component);
    _mav_put_uint8_t(buf, 2, command);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ESTIMATOR_CONTROL_MSG_LEN);
#else
    mavlink_estimator_control_msg_t packet;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.command = command;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ESTIMATOR_CONTROL_MSG_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ESTIMATOR_CONTROL_MSG;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_ESTIMATOR_CONTROL_MSG_MIN_LEN, MAVLINK_MSG_ID_ESTIMATOR_CONTROL_MSG_LEN, MAVLINK_MSG_ID_ESTIMATOR_CONTROL_MSG_CRC);
}

/**
 * @brief Encode a estimator_control_msg struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param estimator_control_msg C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_estimator_control_msg_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_estimator_control_msg_t* estimator_control_msg)
{
    return mavlink_msg_estimator_control_msg_pack(system_id, component_id, msg, estimator_control_msg->target_system, estimator_control_msg->target_component, estimator_control_msg->command);
}

/**
 * @brief Encode a estimator_control_msg struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param estimator_control_msg C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_estimator_control_msg_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_estimator_control_msg_t* estimator_control_msg)
{
    return mavlink_msg_estimator_control_msg_pack_chan(system_id, component_id, chan, msg, estimator_control_msg->target_system, estimator_control_msg->target_component, estimator_control_msg->command);
}

/**
 * @brief Send a estimator_control_msg message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system  System ID
 * @param target_component  Component ID
 * @param command  Command
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_estimator_control_msg_send(mavlink_channel_t chan, uint8_t target_system, uint8_t target_component, uint8_t command)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ESTIMATOR_CONTROL_MSG_LEN];
    _mav_put_uint8_t(buf, 0, target_system);
    _mav_put_uint8_t(buf, 1, target_component);
    _mav_put_uint8_t(buf, 2, command);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ESTIMATOR_CONTROL_MSG, buf, MAVLINK_MSG_ID_ESTIMATOR_CONTROL_MSG_MIN_LEN, MAVLINK_MSG_ID_ESTIMATOR_CONTROL_MSG_LEN, MAVLINK_MSG_ID_ESTIMATOR_CONTROL_MSG_CRC);
#else
    mavlink_estimator_control_msg_t packet;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.command = command;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ESTIMATOR_CONTROL_MSG, (const char *)&packet, MAVLINK_MSG_ID_ESTIMATOR_CONTROL_MSG_MIN_LEN, MAVLINK_MSG_ID_ESTIMATOR_CONTROL_MSG_LEN, MAVLINK_MSG_ID_ESTIMATOR_CONTROL_MSG_CRC);
#endif
}

/**
 * @brief Send a estimator_control_msg message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_estimator_control_msg_send_struct(mavlink_channel_t chan, const mavlink_estimator_control_msg_t* estimator_control_msg)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_estimator_control_msg_send(chan, estimator_control_msg->target_system, estimator_control_msg->target_component, estimator_control_msg->command);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ESTIMATOR_CONTROL_MSG, (const char *)estimator_control_msg, MAVLINK_MSG_ID_ESTIMATOR_CONTROL_MSG_MIN_LEN, MAVLINK_MSG_ID_ESTIMATOR_CONTROL_MSG_LEN, MAVLINK_MSG_ID_ESTIMATOR_CONTROL_MSG_CRC);
#endif
}

#if MAVLINK_MSG_ID_ESTIMATOR_CONTROL_MSG_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_estimator_control_msg_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t target_system, uint8_t target_component, uint8_t command)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, target_system);
    _mav_put_uint8_t(buf, 1, target_component);
    _mav_put_uint8_t(buf, 2, command);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ESTIMATOR_CONTROL_MSG, buf, MAVLINK_MSG_ID_ESTIMATOR_CONTROL_MSG_MIN_LEN, MAVLINK_MSG_ID_ESTIMATOR_CONTROL_MSG_LEN, MAVLINK_MSG_ID_ESTIMATOR_CONTROL_MSG_CRC);
#else
    mavlink_estimator_control_msg_t *packet = (mavlink_estimator_control_msg_t *)msgbuf;
    packet->target_system = target_system;
    packet->target_component = target_component;
    packet->command = command;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ESTIMATOR_CONTROL_MSG, (const char *)packet, MAVLINK_MSG_ID_ESTIMATOR_CONTROL_MSG_MIN_LEN, MAVLINK_MSG_ID_ESTIMATOR_CONTROL_MSG_LEN, MAVLINK_MSG_ID_ESTIMATOR_CONTROL_MSG_CRC);
#endif
}
#endif

#endif

// MESSAGE ESTIMATOR_CONTROL_MSG UNPACKING


/**
 * @brief Get field target_system from estimator_control_msg message
 *
 * @return  System ID
 */
static inline uint8_t mavlink_msg_estimator_control_msg_get_target_system(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field target_component from estimator_control_msg message
 *
 * @return  Component ID
 */
static inline uint8_t mavlink_msg_estimator_control_msg_get_target_component(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field command from estimator_control_msg message
 *
 * @return  Command
 */
static inline uint8_t mavlink_msg_estimator_control_msg_get_command(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Decode a estimator_control_msg message into a struct
 *
 * @param msg The message to decode
 * @param estimator_control_msg C-struct to decode the message contents into
 */
static inline void mavlink_msg_estimator_control_msg_decode(const mavlink_message_t* msg, mavlink_estimator_control_msg_t* estimator_control_msg)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    estimator_control_msg->target_system = mavlink_msg_estimator_control_msg_get_target_system(msg);
    estimator_control_msg->target_component = mavlink_msg_estimator_control_msg_get_target_component(msg);
    estimator_control_msg->command = mavlink_msg_estimator_control_msg_get_command(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_ESTIMATOR_CONTROL_MSG_LEN? msg->len : MAVLINK_MSG_ID_ESTIMATOR_CONTROL_MSG_LEN;
        memset(estimator_control_msg, 0, MAVLINK_MSG_ID_ESTIMATOR_CONTROL_MSG_LEN);
    memcpy(estimator_control_msg, _MAV_PAYLOAD(msg), len);
#endif
}
