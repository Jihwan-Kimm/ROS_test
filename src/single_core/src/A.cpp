#include <ros/ros.h>
#include <std_msgs/Int32.h>

ros::Subscriber sub_;
ros::Publisher pub_;
std_msgs::Int32 msg_;

int main(int argc, char* argv[]){
    ros::init(argc, argv, "A");  
    ros::NodeHandle nh;
    int rate;

    nh.param("/A/rate", rate, -1);

    pub_=nh.advertise<std_msgs::Int32>("/topic_A", 10);
    msg_.data=7;

    ros::Rate r(rate);
    while(ros::ok()){
        pub_.publish(msg_);
        r.sleep();
    }
    return 0;
}