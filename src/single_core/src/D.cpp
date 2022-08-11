#include <ros/ros.h>
#include <std_msgs/Int32.h>

ros::Subscriber sub_;
int n=0;
int real, cbc;

void cb(const std_msgs::Int32& msg){
    for(int i=0; i<real; i++){
        n=1-n;
    }
}

int main(int argc, char* argv[]){
    ros::init(argc, argv, "D");  
    ros::NodeHandle nh;
    int rate;

    nh.param("/D/rate", rate, -1);
    nh.param("/D/real", real, -1);
    nh.param("/D/cbc", cbc, -1);

    sub_=nh.subscribe("/topic_C", 10, cb);

    ros::Rate r(rate);
    while(ros::ok()){
        ros::spinOnce();
        for(int i=0; i<cbc; i++){
            n=1-n;
        }
        r.sleep();
    }
    return 0;
}