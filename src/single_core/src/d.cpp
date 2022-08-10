#include <single_core/d.h>

D::D(){
    sub_=nh_.subscribe("topic_c", 10, &D::d_node_cb, this);
}

void D::d_node_cb(const std_msgs::Int32& msg){
    topic_c=msg.data;
    ROS_WARN("D subscribed %d", topic_c);
}

void D::Run(){
    ros::Rate rate(10);
    while(ros::ok()){
        ros::spinOnce();
        rate.sleep();
    }
}