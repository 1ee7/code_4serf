// MESSAGE TX1_TRACKED_POSITION PACKING

#define MAVLINK_MSG_ID_TX1_TRACKED_POSITION 223

MAVPACKED(
typedef struct __mavlink_tx1_tracked_position_t {
 uint16_t track_top_left_x; /*< the value of top left positon x tracked*/
 uint16_t track_top_left_y; /*< the value of top left positon y tracked*/
 uint16_t track_bottom_right_x; /*< the value of bottom right positon x tracked*/
 uint16_t track_bottom_left_y; /*< the value of bottom left position y tracked*/
 uint16_t tracked_positon; /*< i dont know what is for*/
}) mavlink_tx1_tracked_position_t;

#define MAVLINK_MSG_ID_TX1_TRACKED_POSITION_LEN 10
#define MAVLINK_MSG_ID_TX1_TRACKED_POSITION_MIN_LEN 10
#define MAVLINK_MSG_ID_223_LEN 10
#define MAVLINK_MSG_ID_223_MIN_LEN 10

#define MAVLINK_MSG_ID_TX1_TRACKED_POSITION_CRC 165
#define MAVLINK_MSG_ID_223_CRC 165



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_TX1_TRACKED_POSITION { \
	223, \
	"TX1_TRACKED_POSITION", \
	5, \
	{  { "track_top_left_x", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_tx1_tracked_position_t, track_top_left_x) }, \
         { "track_top_left_y", NULL, MAVLINK_TYPE_UINT16_T, 0, 2, offsetof(mavlink_tx1_tracked_position_t, track_top_left_y) }, \
         { "track_bottom_right_x", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_tx1_tracked_position_t, track_bottom_right_x) }, \
         { "track_bottom_left_y", NULL, MAVLINK_TYPE_UINT16_T, 0, 6, offsetof(mavlink_tx1_tracked_position_t, track_bottom_left_y) }, \
         { "tracked_positon", NULL, MAVLINK_TYPE_UINT16_T, 0, 8, offsetof(mavlink_tx1_tracked_position_t, tracked_positon) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_TX1_TRACKED_POSITION { \
	"TX1_TRACKED_POSITION", \
	5, \
	{  { "track_top_left_x", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_tx1_tracked_position_t, track_top_left_x) }, \
         { "track_top_left_y", NULL, MAVLINK_TYPE_UINT16_T, 0, 2, offsetof(mavlink_tx1_tracked_position_t, track_top_left_y) }, \
         { "track_bottom_right_x", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_tx1_tracked_position_t, track_bottom_right_x) }, \
         { "track_bottom_left_y", NULL, MAVLINK_TYPE_UINT16_T, 0, 6, offsetof(mavlink_tx1_tracked_position_t, track_bottom_left_y) }, \
         { "tracked_positon", NULL, MAVLINK_TYPE_UINT16_T, 0, 8, offsetof(mavlink_tx1_tracked_position_t, tracked_positon) }, \
         } \
}
#endif

