#include <ros/ros.h>
#include <std_msgs/Int32.h>

ros::Subscriber sub_;

void cb(const std_msgs::Int32& msg){
}

int main(int argc, char* argv[]){
    ros::init(argc, argv, "D");  
    ros::NodeHandle nh;
    int rate;

    nh.param("/D/rate", rate, -1);

    sub_=nh.subscribe("/topic_C", 10, cb);

    ros::Rate r(rate);
    while(ros::ok()){
        ros::spinOnce();
        r.sleep();
    }
    return 0;
}