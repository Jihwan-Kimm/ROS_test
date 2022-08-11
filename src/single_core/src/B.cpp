#include <ros/ros.h>
#include <std_msgs/Int32.h>
#include <time.h>

ros::Subscriber sub_;
ros::Publisher pub_;
int n=0;
int real, cbc;

void cb(const std_msgs::Int32& msg){
    for(int i=0; i<real; i++){
        n=1-n;
    }
    pub_.publish(msg);
}

int main(int argc, char* argv[]){
    ros::init(argc, argv, "B");  
    ros::NodeHandle nh;
    int rate;

    nh.param("/B/rate", rate, -1);
    nh.param("/B/real", real, -1);
    nh.param("/B/cbc", cbc, -1);


    pub_=nh.advertise<std_msgs::Int32>("/topic_B", 10);
    sub_=nh.subscribe("/topic_A", 10, cb);

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