/**
 * @brief Pack a tx1_tracked_position message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param track_top_left_x the value of top left positon x tracked
 * @param track_top_left_y the value of top left positon y tracked
 * @param track_bottom_right_x the value of bottom right positon x tracked
 * @param track_bottom_left_y the value of bottom left position y tracked
 * @param tracked_positon i dont know what is for
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_tx1_tracked_position_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint16_t track_top_left_x, uint16_t track_top_left_y, uint16_t track_bottom_right_x, uint16_t track_bottom_left_y, uint16_t tracked_positon)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_TX1_TRACKED_POSITION_LEN];
	_mav_put_uint16_t(buf, 0, track_top_left_x);
	_mav_put_uint16_t(buf, 2, track_top_left_y);
	_mav_put_uint16_t(buf, 4, track_bottom_right_x);
	_mav_put_uint16_t(buf, 6, track_bottom_left_y);
	_mav_put_uint16_t(buf, 8, tracked_positon);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TX1_TRACKED_POSITION_LEN);
#else
	mavlink_tx1_tracked_position_t packet;
	packet.track_top_left_x = track_top_left_x;
	packet.track_top_left_y = track_top_left_y;
	packet.track_bottom_right_x = track_bottom_right_x;
	packet.track_bottom_left_y = track_bottom_left_y;
	packet.tracked_positon = tracked_positon;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TX1_TRACKED_POSITION_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_TX1_TRACKED_POSITION;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_TX1_TRACKED_POSITION_MIN_LEN, MAVLINK_MSG_ID_TX1_TRACKED_POSITION_LEN, MAVLINK_MSG_ID_TX1_TRACKED_POSITION_CRC);
}

/**
 * @brief Pack a tx1_tracked_position message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param track_top_left_x the value of top left positon x tracked
 * @param track_top_left_y the value of top left positon y tracked
 * @param track_bottom_right_x the value of bottom right positon x tracked
 * @param track_bottom_left_y the value of bottom left position y tracked
 * @param tracked_positon i dont know what is for
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_tx1_tracked_position_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint16_t track_top_left_x,uint16_t track_top_left_y,uint16_t track_bottom_right_x,uint16_t track_bottom_left_y,uint16_t tracked_positon)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_TX1_TRACKED_POSITION_LEN];
	_mav_put_uint16_t(buf, 0, track_top_left_x);
	_mav_put_uint16_t(buf, 2, track_top_left_y);
	_mav_put_uint16_t(buf, 4, track_bottom_right_x);
	_mav_put_uint16_t(buf, 6, track_bottom_left_y);
	_mav_put_uint16_t(buf, 8, tracked_positon);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TX1_TRACKED_POSITION_LEN);
#else
	mavlink_tx1_tracked_position_t packet;
	packet.track_top_left_x = track_top_left_x;
	packet.track_top_left_y = track_top_left_y;
	packet.track_bottom_right_x = track_bottom_right_x;
	packet.track_bottom_left_y = track_bottom_left_y;
	packet.tracked_positon = tracked_positon;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TX1_TRACKED_POSITION_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_TX1_TRACKED_POSITION;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_TX1_TRACKED_POSITION_MIN_LEN, MAVLINK_MSG_ID_TX1_TRACKED_POSITION_LEN, MAVLINK_MSG_ID_TX1_TRACKED_POSITION_CRC);
}

/**
 * @brief Encode a tx1_tracked_position struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param tx1_tracked_position C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_tx1_tracked_position_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_tx1_tracked_position_t* tx1_tracked_position)
{
	return mavlink_msg_tx1_tracked_position_pack(system_id, component_id, msg, tx1_tracked_position->track_top_left_x, tx1_tracked_position->track_top_left_y, tx1_tracked_position->track_bottom_right_x, tx1_tracked_position->track_bottom_left_y, tx1_tracked_position->tracked_positon);
}

/**
 * @brief Encode a tx1_tracked_position struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param tx1_tracked_position C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_tx1_tracked_position_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_tx1_tracked_position_t* tx1_tracked_position)
{
	return mavlink_msg_tx1_tracked_position_pack_chan(system_id, component_id, chan, msg, tx1_tracked_position->track_top_left_x, tx1_tracked_position->track_top_left_y, tx1_tracked_position->track_bottom_right_x, tx1_tracked_position->track_bottom_left_y, tx1_tracked_position->tracked_positon);
}

/**
 * @brief Send a tx1_tracked_position message
 * @param chan MAVLink channel to send the message
 *
 * @param track_top_left_x the value of top left positon x tracked
 * @param track_top_left_y the value of top left positon y tracked
 * @param track_bottom_right_x the value of bottom right positon x tracked
 * @param track_bottom_left_y the value of bottom left position y tracked
 * @param tracked_positon i dont know what is for
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_tx1_tracked_position_send(mavlink_channel_t chan, uint16_t track_top_left_x, uint16_t track_top_left_y, uint16_t track_bottom_right_x, uint16_t track_bottom_left_y, uint16_t tracked_positon)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_TX1_TRACKED_POSITION_LEN];
	_mav_put_uint16_t(buf, 0, track_top_left_x);
	_mav_put_uint16_t(buf, 2, track_top_left_y);
	_mav_put_uint16_t(buf, 4, track_bottom_right_x);
	_mav_put_uint16_t(buf, 6, track_bottom_left_y);
	_mav_put_uint16_t(buf, 8, tracked_positon);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TX1_TRACKED_POSITION, buf, MAVLINK_MSG_ID_TX1_TRACKED_POSITION_MIN_LEN, MAVLINK_MSG_ID_TX1_TRACKED_POSITION_LEN, MAVLINK_MSG_ID_TX1_TRACKED_POSITION_CRC);
#else
	mavlink_tx1_tracked_position_t packet;
	packet.track_top_left_x = track_top_left_x;
	packet.track_top_left_y = track_top_left_y;
	packet.track_bottom_right_x = track_bottom_right_x;
	packet.track_bottom_left_y = track_bottom_left_y;
	packet.tracked_positon = tracked_positon;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TX1_TRACKED_POSITION, (const char *)&packet, MAVLINK_MSG_ID_TX1_TRACKED_POSITION_MIN_LEN, MAVLINK_MSG_ID_TX1_TRACKED_POSITION_LEN, MAVLINK_MSG_ID_TX1_TRACKED_POSITION_CRC);
#endif
}

/**
 * @brief Send a tx1_tracked_position message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_tx1_tracked_position_send_struct(mavlink_channel_t chan, const mavlink_tx1_tracked_position_t* tx1_tracked_position)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_tx1_tracked_position_send(chan, tx1_tracked_position->track_top_left_x, tx1_tracked_position->track_top_left_y, tx1_tracked_position->track_bottom_right_x, tx1_tracked_position->track_bottom_left_y, tx1_tracked_position->tracked_positon);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TX1_TRACKED_POSITION, (const char *)tx1_tracked_position, MAVLINK_MSG_ID_TX1_TRACKED_POSITION_MIN_LEN, MAVLINK_MSG_ID_TX1_TRACKED_POSITION_LEN, MAVLINK_MSG_ID_TX1_TRACKED_POSITION_CRC);
#endif
}

#if MAVLINK_MSG_ID_TX1_TRACKED_POSITION_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_tx1_tracked_position_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint16_t track_top_left_x, uint16_t track_top_left_y, uint16_t track_bottom_right_x, uint16_t track_bottom_left_y, uint16_t tracked_positon)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint16_t(buf, 0, track_top_left_x);
	_mav_put_uint16_t(buf, 2, track_top_left_y);
	_mav_put_uint16_t(buf, 4, track_bottom_right_x);
	_mav_put_uint16_t(buf, 6, track_bottom_left_y);
	_mav_put_uint16_t(buf, 8, tracked_positon);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TX1_TRACKED_POSITION, buf, MAVLINK_MSG_ID_TX1_TRACKED_POSITION_MIN_LEN, MAVLINK_MSG_ID_TX1_TRACKED_POSITION_LEN, MAVLINK_MSG_ID_TX1_TRACKED_POSITION_CRC);
#else
	mavlink_tx1_tracked_position_t *packet = (mavlink_tx1_tracked_position_t *)msgbuf;
	packet->track_top_left_x = track_top_left_x;
	packet->track_top_left_y = track_top_left_y;
	packet->track_bottom_right_x = track_bottom_right_x;
	packet->track_bottom_left_y = track_bottom_left_y;
	packet->tracked_positon = tracked_positon;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TX1_TRACKED_POSITION, (const char *)packet, MAVLINK_MSG_ID_TX1_TRACKED_POSITION_MIN_LEN, MAVLINK_MSG_ID_TX1_TRACKED_POSITION_LEN, MAVLINK_MSG_ID_TX1_TRACKED_POSITION_CRC);
#endif
}
#endif

#endif

// MESSAGE TX1_TRACKED_POSITION UNPACKING


/**
 * @brief Get field track_top_left_x from tx1_tracked_position message
 *
 * @return the value of top left positon x tracked
 */
