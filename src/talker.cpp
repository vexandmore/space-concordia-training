#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/UInt16.h"

#include <sstream>

//Send messages over ROS

int main(int argc, char** argv) {
	//ros::init must be called before doing anything else
	//needs the cmd args so it can do ros arguments
	//
	//The third argument is the name of the node.
	ros::init(argc, argv, "talker");

	//This is the main access point to comms with ROS. The first one
	//cted will initialize this node
	ros::NodeHandle n;

	//The advertise() function returns a Publisher that allows us to
	//publish messages in ROS. The first argument is the topic name,
	//the second is the queue size.
	//
	//Once all copies of the Publisher are destroyed, the topic 
	//will disappear
	ros::Publisher chatter_pub = n.advertise<std_msgs::UInt16>("toggle_led", 1000);
	//Specify a frequency to loop at
	ros::Rate loop_rate(5);

	int count = 0;//number of sent messages; determines whether to turn on or off
	while (ros::ok()) {
		std_msgs::UInt16 msg;

		msg.data = count % 2;
		ROS_INFO("sent to arduino:  %u", msg.data);
	
		//publish() is how the message is actually sent.
		chatter_pub.publish(msg);
		ros::spinOnce();
		//Wait sufficient time for the 10Hz rate
		loop_rate.sleep();
		count++;
	}
	return 0;
}







