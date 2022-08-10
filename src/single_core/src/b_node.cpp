#include <single_core/b.h>

int main(int argc, char* argv[]){
    ros::init(argc, argv, "b");
    B b;
    b.Run();

    return 0;
}