static inline uint16_t mavlink_msg_tx1_tracked_position_get_track_top_left_x(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Get field track_top_left_y from tx1_tracked_position message
 *
 * @return the value of top left positon y tracked
 */
static inline uint16_t mavlink_msg_tx1_tracked_position_get_track_top_left_y(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  2);
}

/**
 * @brief Get field track_bottom_right_x from tx1_tracked_position message
 *
 * @return the value of bottom right positon x tracked
 */
static inline uint16_t mavlink_msg_tx1_tracked_position_get_track_bottom_right_x(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  4);
}

/**
 * @brief Get field track_bottom_left_y from tx1_tracked_position message
 *
 * @return the value of bottom left position y tracked
 */
static inline uint16_t mavlink_msg_tx1_tracked_position_get_track_bottom_left_y(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  6);
}

/**
 * @brief Get field tracked_positon from tx1_tracked_position message
 *
 * @return i dont know what is for
 */
static inline uint16_t mavlink_msg_tx1_tracked_position_get_tracked_positon(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  8);
}

/**
 * @brief Decode a tx1_tracked_position message into a struct
 *
 * @param msg The message to decode
 * @param tx1_tracked_position C-struct to decode the message contents into
 */
static inline void mavlink_msg_tx1_tracked_position_decode(const mavlink_message_t* msg, mavlink_tx1_tracked_position_t* tx1_tracked_position)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	tx1_tracked_position->track_top_left_x = mavlink_msg_tx1_tracked_position_get_track_top_left_x(msg);
	tx1_tracked_position->track_top_left_y = mavlink_msg_tx1_tracked_position_get_track_top_left_y(msg);
	tx1_tracked_position->track_bottom_right_x = mavlink_msg_tx1_tracked_position_get_track_bottom_right_x(msg);
	tx1_tracked_position->track_bottom_left_y = mavlink_msg_tx1_tracked_position_get_track_bottom_left_y(msg);
	tx1_tracked_position->tracked_positon = mavlink_msg_tx1_tracked_position_get_tracked_positon(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_TX1_TRACKED_POSITION_LEN? msg->len : MAVLINK_MSG_ID_TX1_TRACKED_POSITION_LEN;
        memset(tx1_tracked_position, 0, MAVLINK_MSG_ID_TX1_TRACKED_POSITION_LEN);
	memcpy(tx1_tracked_position, _MAV_PAYLOAD(msg), len);
#endif
}
