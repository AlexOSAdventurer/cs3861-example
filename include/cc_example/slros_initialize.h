#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"
#include "CC_Example_types.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block CC_Example/Subscribe
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_CC_Example_std_msgs_Float64> Sub_CC_Example_37;

// For Block CC_Example/Subscribe1
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_CC_Example_std_msgs_Float64> Sub_CC_Example_36;

// For Block CC_Example/Publish
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_CC_Example_std_msgs_Float64> Pub_CC_Example_38;

// For Block CC_Example/Publish1
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_CC_Example_std_msgs_Float64> Pub_CC_Example_39;

// For Block CC_Example/Publish2
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_CC_Example_std_msgs_Float64> Pub_CC_Example_40;

void slros_node_init(int argc, char** argv);

#endif
