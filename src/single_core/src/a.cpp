#include <single_core/a.h>

A::A(){
    pub_=nh_.advertise<std_msgs::Int32>("topic_a", 10);
}

void A::Run(){
    ros::Rate rate(10);

    nh_.param("/a/int_param", param_a, -1);

    while(ros::ok()){
        msg_.data=param_a++;
        pub_.publish(msg_);
        ROS_INFO("topic_a : %d", msg_.data);
        rate.sleep();
    }
}