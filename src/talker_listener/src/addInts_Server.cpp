#include "ros/ros.h"
#include "talker_listener/server_communication.h"

bool doReq(talker_listener::server_communication::Request& req,
            talker_listener::server_communication::Response& resp)
{
    int num1 = req.num1;
    int num2 = req.num2;

    ROS_INFO("服务器接收到的请求数据为：num1 = %d, num2 = %d", num1, num2);

    if (num1 < 0 || num2 < 0)
    {
        ROS_ERROR("提交的数据有异常，不可以有负数");
        return false;
    }

    resp.sum = num1 + num2;
    return true;
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");

    ros::init(argc, argv, "addInts_Server");

    ros::NodeHandle nh;

    ros::ServiceServer server = nh.advertiseService("AddInts", doReq);

    ROS_INFO("服务已启动....");

    ros::spin();

    return 0;
    
}