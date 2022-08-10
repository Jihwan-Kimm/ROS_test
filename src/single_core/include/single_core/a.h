#include <ros/ros.h>
#include <std_msgs/Int32.h>

class A{
    public:
        A();
        void Run();
    private:
        ros::NodeHandle nh_;
        ros::Publisher pub_;
        std_msgs::Int32 msg_;
        int param_a;
};
