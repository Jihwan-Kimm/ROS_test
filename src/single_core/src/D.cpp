#include <ros/ros.h>

ros::Subscriber sub_;
ros::Publisher pub_;

ros::NodeHandle nh;

void cb(const geometry_msgs::PoseStampedConstPtr& msg){
    rubis::instance_ = RUBIS_NO_INSTANCE;
    
    pub_.publish(msg_);
}

int main(int argc, char* argv[]){
    ros::init(argc, argv, "D");  
    int rate;

    nh.param("/D/rate", rate, -1);

    sub_ = nh.subscribe("topic_C", 10, cb);

    ros::Rate r(rate);
    while(ros::ok()){
        ros::spinOnce();
        r.sleep();
    }
    return 0;
}