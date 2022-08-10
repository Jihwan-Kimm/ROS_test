#include <ros/ros.h>

ros::Subscriber sub_;
ros::Publisher pub_;

ros::NodeHandle nh;

void cb(const geometry_msgs::PoseStampedConstPtr& msg){
    rubis::instance_ = RUBIS_NO_INSTANCE;
    
    pub_.publish(msg_);
}

int main(int argc, char* argv[]){
    ros::init(argc, argv, "C");  
    int rate;

    nh.param("/C/rate", rate, -1);

    pub_=nh.advertise<std_msgs::Int32>("topic_C", 10);
    sub_ = nh.subscribe("topic_B", 10, cb);

    ros::Rate r(rate);
    while(ros::ok()){
        ros::spinOnce();
        r.sleep();
    }
    return 0;
}