// MESSAGE TX1_CONTROL_STREAM PACKING

#define MAVLINK_MSG_ID_TX1_CONTROL_STREAM 220

MAVPACKED(
typedef struct __mavlink_tx1_control_stream_t {
 uint8_t stream_on_off; /*< control the video stream is on or off*/
}) mavlink_tx1_control_stream_t;

#define MAVLINK_MSG_ID_TX1_CONTROL_STREAM_LEN 1
#define MAVLINK_MSG_ID_TX1_CONTROL_STREAM_MIN_LEN 1
#define MAVLINK_MSG_ID_220_LEN 1
#define MAVLINK_MSG_ID_220_MIN_LEN 1

#define MAVLINK_MSG_ID_TX1_CONTROL_STREAM_CRC 34
#define MAVLINK_MSG_ID_220_CRC 34



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_TX1_CONTROL_STREAM { \
	220, \
	"TX1_CONTROL_STREAM", \
	1, \
	{  { "stream_on_off", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_tx1_control_stream_t, stream_on_off) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_TX1_CONTROL_STREAM { \
	"TX1_CONTROL_STREAM", \
	1, \
	{  { "stream_on_off", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_tx1_control_stream_t, stream_on_off) }, \
         } \
}
#endif

/**
 * @brief Pack a tx1_control_stream message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param stream_on_off control the video stream is on or off
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_tx1_control_stream_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t stream_on_off)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_TX1_CONTROL_STREAM_LEN];
	_mav_put_uint8_t(buf, 0, stream_on_off);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TX1_CONTROL_STREAM_LEN);
#else
	mavlink_tx1_control_stream_t packet;
	packet.stream_on_off = stream_on_off;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TX1_CONTROL_STREAM_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_TX1_CONTROL_STREAM;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_TX1_CONTROL_STREAM_MIN_LEN, MAVLINK_MSG_ID_TX1_CONTROL_STREAM_LEN, MAVLINK_MSG_ID_TX1_CONTROL_STREAM_CRC);
}

/**
 * @brief Pack a tx1_control_stream message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param stream_on_off control the video stream is on or off
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_tx1_control_stream_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t stream_on_off)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_TX1_CONTROL_STREAM_LEN];
	_mav_put_uint8_t(buf, 0, stream_on_off);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TX1_CONTROL_STREAM_LEN);
#else
	mavlink_tx1_control_stream_t packet;
	packet.stream_on_off = stream_on_off;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TX1_CONTROL_STREAM_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_TX1_CONTROL_STREAM;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_TX1_CONTROL_STREAM_MIN_LEN, MAVLINK_MSG_ID_TX1_CONTROL_STREAM_LEN, MAVLINK_MSG_ID_TX1_CONTROL_STREAM_CRC);
}

/**
 * @brief Encode a tx1_control_stream struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param tx1_control_stream C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_tx1_control_stream_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_tx1_control_stream_t* tx1_control_stream)
{
	return mavlink_msg_tx1_control_stream_pack(system_id, component_id, msg, tx1_control_stream->stream_on_off);
}

/**
 * @brief Encode a tx1_control_stream struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param tx1_control_stream C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_tx1_control_stream_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_tx1_control_stream_t* tx1_control_stream)
{
	return mavlink_msg_tx1_control_stream_pack_chan(system_id, component_id, chan, msg, tx1_control_stream->stream_on_off);
}

/**
 * @brief Send a tx1_control_stream message
 * @param chan MAVLink channel to send the message
 *
 * @param stream_on_off control the video stream is on or off
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_tx1_control_stream_send(mavlink_channel_t chan, uint8_t stream_on_off)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_TX1_CONTROL_STREAM_LEN];
	_mav_put_uint8_t(buf, 0, stream_on_off);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TX1_CONTROL_STREAM, buf, MAVLINK_MSG_ID_TX1_CONTROL_STREAM_MIN_LEN, MAVLINK_MSG_ID_TX1_CONTROL_STREAM_LEN, MAVLINK_MSG_ID_TX1_CONTROL_STREAM_CRC);
#else
	mavlink_tx1_control_stream_t packet;
	packet.stream_on_off = stream_on_off;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TX1_CONTROL_STREAM, (const char *)&packet, MAVLINK_MSG_ID_TX1_CONTROL_STREAM_MIN_LEN, MAVLINK_MSG_ID_TX1_CONTROL_STREAM_LEN, MAVLINK_MSG_ID_TX1_CONTROL_STREAM_CRC);
#endif
}

/**
 * @brief Send a tx1_control_stream message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_tx1_control_stream_send_struct(mavlink_channel_t chan, const mavlink_tx1_control_stream_t* tx1_control_stream)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_tx1_control_stream_send(chan, tx1_control_stream->stream_on_off);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TX1_CONTROL_STREAM, (const char *)tx1_control_stream, MAVLINK_MSG_ID_TX1_CONTROL_STREAM_MIN_LEN, MAVLINK_MSG_ID_TX1_CONTROL_STREAM_LEN, MAVLINK_MSG_ID_TX1_CONTROL_STREAM_CRC);
#endif
}

#if MAVLINK_MSG_ID_TX1_CONTROL_STREAM_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_tx1_control_stream_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t stream_on_off)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint8_t(buf, 0, stream_on_off);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TX1_CONTROL_STREAM, buf, MAVLINK_MSG_ID_TX1_CONTROL_STREAM_MIN_LEN, MAVLINK_MSG_ID_TX1_CONTROL_STREAM_LEN, MAVLINK_MSG_ID_TX1_CONTROL_STREAM_CRC);
#else
	mavlink_tx1_control_stream_t *packet = (mavlink_tx1_control_stream_t *)msgbuf;
	packet->stream_on_off = stream_on_off;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TX1_CONTROL_STREAM, (const char *)packet, MAVLINK_MSG_ID_TX1_CONTROL_STREAM_MIN_LEN, MAVLINK_MSG_ID_TX1_CONTROL_STREAM_LEN, MAVLINK_MSG_ID_TX1_CONTROL_STREAM_CRC);
#endif
}
#endif

#endif

// MESSAGE TX1_CONTROL_STREAM UNPACKING


/**
 * @brief Get field stream_on_off from tx1_control_stream message
 *
 * @return control the video stream is on or off
 */
static inline uint8_t mavlink_msg_tx1_control_stream_get_stream_on_off(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Decode a tx1_control_stream message into a struct
 *
 * @param msg The message to decode
 * @param tx1_control_stream C-struct to decode the message contents into
 */
static inline void mavlink_msg_tx1_control_stream_decode(const mavlink_message_t* msg, mavlink_tx1_control_stream_t* tx1_control_stream)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	tx1_control_stream->stream_on_off = mavlink_msg_tx1_control_stream_get_stream_on_off(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_TX1_CONTROL_STREAM_LEN? msg->len : MAVLINK_MSG_ID_TX1_CONTROL_STREAM_LEN;
        memset(tx1_control_stream, 0, MAVLINK_MSG_ID_TX1_CONTROL_STREAM_LEN);
	memcpy(tx1_control_stream, _MAV_PAYLOAD(msg), len);
#endif
}
