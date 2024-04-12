#include "ros/ros.h"
#include "std_msgs/String.h"
#include "talker_listener/Person.h"

void doMsg(const talker_listener::Person::ConstPtr& person_p) {
    ROS_INFO("订阅人的信息：%s, %d, %2f", person_p->name.c_str(), person_p->age, person_p->height);

}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");

    ros::init(argc, argv, "listener");

    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe<talker_listener::Person>("chatter", 10, doMsg);

    ros::spin();

    return 0;
}