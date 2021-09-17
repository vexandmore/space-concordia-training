# System dependencies
ros-melodic-rosserial
ros-melodic-rosserial-arduino

(if you are using a version other than melodic, replace "melodic"
with whatever version of ROS you're using)

# To setup rosserial
Follow instructions in http://wiki.ros.org/rosserial_arduino/Tutorials/Arduino%20IDE%20Setup
AND do the hack in the last comment in https://github.com/ros-drivers/rosserial/issues/518 so it compiles

ALSO follow the hack here to make the python bridge work: https://answers.ros.org/question/362043/importerror-no-module-named-queue/

ALSO make sure ros can read from the serial port

# Arduino dependencies
rosserial
