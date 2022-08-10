#include <ros/ros.h>
#include <std_msgs/Int32.h>

ros::Subscriber sub_;
ros::Publisher pub_;

ros::NodeHandle nh;

void cb(const std_msgs::Int32& msg){
    pub_.publish(msg_);
}

int main(int argc, char* argv[]){
    ros::init(argc, argv, "B");  
    int rate;

    nh.param("/B/rate", rate, -1);

    pub_=nh.advertise<std_msgs::Int32>("topic_B", 10);
    sub_=nh.subscribe("topic_A", 10, cb);

    ros::Rate r(rate);
    while(ros::ok()){
        ros::spinOnce();
        r.sleep();
    }
    return 0;
}