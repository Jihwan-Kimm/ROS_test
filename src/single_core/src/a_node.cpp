#include <single_core/a.h>

int main(int argc, char* argv[]){
    ros::init(argc, argv, "a");
    A a;
    a.Run();

    return 0;
}