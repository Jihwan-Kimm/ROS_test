#include <ros/ros.h>
#include <std_msgs/Int32.h>

class D{
    public:
        D();
        void d_node_cb(const std_msgs::Int32& msg);
        void Run();
    private:
        ros::NodeHandle nh_;
        ros::Publisher pub_;
        ros::Subscriber sub_;
        int topic_c=0;
};