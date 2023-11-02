#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "CC_Example";

// For Block CC_Example/Subscribe1
SimulinkSubscriber<std_msgs::Float64, SL_Bus_CC_Example_std_msgs_Float64> Sub_CC_Example_36;

// For Block CC_Example/Publish
SimulinkPublisher<std_msgs::Float64, SL_Bus_CC_Example_std_msgs_Float64> Pub_CC_Example_38;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

