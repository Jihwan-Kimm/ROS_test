#include <ros/ros.h>
#include <std_msgs/Int32.h>

class C{
    public:
        C();
        void c_node_cb(const std_msgs::Int32& msg);
        void Run();
    private:
        ros::NodeHandle nh_;
        ros::Publisher pub_;
        ros::Subscriber sub_;
        std_msgs::Int32 msg_; 
        int topic_b=0;
        int param_c;
};