#include "Test.h"

Test::Test()
{
    tRocket= new Rocket;
    ORocket= new OpponentRocket;
}

Test::~Test()
{
    delete tRocket;
    delete ORocket;
}
int Test::OpRocket()
{

    ORocket->startR();
    std::cout.precision(3);
    std::cout<<ORocket->getDir()<<"     "<<ORocket->getVel()<<"     ("<<ORocket->getXPos()<<", "<<ORocket->getYPos()<<")"<<std::endl;
    ORocket->nextTurn();
    std::cout<<ORocket->getDir()<<"     "<<ORocket->getVel()<<"     ("<<ORocket->getXPos()<<", "<<ORocket->getYPos()<<")"<<std::endl;
    ORocket->nextTurn();
    std::cout<<ORocket->getDir()<<"     "<<ORocket->getVel()<<"     ("<<ORocket->getXPos()<<", "<<ORocket->getYPos()<<")"<<std::endl;
    ORocket->nextTurn();
    std::cout<<ORocket->getDir()<<"     "<<ORocket->getVel()<<"     ("<<ORocket->getXPos()<<", "<<ORocket->getYPos()<<")"<<std::endl;
    ORocket->nextTurn();
    std::cout<<ORocket->getDir()<<"     "<<ORocket->getVel()<<"     ("<<ORocket->getXPos()<<", "<<ORocket->getYPos()<<")"<<std::endl;
    ORocket->newDir();
    ORocket->velUpdate();
    ORocket->nextTurn();
    std::cout<<ORocket->getDir()<<"     "<<ORocket->getVel()<<"     ("<<ORocket->getXPos()<<", "<<ORocket->getYPos()<<")"<<std::endl;
    ORocket->nextTurn();
    std::cout<<ORocket->getDir()<<"     "<<ORocket->getVel()<<"     ("<<ORocket->getXPos()<<", "<<ORocket->getYPos()<<")"<<std::endl;
    ORocket->nextTurn();
    std::cout<<ORocket->getDir()<<"     "<<ORocket->getVel()<<"     ("<<ORocket->getXPos()<<", "<<ORocket->getYPos()<<")"<<std::endl;
    return 1;
}
int Test::rocketTest()
{
    if(tRocket->setPos(32, 2)==0) return 0;
    if(tRocket->setPos(50, 32)==0) return 0;
    if(tRocket->setPos(32, -43)==0) return 0;
    std::cout<<tRocket->getVel()<<std::endl;
    std::cout<<tRocket->dirUpdate()<<std::endl;
    return 1;
}
int Test::DefRocket()
{
    MyDefRocket* rocket1;
    MyDefRocket* rocket2;
    MyDefRocket* rocket3;
    MyDefRocket* rocket4;
    OpponentRocket* target1;
    OpponentRocket* target2;
    OpponentRocket* target3;
    OpponentRocket* target4;
    rocket1=new MyDefRocket;
    rocket2=new MyDefRocket;
    rocket3=new MyDefRocket;
    rocket4=new MyDefRocket;
    target1=new OpponentRocket;
    target2=new OpponentRocket;
    target3=new OpponentRocket;
    target4=new OpponentRocket;

    target1->startR(9, 5);
    target2->startR(-32, 45);
    target3->startR(-21, -2);
    target4->startR(9, -145);

    rocket1->setVel(15);
    rocket2->setVel(25);
    rocket3->setVel(35);
    rocket4->setVel(35);

    target1->nextTurn();
    target2->nextTurn();
    target3->nextTurn();
    target4->nextTurn();

    rocket1->catchR(target1);
    rocket2->catchR(target2);
    rocket3->catchR(target3);
    rocket4->catchR(target4);
    std::cout<<"Round 1"<<std::endl;
    if(target1->isLive()==0) std::cout<<"Target1: destroyed"<<std::endl;
    else std::cout<<"Target1: Alive"<<std::endl;
    if(target2->isLive()==0) std::cout<<"Target2: destroyed"<<std::endl;
    else std::cout<<"Target2: Alive"<<std::endl;
    if(target3->isLive()==0) std::cout<<"Target3: destroyed"<<std::endl;
    else std::cout<<"Target3: Alive"<<std::endl;
    if(target4->isLive()==0) std::cout<<"Target4: destroyed"<<std::endl;
    else std::cout<<"Target4: Alive"<<std::endl;


    target1->nextTurn();
    target2->nextTurn();
    target3->nextTurn();
    target4->nextTurn();

    rocket1->catchR(target1);
    rocket2->catchR(target2);
    rocket3->catchR(target3);
    rocket4->catchR(target4);
    std::cout<<"Round 2"<<std::endl;
    if(target1->isLive()==0) std::cout<<"Target1: destroyed"<<std::endl;
    else std::cout<<"Target1: Alive"<<std::endl;
    if(target2->isLive()==0) std::cout<<"Target2: destroyed"<<std::endl;
    else std::cout<<"Target2: Alive"<<std::endl;
    if(target3->isLive()==0) std::cout<<"Target3: destroyed"<<std::endl;
    else std::cout<<"Target3: Alive"<<std::endl;
    if(target4->isLive()==0) std::cout<<"Target4: destroyed"<<std::endl;
    else std::cout<<"Target4: Alive"<<std::endl;

    rocket1->catchR(target1);
    rocket2->catchR(target2);
    rocket3->catchR(target3);
    rocket4->catchR(target4);
    delete rocket1;
    delete rocket2;
    delete rocket3;
    delete rocket4;
    delete target1;
    delete target2;
    delete target3;
    delete target4;
    return 1;
}

