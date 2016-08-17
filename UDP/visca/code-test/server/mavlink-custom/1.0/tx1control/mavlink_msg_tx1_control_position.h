// MESSAGE TX1_CONTROL_POSITION PACKING

#define MAVLINK_MSG_ID_TX1_CONTROL_POSITION 222

MAVPACKED(
typedef struct __mavlink_tx1_control_position_t {
 uint16_t top_left_x; /*< the value of top left positon x*/
 uint16_t top_left_y; /*< the value of top left positon y*/
 uint16_t bottom_right_x; /*< the value of bottom right positon x*/
 uint16_t bottom_left_y; /*< the value of bottom left position y*/
}) mavlink_tx1_control_position_t;

#define MAVLINK_MSG_ID_TX1_CONTROL_POSITION_LEN 8
#define MAVLINK_MSG_ID_TX1_CONTROL_POSITION_MIN_LEN 8
#define MAVLINK_MSG_ID_222_LEN 8
#define MAVLINK_MSG_ID_222_MIN_LEN 8

#define MAVLINK_MSG_ID_TX1_CONTROL_POSITION_CRC 124
#define MAVLINK_MSG_ID_222_CRC 124



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_TX1_CONTROL_POSITION { \
	222, \
	"TX1_CONTROL_POSITION", \
	4, \
	{  { "top_left_x", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_tx1_control_position_t, top_left_x) }, \
         { "top_left_y", NULL, MAVLINK_TYPE_UINT16_T, 0, 2, offsetof(mavlink_tx1_control_position_t, top_left_y) }, \
         { "bottom_right_x", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_tx1_control_position_t, bottom_right_x) }, \
         { "bottom_left_y", NULL, MAVLINK_TYPE_UINT16_T, 0, 6, offsetof(mavlink_tx1_control_position_t, bottom_left_y) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_TX1_CONTROL_POSITION { \
	"TX1_CONTROL_POSITION", \
	4, \
	{  { "top_left_x", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_tx1_control_position_t, top_left_x) }, \
         { "top_left_y", NULL, MAVLINK_TYPE_UINT16_T, 0, 2, offsetof(mavlink_tx1_control_position_t, top_left_y) }, \
         { "bottom_right_x", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_tx1_control_position_t, bottom_right_x) }, \
         { "bottom_left_y", NULL, MAVLINK_TYPE_UINT16_T, 0, 6, offsetof(mavlink_tx1_control_position_t, bottom_left_y) }, \
         } \
}
#endif

