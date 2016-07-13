// MESSAGE TX1_CONTROL_RECORD PACKING

#define MAVLINK_MSG_ID_TX1_CONTROL_RECORD 221

MAVPACKED(
typedef struct __mavlink_tx1_control_record_t {
 uint8_t record_on_off; /*< control the record is on or off*/
}) mavlink_tx1_control_record_t;

#define MAVLINK_MSG_ID_TX1_CONTROL_RECORD_LEN 1
#define MAVLINK_MSG_ID_TX1_CONTROL_RECORD_MIN_LEN 1
#define MAVLINK_MSG_ID_221_LEN 1
#define MAVLINK_MSG_ID_221_MIN_LEN 1

#define MAVLINK_MSG_ID_TX1_CONTROL_RECORD_CRC 198
#define MAVLINK_MSG_ID_221_CRC 198



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_TX1_CONTROL_RECORD { \
	221, \
	"TX1_CONTROL_RECORD", \
	1, \
	{  { "record_on_off", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_tx1_control_record_t, record_on_off) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_TX1_CONTROL_RECORD { \
	"TX1_CONTROL_RECORD", \
	1, \
	{  { "record_on_off", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_tx1_control_record_t, record_on_off) }, \
         } \
}
#endif

/**
 * @brief Pack a tx1_control_record message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param record_on_off control the record is on or off
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_tx1_control_record_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t record_on_off)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_TX1_CONTROL_RECORD_LEN];
	_mav_put_uint8_t(buf, 0, record_on_off);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TX1_CONTROL_RECORD_LEN);
#else
	mavlink_tx1_control_record_t packet;
	packet.record_on_off = record_on_off;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TX1_CONTROL_RECORD_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_TX1_CONTROL_RECORD;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_TX1_CONTROL_RECORD_MIN_LEN, MAVLINK_MSG_ID_TX1_CONTROL_RECORD_LEN, MAVLINK_MSG_ID_TX1_CONTROL_RECORD_CRC);
}

/**
 * @brief Pack a tx1_control_record message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param record_on_off control the record is on or off
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_tx1_control_record_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t record_on_off)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_TX1_CONTROL_RECORD_LEN];
	_mav_put_uint8_t(buf, 0, record_on_off);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TX1_CONTROL_RECORD_LEN);
#else
	mavlink_tx1_control_record_t packet;
	packet.record_on_off = record_on_off;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TX1_CONTROL_RECORD_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_TX1_CONTROL_RECORD;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_TX1_CONTROL_RECORD_MIN_LEN, MAVLINK_MSG_ID_TX1_CONTROL_RECORD_LEN, MAVLINK_MSG_ID_TX1_CONTROL_RECORD_CRC);
}

/**
 * @brief Encode a tx1_control_record struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param tx1_control_record C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_tx1_control_record_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_tx1_control_record_t* tx1_control_record)
{
	return mavlink_msg_tx1_control_record_pack(system_id, component_id, msg, tx1_control_record->record_on_off);
}

/**
 * @brief Encode a tx1_control_record struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param tx1_control_record C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_tx1_control_record_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_tx1_control_record_t* tx1_control_record)
{
	return mavlink_msg_tx1_control_record_pack_chan(system_id, component_id, chan, msg, tx1_control_record->record_on_off);
}

/**
 * @brief Send a tx1_control_record message
 * @param chan MAVLink channel to send the message
 *
 * @param record_on_off control the record is on or off
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_tx1_control_record_send(mavlink_channel_t chan, uint8_t record_on_off)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_TX1_CONTROL_RECORD_LEN];
	_mav_put_uint8_t(buf, 0, record_on_off);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TX1_CONTROL_RECORD, buf, MAVLINK_MSG_ID_TX1_CONTROL_RECORD_MIN_LEN, MAVLINK_MSG_ID_TX1_CONTROL_RECORD_LEN, MAVLINK_MSG_ID_TX1_CONTROL_RECORD_CRC);
#else
	mavlink_tx1_control_record_t packet;
	packet.record_on_off = record_on_off;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TX1_CONTROL_RECORD, (const char *)&packet, MAVLINK_MSG_ID_TX1_CONTROL_RECORD_MIN_LEN, MAVLINK_MSG_ID_TX1_CONTROL_RECORD_LEN, MAVLINK_MSG_ID_TX1_CONTROL_RECORD_CRC);
#endif
}

/**
 * @brief Send a tx1_control_record message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_tx1_control_record_send_struct(mavlink_channel_t chan, const mavlink_tx1_control_record_t* tx1_control_record)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_tx1_control_record_send(chan, tx1_control_record->record_on_off);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TX1_CONTROL_RECORD, (const char *)tx1_control_record, MAVLINK_MSG_ID_TX1_CONTROL_RECORD_MIN_LEN, MAVLINK_MSG_ID_TX1_CONTROL_RECORD_LEN, MAVLINK_MSG_ID_TX1_CONTROL_RECORD_CRC);
#endif
}

#if MAVLINK_MSG_ID_TX1_CONTROL_RECORD_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_tx1_control_record_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t record_on_off)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint8_t(buf, 0, record_on_off);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TX1_CONTROL_RECORD, buf, MAVLINK_MSG_ID_TX1_CONTROL_RECORD_MIN_LEN, MAVLINK_MSG_ID_TX1_CONTROL_RECORD_LEN, MAVLINK_MSG_ID_TX1_CONTROL_RECORD_CRC);
#else
	mavlink_tx1_control_record_t *packet = (mavlink_tx1_control_record_t *)msgbuf;
	packet->record_on_off = record_on_off;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TX1_CONTROL_RECORD, (const char *)packet, MAVLINK_MSG_ID_TX1_CONTROL_RECORD_MIN_LEN, MAVLINK_MSG_ID_TX1_CONTROL_RECORD_LEN, MAVLINK_MSG_ID_TX1_CONTROL_RECORD_CRC);
#endif
}
#endif

#endif

// MESSAGE TX1_CONTROL_RECORD UNPACKING


/**
 * @brief Get field record_on_off from tx1_control_record message
 *
 * @return control the record is on or off
 */
static inline uint8_t mavlink_msg_tx1_control_record_get_record_on_off(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Decode a tx1_control_record message into a struct
 *
 * @param msg The message to decode
 * @param tx1_control_record C-struct to decode the message contents into
 */
static inline void mavlink_msg_tx1_control_record_decode(const mavlink_message_t* msg, mavlink_tx1_control_record_t* tx1_control_record)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	tx1_control_record->record_on_off = mavlink_msg_tx1_control_record_get_record_on_off(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_TX1_CONTROL_RECORD_LEN? msg->len : MAVLINK_MSG_ID_TX1_CONTROL_RECORD_LEN;
        memset(tx1_control_record, 0, MAVLINK_MSG_ID_TX1_CONTROL_RECORD_LEN);
	memcpy(tx1_control_record, _MAV_PAYLOAD(msg), len);
#endif
}
