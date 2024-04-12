#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
#include "talker_listener/Person.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    
    ros::init(argc, argv, "talker");

    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<talker_listener::Person>("chatter", 1000);

    talker_listener::Person p;
    p.name = "Sunwukong";
    p.age = 2000;
    p.height = 1.45;
    //std_msgs::String msg;

    //std::string msg_front = "Hello 你好！";
    //int count = 0;

    ros::Rate r(1);

    while(ros::ok())
    {

        pub.publish(p);
        p.age += 1;

        ROS_INFO("我叫：%s，今年%d岁，高%.2f米", p.name.c_str(), p.age, p.height);

        r.sleep();
        ros::spinOnce();
    }

    return 0;
}