/**
 * @brief Pack a tx1_control_position message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param top_left_x the value of top left positon x
 * @param top_left_y the value of top left positon y
 * @param bottom_right_x the value of bottom right positon x
 * @param bottom_left_y the value of bottom left position y
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_tx1_control_position_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint16_t top_left_x, uint16_t top_left_y, uint16_t bottom_right_x, uint16_t bottom_left_y)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_TX1_CONTROL_POSITION_LEN];
	_mav_put_uint16_t(buf, 0, top_left_x);
	_mav_put_uint16_t(buf, 2, top_left_y);
	_mav_put_uint16_t(buf, 4, bottom_right_x);
	_mav_put_uint16_t(buf, 6, bottom_left_y);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TX1_CONTROL_POSITION_LEN);
#else
	mavlink_tx1_control_position_t packet;
	packet.top_left_x = top_left_x;
	packet.top_left_y = top_left_y;
	packet.bottom_right_x = bottom_right_x;
	packet.bottom_left_y = bottom_left_y;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TX1_CONTROL_POSITION_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_TX1_CONTROL_POSITION;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_TX1_CONTROL_POSITION_MIN_LEN, MAVLINK_MSG_ID_TX1_CONTROL_POSITION_LEN, MAVLINK_MSG_ID_TX1_CONTROL_POSITION_CRC);
}

/**
 * @brief Pack a tx1_control_position message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param top_left_x the value of top left positon x
 * @param top_left_y the value of top left positon y
 * @param bottom_right_x the value of bottom right positon x
 * @param bottom_left_y the value of bottom left position y
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_tx1_control_position_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint16_t top_left_x,uint16_t top_left_y,uint16_t bottom_right_x,uint16_t bottom_left_y)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_TX1_CONTROL_POSITION_LEN];
	_mav_put_uint16_t(buf, 0, top_left_x);
	_mav_put_uint16_t(buf, 2, top_left_y);
	_mav_put_uint16_t(buf, 4, bottom_right_x);
	_mav_put_uint16_t(buf, 6, bottom_left_y);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TX1_CONTROL_POSITION_LEN);
#else
	mavlink_tx1_control_position_t packet;
	packet.top_left_x = top_left_x;
	packet.top_left_y = top_left_y;
	packet.bottom_right_x = bottom_right_x;
	packet.bottom_left_y = bottom_left_y;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TX1_CONTROL_POSITION_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_TX1_CONTROL_POSITION;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_TX1_CONTROL_POSITION_MIN_LEN, MAVLINK_MSG_ID_TX1_CONTROL_POSITION_LEN, MAVLINK_MSG_ID_TX1_CONTROL_POSITION_CRC);
}

/**
 * @brief Encode a tx1_control_position struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param tx1_control_position C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_tx1_control_position_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_tx1_control_position_t* tx1_control_position)
{
	return mavlink_msg_tx1_control_position_pack(system_id, component_id, msg, tx1_control_position->top_left_x, tx1_control_position->top_left_y, tx1_control_position->bottom_right_x, tx1_control_position->bottom_left_y);
}

/**
 * @brief Encode a tx1_control_position struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param tx1_control_position C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_tx1_control_position_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_tx1_control_position_t* tx1_control_position)
{
	return mavlink_msg_tx1_control_position_pack_chan(system_id, component_id, chan, msg, tx1_control_position->top_left_x, tx1_control_position->top_left_y, tx1_control_position->bottom_right_x, tx1_control_position->bottom_left_y);
}

/**
 * @brief Send a tx1_control_position message
 * @param chan MAVLink channel to send the message
 *
 * @param top_left_x the value of top left positon x
 * @param top_left_y the value of top left positon y
 * @param bottom_right_x the value of bottom right positon x
 * @param bottom_left_y the value of bottom left position y
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_tx1_control_position_send(mavlink_channel_t chan, uint16_t top_left_x, uint16_t top_left_y, uint16_t bottom_right_x, uint16_t bottom_left_y)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_TX1_CONTROL_POSITION_LEN];
	_mav_put_uint16_t(buf, 0, top_left_x);
	_mav_put_uint16_t(buf, 2, top_left_y);
	_mav_put_uint16_t(buf, 4, bottom_right_x);
	_mav_put_uint16_t(buf, 6, bottom_left_y);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TX1_CONTROL_POSITION, buf, MAVLINK_MSG_ID_TX1_CONTROL_POSITION_MIN_LEN, MAVLINK_MSG_ID_TX1_CONTROL_POSITION_LEN, MAVLINK_MSG_ID_TX1_CONTROL_POSITION_CRC);
#else
	mavlink_tx1_control_position_t packet;
	packet.top_left_x = top_left_x;
	packet.top_left_y = top_left_y;
	packet.bottom_right_x = bottom_right_x;
	packet.bottom_left_y = bottom_left_y;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TX1_CONTROL_POSITION, (const char *)&packet, MAVLINK_MSG_ID_TX1_CONTROL_POSITION_MIN_LEN, MAVLINK_MSG_ID_TX1_CONTROL_POSITION_LEN, MAVLINK_MSG_ID_TX1_CONTROL_POSITION_CRC);
#endif
}

/**
 * @brief Send a tx1_control_position message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_tx1_control_position_send_struct(mavlink_channel_t chan, const mavlink_tx1_control_position_t* tx1_control_position)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_tx1_control_position_send(chan, tx1_control_position->top_left_x, tx1_control_position->top_left_y, tx1_control_position->bottom_right_x, tx1_control_position->bottom_left_y);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TX1_CONTROL_POSITION, (const char *)tx1_control_position, MAVLINK_MSG_ID_TX1_CONTROL_POSITION_MIN_LEN, MAVLINK_MSG_ID_TX1_CONTROL_POSITION_LEN, MAVLINK_MSG_ID_TX1_CONTROL_POSITION_CRC);
#endif
}

#if MAVLINK_MSG_ID_TX1_CONTROL_POSITION_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_tx1_control_position_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint16_t top_left_x, uint16_t top_left_y, uint16_t bottom_right_x, uint16_t bottom_left_y)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint16_t(buf, 0, top_left_x);
	_mav_put_uint16_t(buf, 2, top_left_y);
	_mav_put_uint16_t(buf, 4, bottom_right_x);
	_mav_put_uint16_t(buf, 6, bottom_left_y);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TX1_CONTROL_POSITION, buf, MAVLINK_MSG_ID_TX1_CONTROL_POSITION_MIN_LEN, MAVLINK_MSG_ID_TX1_CONTROL_POSITION_LEN, MAVLINK_MSG_ID_TX1_CONTROL_POSITION_CRC);
#else
	mavlink_tx1_control_position_t *packet = (mavlink_tx1_control_position_t *)msgbuf;
	packet->top_left_x = top_left_x;
	packet->top_left_y = top_left_y;
	packet->bottom_right_x = bottom_right_x;
	packet->bottom_left_y = bottom_left_y;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TX1_CONTROL_POSITION, (const char *)packet, MAVLINK_MSG_ID_TX1_CONTROL_POSITION_MIN_LEN, MAVLINK_MSG_ID_TX1_CONTROL_POSITION_LEN, MAVLINK_MSG_ID_TX1_CONTROL_POSITION_CRC);
#endif
}
#endif

#endif

// MESSAGE TX1_CONTROL_POSITION UNPACKING


/**
 * @brief Get field top_left_x from tx1_control_position message
 *
 * @return the value of top left positon x
 */
