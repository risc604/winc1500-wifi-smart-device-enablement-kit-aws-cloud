/**
 * \file
 *
 * \brief MAIN configuration.
 *
 * Copyright (c) 2017 Atmel Corporation. All rights reserved.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. The name of Atmel may not be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * \asf_license_stop
 *
 */

/**
 * @file aws_iot_config.h
 * @brief AWS IoT specific configuration file
 */

#ifndef SRC_SHADOW_IOT_SHADOW_CONFIG_H_
#define SRC_SHADOW_IOT_SHADOW_CONFIG_H_

// Get from console
// =================================================
#define AWS_IOT_MQTT_HOST              "xxxxxxxxxxxxxx.iot.us-east-1.amazonaws.com" // To be Modified based on the user account
#define AWS_IOT_MQTT_PORT               8883
#define AWS_IOT_MQTT_CLIENT_ID         "SAMD21_MQTT"
#define AWS_IOT_MY_THING_NAME          "SAMD21_MQTT"
#define AWS_IOT_ROOT_CA_FILENAME       " "
#define AWS_IOT_CERTIFICATE_FILENAME   " "
#define AWS_IOT_PRIVATE_KEY_FILENAME   " "
// =================================================

// MQTT PubSub
#define AWS_IOT_MQTT_TX_BUF_LEN 1024 ///< Any time a message is sent out through the MQTT layer. The message is copied into this buffer anytime a publish is done. This will also be used in the case of Thing Shadow
#define AWS_IOT_MQTT_RX_BUF_LEN 2048 ///< Any message that comes into the device should be less than this buffer size. If a received message is bigger than this buffer size the message will be dropped.
#define AWS_IOT_MQTT_NUM_SUBSCRIBE_HANDLERS 5 ///< Maximum number of topic filters the MQTT client can handle at any given time. This should be increased appropriately when using Thing Shadow

// Thing Shadow specific configs
#define SHADOW_MAX_SIZE_OF_RX_BUFFER AWS_IOT_MQTT_RX_BUF_LEN+1 ///< Maximum size of the SHADOW buffer to store the received Shadow message
#define MAX_SIZE_OF_UNIQUE_CLIENT_ID_BYTES 80  ///< Maximum size of the Unique Client Id. For More info on the Client Id refer \ref response "Acknowledgments"
#define MAX_SIZE_CLIENT_ID_WITH_SEQUENCE MAX_SIZE_OF_UNIQUE_CLIENT_ID_BYTES + 10 ///< This is size of the extra sequence number that will be appended to the Unique client Id
#define MAX_SIZE_CLIENT_TOKEN_CLIENT_SEQUENCE MAX_SIZE_CLIENT_ID_WITH_SEQUENCE + 20 ///< This is size of the the total clientToken key and value pair in the JSON
#define MAX_ACKS_TO_COMEIN_AT_ANY_GIVEN_TIME 10 ///< At Any given time we will wait for this many responses. This will correlate to the rate at which the shadow actions are requested
#define MAX_THINGNAME_HANDLED_AT_ANY_GIVEN_TIME 10 ///< We could perform shadow action on any thing Name and this is maximum Thing Names we can act on at any given time
#define MAX_JSON_TOKEN_EXPECTED 120 ///< These are the max tokens that is expected to be in the Shadow JSON document. Include the metadata that gets published
#define MAX_SHADOW_TOPIC_LENGTH_WITHOUT_THINGNAME 60 ///< All shadow actions have to be published or subscribed to a topic which is of the format $aws/things/{thingName}/shadow/update/accepted. This refers to the size of the topic without the Thing Name
#define MAX_SIZE_OF_THING_NAME 20 ///< The Thing Name should not be bigger than this value. Modify this if the Thing Name needs to be bigger
#define MAX_SHADOW_TOPIC_LENGTH_BYTES MAX_SHADOW_TOPIC_LENGTH_WITHOUT_THINGNAME + MAX_SIZE_OF_THING_NAME ///< This size includes the length of topic with Thing Name

// Auto Reconnect specific config
#define AWS_IOT_MQTT_MIN_RECONNECT_WAIT_INTERVAL 1000 ///< Minimum time before the First reconnect attempt is made as part of the exponential back-off algorithm
//#define AWS_IOT_MQTT_MAX_RECONNECT_WAIT_INTERVAL 8000 ///< Maximum time interval after which exponential back-off will stop attempting to reconnect.
#define AWS_IOT_MQTT_MAX_RECONNECT_WAIT_INTERVAL 64000

#endif /* SRC_SHADOW_IOT_SHADOW_CONFIG_H_ */