int Test::AttRocket()
{
    MyAttRocket* rocket1;
    MyAttRocket* rocket2;
    MyAttRocket* rocket3;
    MyAttRocket* rocket4;
    rocket1= new MyAttRocket;
    rocket2= new MyAttRocket;
    rocket3= new MyAttRocket;
    rocket4= new MyAttRocket;

    int i1=0, i2=0, i3=0, i4=0;

    rocket1->attack(145, -200);
    while (rocket1->isLive())
    {
        i1++;
        rocket1->nextTurn();
    }

    rocket2->attack(5, -10);
    while (rocket2->isLive())
    {
        i2++;
        rocket2->nextTurn();
    }

    Position* xy;
    xy=new Position;
    xy->setXY(-122, 230);

    rocket3->attack(xy);
    rocket3->setVel(30);
    while (rocket3->isLive())
    {
        i3++;
        rocket3->nextTurn();
    }

    xy->setXY(203, 15);
    rocket4->attack(xy);
    while (rocket4->isLive())
    {
        i4++;
        rocket4->nextTurn();
    }
    std::cout<<"Rocket 1: "<<i1<<std::endl;
    std::cout<<"Rocket 2: "<<i2<<std::endl;
    std::cout<<"Rocket 3: "<<i3<<std::endl;
    std::cout<<"Rocket 4: "<<i4<<std::endl;

    delete xy;
    delete rocket1;
    delete rocket2;
    delete rocket3;
    delete rocket4;
    return 1;
}

int Test::Launch()
{
    Launcher* launcher;
    launcher= new Launcher;
    launcher->addDfR(20);
    launcher->addDfR(20);
    launcher->addDfR(20);
    launcher->addDfR(20);
    launcher->addAtR(40);
    launcher->addAtR(50);
    launcher->addAtR(20);
    launcher->addAtR(30);
    launcher->addOpR(200, 184);
    launcher->addOpR(-200, 184);
    launcher->addOpR(200, -184);
    launcher->addOpR(-200, -184);
    MyDefRocket* D1;
    MyDefRocket* D2;
    MyDefRocket* D3;
    MyDefRocket* D4;
    D1=launcher->getDefR();
    D2=launcher->getDefR();
    D3=launcher->getDefR();
    D4=launcher->getDefR();
    OpponentRocket* O1;
    OpponentRocket* O2;
    OpponentRocket* O3;
    OpponentRocket* O4;
    O1=launcher->getOpR();
    O2=launcher->getOpR();
    O3=launcher->getOpR();
    O4=launcher->getOpR();
    if(D1==NULL || D2==NULL || D3==NULL || D4==NULL || O1==NULL || O2==NULL || O3==NULL || O4==NULL)
        return 0;
    launcher->unChoose(D3);
    launcher->unChoose(D2);
    D3=launcher->getDefR();
    D2=launcher->getDefR();

    int i1;
    for(i1=1;O1->isLive()==1 ;++i1)
    {
        O1->nextTurn();
        D1->catchR(O1);
    }
    std::cout<<"Test 1:"<<std::endl<<"chased after: "<<i1<<" turns."<<std::endl;

    int i2;
    for(i2=1;O2->isLive()==1  ;++i2)
    {
        O2->nextTurn();
        D2->catchR(O2);
    }
    std::cout<<"Test 2:"<<std::endl<<"chased after: "<<i2<<" turns."<<std::endl;

    int i3;
    for(i3=1;O3->isLive()==1  ;++i3)
    {
        O3->nextTurn();
        D3->catchR(O3);
    }
    std::cout<<"Test 3:"<<std::endl<<"chased after: "<<i3<<" turns."<<std::endl;

    int i4;
    for(i4=1;O4->isLive()==1 ;++i4)
    {
        O4->nextTurn();
        D4->catchR(O4);
    }
    std::cout<<"Test 4:"<<std::endl<<"chased after: "<<i4<<" turns."<<std::endl;

    MyAttRocket* A1;
    MyAttRocket* A2;
    MyAttRocket* A3;
    MyAttRocket* A4;
    A1=launcher->getAtR();
    A2=launcher->getAtR();
    A3=launcher->getAtR();
    A4=launcher->getAtR();
    if(A1==NULL || A2==NULL || A3==NULL || A4==NULL)
        return 0;
    A1->attack(130,102);
    A2->attack(-123,202);
    A3->attack(-239,-2);
    A4->attack(136,-242);

    int a1;
    for(a1=1;A1->isLive()==1 ;++a1)
    {
        A1->nextTurn();
    }
    std::cout<<"Attacking rocket test 1:"<<std::endl<<"hit after: "<<a1<<" turns."<<std::endl;

    int a2;
    for(a2=1;A2->isLive()==1 ;++a2)
    {
        A2->nextTurn();
    }
    std::cout<<"Attacking rocket test 2:"<<std::endl<<"hit after: "<<a2<<" turns."<<std::endl;

    int a3;
    for(a3=1;A3->isLive()==1 ;++a3)
    {
        A3->nextTurn();
    }
    std::cout<<"Attacking rocket test 3:"<<std::endl<<"hit after: "<<a3<<" turns."<<std::endl;

    int a4;
    for(a4=1;A4->isLive()==1 ;++a4)
    {
        A4->nextTurn();
    }
    std::cout<<"Attacking rocket test 4:"<<std::endl<<"hit after: "<<a4<<" turns."<<std::endl;

    delete launcher;
    return 1;
}