static inline uint16_t mavlink_msg_tx1_control_position_get_top_left_x(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Get field top_left_y from tx1_control_position message
 *
 * @return the value of top left positon y
 */
static inline uint16_t mavlink_msg_tx1_control_position_get_top_left_y(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  2);
}

/**
 * @brief Get field bottom_right_x from tx1_control_position message
 *
 * @return the value of bottom right positon x
 */
static inline uint16_t mavlink_msg_tx1_control_position_get_bottom_right_x(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  4);
}

/**
 * @brief Get field bottom_left_y from tx1_control_position message
 *
 * @return the value of bottom left position y
 */
static inline uint16_t mavlink_msg_tx1_control_position_get_bottom_left_y(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  6);
}

/**
 * @brief Decode a tx1_control_position message into a struct
 *
 * @param msg The message to decode
 * @param tx1_control_position C-struct to decode the message contents into
 */
static inline void mavlink_msg_tx1_control_position_decode(const mavlink_message_t* msg, mavlink_tx1_control_position_t* tx1_control_position)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	tx1_control_position->top_left_x = mavlink_msg_tx1_control_position_get_top_left_x(msg);
	tx1_control_position->top_left_y = mavlink_msg_tx1_control_position_get_top_left_y(msg);
	tx1_control_position->bottom_right_x = mavlink_msg_tx1_control_position_get_bottom_right_x(msg);
	tx1_control_position->bottom_left_y = mavlink_msg_tx1_control_position_get_bottom_left_y(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_TX1_CONTROL_POSITION_LEN? msg->len : MAVLINK_MSG_ID_TX1_CONTROL_POSITION_LEN;
        memset(tx1_control_position, 0, MAVLINK_MSG_ID_TX1_CONTROL_POSITION_LEN);
	memcpy(tx1_control_position, _MAV_PAYLOAD(msg), len);
#endif
}
