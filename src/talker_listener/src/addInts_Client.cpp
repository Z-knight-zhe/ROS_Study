#include "ros/ros.h"
#include "talker_listener/server_communication.h"


int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");

    if (argc != 3)
    {
        ROS_ERROR("请提交两个整数");
        return 1;
    }

    ros::init(argc, argv, "addInts_Client");

    ros::NodeHandle nh;

    ros::ServiceClient client = nh.serviceClient<talker_listener::server_communication>("AddInts");
    ros::service::waitForService("AddInts");


    talker_listener::server_communication ai;
    ai.request.num1 = atoi(argv[1]);
    ai.request.num2 = atoi(argv[2]);

    bool flag = client.call(ai);

    if(flag) {
        ROS_INFO("请求正常处理，响应结果%d", ai.response.sum);
    } else {
        ROS_ERROR("请求处理失败...");
        return 1;
    }

    return 0;
}