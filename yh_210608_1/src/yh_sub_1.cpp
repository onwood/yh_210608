#include "ros/ros.h"
#include "yh_210608_1/yh_msg_1.h"

void msgCallback(const yh_210608_1::yh_msg_1::ConstPtr&msg) //const: 상수
{
	ROS_INFO("receive msg = %d", msg -> stamp.sec);
	ROS_INFO("receive msg = %d", msg -> stamp.nsec);
	ROS_INFO("receive msg = %d", msg -> data);
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "yh_sub_1");
	ros::NodeHandle nh;

	ros::Subscriber sub = nh.subscribe("yh_topic_1", 100, msgCallback);
	ros::spin(); // 어떤 값이 들어오기 전까지 대기
	return 0;
}
