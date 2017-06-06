#include <iostream>
#include "Position.h"
#include "Rocket.h"
#include "Test.h"
#include "MyAttRocket.h"
#include "MyDefRocket.h"
#include "OpponentRocket.h"
#include "Launcher.h"
#include "Singleton.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    Test *MyTest;
    MyTest= new Test;
    if(MyTest->rocketTest()==1) std::cout<<"Rocket Test: passed!"<<std::endl;
    else std::cout<<"Rocket Test: failed!"<<std::endl;
    if(MyTest->OpRocket()==1) std::cout<<"Opponent Rocket Test: passed!"<<std::endl;
    else std::cout<<"Opponent Rocket Test: failed!"<<std::endl;
    if(MyTest->DefRocket()==1)   std::cout<<"Defensive Rocket Test: passed!"<<std::endl;
    else std::cout<<"Defensive Rocket Test: failed!"<<std::endl;
    if(MyTest->AttRocket()==1)   std::cout<<"Attacking Rocket Test: passed!"<<std::endl;
    else std::cout<<"Attacking Rocket Test: failed!"<<std::endl;
    if(MyTest->Launch()==1)   std::cout<<"Launcher Test: passed!"<<std::endl;
    else std::cout<<"Launcher Test: failed!"<<std::endl;

    delete MyTest;
    return 0;
}
