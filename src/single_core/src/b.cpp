#include <single_core/b.h>

B::B(){
    pub_=nh_.advertise<std_msgs::Int32>("topic_b", 10);
    sub_=nh_.subscribe("topic_a", 10, &B::b_node_cb, this);
}

void B::b_node_cb(const std_msgs::Int32& msg){
    topic_a=msg.data;
}

void B::Run(){
    ros::Rate rate(10);

    nh_.param("/b/int_param", param_b, -1);

    while(ros::ok()){
        ros::spinOnce();
        msg_.data=param_b+topic_a;
        pub_.publish(msg_);
        ROS_INFO("topic_b : %d", msg_.data);
        rate.sleep();
    }
}