# About

This is a submission for software training for Space Concordia.
Involves an arduino node, and two software nodes that publish to the arduino node and subscribe from a topic published from the arduino.

# Usage

Upload the arduino code in Arduino-src to the arduino, setup the arduino hardware as described below, setup rosserial as described below, and run catkin_make and catkin_make install.

Then, run these nodes:
rosrun <package-name> listener.py
rosrun <package-name> talker
rosrun rosserial_python serial_node.py /dev/ttyACM0

Note that /dev/tty/ACM0 must be the serial port where the arduino is, verify ex in Arduino IDE. Also make sure ros has read/write perms to the port.

## What are the nodes doing?
* listener.py is listening to button press messages from the arduino on "button_press"
* talker is sending signals to the arduino to turn its builtin led on and off on "toggle_led"

# Setup

## Arduino Setup
Add a button connected to digital pin 8 and ground (the sketch sets up an internal pullup). The arduino sketch uses the built-in LED, so no further hardware setup is required.

## To setup rosserial
Follow instructions in http://wiki.ros.org/rosserial_arduino/Tutorials/Arduino%20IDE%20Setup
AND do the hack in the last comment in https://github.com/ros-drivers/rosserial/issues/518 so it compiles

ALSO follow the hack here to make the python bridge work: https://answers.ros.org/question/362043/importerror-no-module-named-queue/

ALSO make sure ros can read from the serial port
