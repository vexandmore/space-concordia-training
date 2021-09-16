#include "ros/ros.h"
#include "std_msgs/String.h"

void chatterCallback(const std_msgs::String::ConstPtr& msg) {
	ROS_INFO("I heard: [%s]", msg->data.c_str());
}

int main(int argc, char** argv) {
	ros::init(argc, argv, "listener");

	//As before, sets up the lifecycle of this node
	ros::NodeHandle n;

	/**
	 *  subscribe() is how we subscribe to a topic. Involved the
	 *  ROS master node. The messages are passed to the callback
	 *  function.
	 *  Once all copid of the returned object (type Subscriber) 
	 *  go out of scope, the callback will be unsubscribed.
	 *
	 */
	ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);
	//Enter a loop and just process callbacks. The way this is setup, 
	//all callbacks will be processed in this thread.
	//Exits on ctrl-c, etc.
	ros::spin();
	return 0;
}

