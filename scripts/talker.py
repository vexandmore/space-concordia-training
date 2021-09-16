#!/usr/bin/env python

import rospy
from std_msgs.msg import String

def talker():
    # declare that we're publishing on this topic, get the
    # object we need to publish
    pub = rospy.Publisher('chatter', String, queue_size=10)
    # initialize this node with name 'talker'
    # anonymous=True adds random nums to the end to ensure uniqueness
    rospy.init_node('talker', anonymous=True)
    rate = rospy.Rate(10) #10 hz
    while not rospy.is_shutdown():
        hello_str = "hello world %s" % rospy.get_time()
        # print to screen, write to log file, write to rosout
        rospy.loginfo(hello_str)
        pub.publish(hello_str)
        rate.sleep() # sleep to maintain 10Hz

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass # the exception could be thrown when ctrl-c pressed, etc

