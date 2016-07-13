// MESSAGE TX1_TEST_TYPES PACKING

#define MAVLINK_MSG_ID_TX1_TEST_TYPES 220

MAVPACKED(
typedef struct __mavlink_tx1_test_types_t {
 float position[3]; /*< float_array*/
 uint32_t control_cmd[3]; /*< double_array*/
}) mavlink_tx1_test_types_t;

#define MAVLINK_MSG_ID_TX1_TEST_TYPES_LEN 24
#define MAVLINK_MSG_ID_TX1_TEST_TYPES_MIN_LEN 24
#define MAVLINK_MSG_ID_220_LEN 24
#define MAVLINK_MSG_ID_220_MIN_LEN 24

#define MAVLINK_MSG_ID_TX1_TEST_TYPES_CRC 157
#define MAVLINK_MSG_ID_220_CRC 157

#define MAVLINK_MSG_TX1_TEST_TYPES_FIELD_POSITION_LEN 3
#define MAVLINK_MSG_TX1_TEST_TYPES_FIELD_CONTROL_CMD_LEN 3

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_TX1_TEST_TYPES { \
	220, \
	"TX1_TEST_TYPES", \
	2, \
	{  { "position", NULL, MAVLINK_TYPE_FLOAT, 3, 0, offsetof(mavlink_tx1_test_types_t, position) }, \
         { "control_cmd", NULL, MAVLINK_TYPE_UINT32_T, 3, 12, offsetof(mavlink_tx1_test_types_t, control_cmd) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_TX1_TEST_TYPES { \
	"TX1_TEST_TYPES", \
	2, \
	{  { "position", NULL, MAVLINK_TYPE_FLOAT, 3, 0, offsetof(mavlink_tx1_test_types_t, position) }, \
         { "control_cmd", NULL, MAVLINK_TYPE_UINT32_T, 3, 12, offsetof(mavlink_tx1_test_types_t, control_cmd) }, \
         } \
}
#endif

/**
 * @brief Pack a tx1_test_types message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param position float_array
 * @param control_cmd double_array
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_tx1_test_types_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       const float *position, const uint32_t *control_cmd)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_TX1_TEST_TYPES_LEN];

	_mav_put_float_array(buf, 0, position, 3);
	_mav_put_uint32_t_array(buf, 12, control_cmd, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TX1_TEST_TYPES_LEN);
#else
	mavlink_tx1_test_types_t packet;

	mav_array_memcpy(packet.position, position, sizeof(float)*3);
	mav_array_memcpy(packet.control_cmd, control_cmd, sizeof(uint32_t)*3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TX1_TEST_TYPES_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_TX1_TEST_TYPES;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_TX1_TEST_TYPES_MIN_LEN, MAVLINK_MSG_ID_TX1_TEST_TYPES_LEN, MAVLINK_MSG_ID_TX1_TEST_TYPES_CRC);
}

/**
 * @brief Pack a tx1_test_types message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param position float_array
 * @param control_cmd double_array
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_tx1_test_types_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           const float *position,const uint32_t *control_cmd)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_TX1_TEST_TYPES_LEN];

	_mav_put_float_array(buf, 0, position, 3);
	_mav_put_uint32_t_array(buf, 12, control_cmd, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TX1_TEST_TYPES_LEN);
#else
	mavlink_tx1_test_types_t packet;

	mav_array_memcpy(packet.position, position, sizeof(float)*3);
	mav_array_memcpy(packet.control_cmd, control_cmd, sizeof(uint32_t)*3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TX1_TEST_TYPES_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_TX1_TEST_TYPES;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_TX1_TEST_TYPES_MIN_LEN, MAVLINK_MSG_ID_TX1_TEST_TYPES_LEN, MAVLINK_MSG_ID_TX1_TEST_TYPES_CRC);
}

/**
 * @brief Encode a tx1_test_types struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param tx1_test_types C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_tx1_test_types_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_tx1_test_types_t* tx1_test_types)
{
	return mavlink_msg_tx1_test_types_pack(system_id, component_id, msg, tx1_test_types->position, tx1_test_types->control_cmd);
}

/**
 * @brief Encode a tx1_test_types struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param tx1_test_types C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_tx1_test_types_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_tx1_test_types_t* tx1_test_types)
{
	return mavlink_msg_tx1_test_types_pack_chan(system_id, component_id, chan, msg, tx1_test_types->position, tx1_test_types->control_cmd);
}

/**
 * @brief Send a tx1_test_types message
 * @param chan MAVLink channel to send the message
 *
 * @param position float_array
 * @param control_cmd double_array
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_tx1_test_types_send(mavlink_channel_t chan, const float *position, const uint32_t *control_cmd)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_TX1_TEST_TYPES_LEN];

	_mav_put_float_array(buf, 0, position, 3);
	_mav_put_uint32_t_array(buf, 12, control_cmd, 3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TX1_TEST_TYPES, buf, MAVLINK_MSG_ID_TX1_TEST_TYPES_MIN_LEN, MAVLINK_MSG_ID_TX1_TEST_TYPES_LEN, MAVLINK_MSG_ID_TX1_TEST_TYPES_CRC);
#else
	mavlink_tx1_test_types_t packet;

	mav_array_memcpy(packet.position, position, sizeof(float)*3);
	mav_array_memcpy(packet.control_cmd, control_cmd, sizeof(uint32_t)*3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TX1_TEST_TYPES, (const char *)&packet, MAVLINK_MSG_ID_TX1_TEST_TYPES_MIN_LEN, MAVLINK_MSG_ID_TX1_TEST_TYPES_LEN, MAVLINK_MSG_ID_TX1_TEST_TYPES_CRC);
#endif
}

/**
 * @brief Send a tx1_test_types message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_tx1_test_types_send_struct(mavlink_channel_t chan, const mavlink_tx1_test_types_t* tx1_test_types)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_tx1_test_types_send(chan, tx1_test_types->position, tx1_test_types->control_cmd);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TX1_TEST_TYPES, (const char *)tx1_test_types, MAVLINK_MSG_ID_TX1_TEST_TYPES_MIN_LEN, MAVLINK_MSG_ID_TX1_TEST_TYPES_LEN, MAVLINK_MSG_ID_TX1_TEST_TYPES_CRC);
#endif
}

#if MAVLINK_MSG_ID_TX1_TEST_TYPES_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_tx1_test_types_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  const float *position, const uint32_t *control_cmd)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;

	_mav_put_float_array(buf, 0, position, 3);
	_mav_put_uint32_t_array(buf, 12, control_cmd, 3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TX1_TEST_TYPES, buf, MAVLINK_MSG_ID_TX1_TEST_TYPES_MIN_LEN, MAVLINK_MSG_ID_TX1_TEST_TYPES_LEN, MAVLINK_MSG_ID_TX1_TEST_TYPES_CRC);
#else
	mavlink_tx1_test_types_t *packet = (mavlink_tx1_test_types_t *)msgbuf;

	mav_array_memcpy(packet->position, position, sizeof(float)*3);
	mav_array_memcpy(packet->control_cmd, control_cmd, sizeof(uint32_t)*3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TX1_TEST_TYPES, (const char *)packet, MAVLINK_MSG_ID_TX1_TEST_TYPES_MIN_LEN, MAVLINK_MSG_ID_TX1_TEST_TYPES_LEN, MAVLINK_MSG_ID_TX1_TEST_TYPES_CRC);
#endif
}
#endif

#endif

// MESSAGE TX1_TEST_TYPES UNPACKING


/**
 * @brief Get field position from tx1_test_types message
 *
 * @return float_array
 */
static inline uint16_t mavlink_msg_tx1_test_types_get_position(const mavlink_message_t* msg, float *position)
{
	return _MAV_RETURN_float_array(msg, position, 3,  0);
}

/**
 * @brief Get field control_cmd from tx1_test_types message
 *
 * @return double_array
 */
static inline uint16_t mavlink_msg_tx1_test_types_get_control_cmd(const mavlink_message_t* msg, uint32_t *control_cmd)
{
	return _MAV_RETURN_uint32_t_array(msg, control_cmd, 3,  12);
}

/**
 * @brief Decode a tx1_test_types message into a struct
 *
 * @param msg The message to decode
 * @param tx1_test_types C-struct to decode the message contents into
 */
static inline void mavlink_msg_tx1_test_types_decode(const mavlink_message_t* msg, mavlink_tx1_test_types_t* tx1_test_types)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	mavlink_msg_tx1_test_types_get_position(msg, tx1_test_types->position);
	mavlink_msg_tx1_test_types_get_control_cmd(msg, tx1_test_types->control_cmd);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_TX1_TEST_TYPES_LEN? msg->len : MAVLINK_MSG_ID_TX1_TEST_TYPES_LEN;
        memset(tx1_test_types, 0, MAVLINK_MSG_ID_TX1_TEST_TYPES_LEN);
	memcpy(tx1_test_types, _MAV_PAYLOAD(msg), len);
#endif
}
