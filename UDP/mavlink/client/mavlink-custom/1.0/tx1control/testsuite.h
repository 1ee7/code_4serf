/** @file
 *	@brief MAVLink comm protocol testsuite generated from tx1control.xml
 *	@see http://qgroundcontrol.org/mavlink/
 */
#ifndef TX1CONTROL_TESTSUITE_H
#define TX1CONTROL_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL
static void mavlink_test_common(uint8_t, uint8_t, mavlink_message_t *last_msg);
static void mavlink_test_ardupilotmega(uint8_t, uint8_t, mavlink_message_t *last_msg);
static void mavlink_test_tx1control(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_test_common(system_id, component_id, last_msg);
	mavlink_test_ardupilotmega(system_id, component_id, last_msg);
	mavlink_test_tx1control(system_id, component_id, last_msg);
}
#endif

#include "../common/testsuite.h"
#include "../ardupilotmega/testsuite.h"


static void mavlink_test_tx1_control_stream(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
	mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_TX1_CONTROL_STREAM >= 256) {
        	return;
        }
#endif
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_tx1_control_stream_t packet_in = {
		5
    };
	mavlink_tx1_control_stream_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.stream_on_off = packet_in.stream_on_off;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_TX1_CONTROL_STREAM_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_TX1_CONTROL_STREAM_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_tx1_control_stream_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_tx1_control_stream_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_tx1_control_stream_pack(system_id, component_id, &msg , packet1.stream_on_off );
	mavlink_msg_tx1_control_stream_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_tx1_control_stream_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.stream_on_off );
	mavlink_msg_tx1_control_stream_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_tx1_control_stream_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_tx1_control_stream_send(MAVLINK_COMM_1 , packet1.stream_on_off );
	mavlink_msg_tx1_control_stream_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_tx1_control_record(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
	mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_TX1_CONTROL_RECORD >= 256) {
        	return;
        }
#endif
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_tx1_control_record_t packet_in = {
		5
    };
	mavlink_tx1_control_record_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.record_on_off = packet_in.record_on_off;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_TX1_CONTROL_RECORD_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_TX1_CONTROL_RECORD_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_tx1_control_record_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_tx1_control_record_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_tx1_control_record_pack(system_id, component_id, &msg , packet1.record_on_off );
	mavlink_msg_tx1_control_record_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_tx1_control_record_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.record_on_off );
	mavlink_msg_tx1_control_record_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_tx1_control_record_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_tx1_control_record_send(MAVLINK_COMM_1 , packet1.record_on_off );
	mavlink_msg_tx1_control_record_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_tx1_control_position(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
	mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_TX1_CONTROL_POSITION >= 256) {
        	return;
        }
#endif
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_tx1_control_position_t packet_in = {
		17235,17339,17443,17547
    };
	mavlink_tx1_control_position_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.top_left_x = packet_in.top_left_x;
        packet1.top_left_y = packet_in.top_left_y;
        packet1.bottom_right_x = packet_in.bottom_right_x;
        packet1.bottom_left_y = packet_in.bottom_left_y;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_TX1_CONTROL_POSITION_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_TX1_CONTROL_POSITION_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_tx1_control_position_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_tx1_control_position_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_tx1_control_position_pack(system_id, component_id, &msg , packet1.top_left_x , packet1.top_left_y , packet1.bottom_right_x , packet1.bottom_left_y );
	mavlink_msg_tx1_control_position_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_tx1_control_position_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.top_left_x , packet1.top_left_y , packet1.bottom_right_x , packet1.bottom_left_y );
	mavlink_msg_tx1_control_position_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_tx1_control_position_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_tx1_control_position_send(MAVLINK_COMM_1 , packet1.top_left_x , packet1.top_left_y , packet1.bottom_right_x , packet1.bottom_left_y );
	mavlink_msg_tx1_control_position_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_tx1_tracked_position(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
	mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_TX1_TRACKED_POSITION >= 256) {
        	return;
        }
#endif
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_tx1_tracked_position_t packet_in = {
		17235,17339,17443,17547,17651
    };
	mavlink_tx1_tracked_position_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.track_top_left_x = packet_in.track_top_left_x;
        packet1.track_top_left_y = packet_in.track_top_left_y;
        packet1.track_bottom_right_x = packet_in.track_bottom_right_x;
        packet1.track_bottom_left_y = packet_in.track_bottom_left_y;
        packet1.tracked_positon = packet_in.tracked_positon;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_TX1_TRACKED_POSITION_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_TX1_TRACKED_POSITION_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_tx1_tracked_position_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_tx1_tracked_position_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_tx1_tracked_position_pack(system_id, component_id, &msg , packet1.track_top_left_x , packet1.track_top_left_y , packet1.track_bottom_right_x , packet1.track_bottom_left_y , packet1.tracked_positon );
	mavlink_msg_tx1_tracked_position_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_tx1_tracked_position_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.track_top_left_x , packet1.track_top_left_y , packet1.track_bottom_right_x , packet1.track_bottom_left_y , packet1.tracked_positon );
	mavlink_msg_tx1_tracked_position_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_tx1_tracked_position_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_tx1_tracked_position_send(MAVLINK_COMM_1 , packet1.track_top_left_x , packet1.track_top_left_y , packet1.track_bottom_right_x , packet1.track_bottom_left_y , packet1.tracked_positon );
	mavlink_msg_tx1_tracked_position_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_tx1control(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_test_tx1_control_stream(system_id, component_id, last_msg);
	mavlink_test_tx1_control_record(system_id, component_id, last_msg);
	mavlink_test_tx1_control_position(system_id, component_id, last_msg);
	mavlink_test_tx1_tracked_position(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // TX1CONTROL_TESTSUITE_H
