#include <single_core/c.h>

C::C(){
    pub_=nh_.advertise<std_msgs::Int32>("topic_c", 10);
    sub_=nh_.subscribe("topic_b", 10, &C::c_node_cb, this);
}

void C::c_node_cb(const std_msgs::Int32& msg){
    topic_b=msg.data;
}

void C::Run(){
    ros::Rate rate(10);

    nh_.param("/c/int_param", param_c, -1);

    while(ros::ok()){
        ros::spinOnce();
        msg_.data=param_c+topic_b;
        pub_.publish(msg_);
        ROS_INFO("topic_c : %d", msg_.data);
        rate.sleep();
    }
}