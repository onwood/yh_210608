#include "ros/ros.h"
#include "yh_210608_2/yh_msg_2.h"

void msgCallback(const yh_210608_2::yh_msg_2::ConstPtr&msg) //const: 상수
{
	// ROS_INFO("receive msg = %d", msg -> stamp.sec);
	// ROS_INFO("receive msg = %d", msg -> stamp.nsec);
	if ((msg -> data) % 2 == 1)
		ROS_INFO("receive msg = %d", msg -> data);
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "yh_sub_2_int");
	ros::NodeHandle nh;

	ros::Subscriber sub = nh.subscribe("yh_topic_2", 100, msgCallback);
	ros::spin(); // 어떤 값이 들어오기 전까지 대기
	return 0;
}
