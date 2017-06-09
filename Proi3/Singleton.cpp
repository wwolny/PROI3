#include "Singleton.h"
Singleton* Singleton::init=NULL;

Singleton::Singleton()
{
    launch = new Launcher;
}
Singleton* Singleton::Init(){
    if(init == NULL)
    {
        init= new Singleton();
    }
    return init;
}

Singleton::~Singleton()
{
    delete launch;
}

Singleton::Singleton(Singleton const&)
{
    delete this;
}

void Singleton::operator=(Singleton const&)
{
    delete this;
}
int Singleton::unChoose(Rocket* rocket)
{
    if(launch==NULL) return 0;
    if(launch->unChoose(rocket)==0) return 0;
    else return 1;
}

MyDefRocket* Singleton::getDefR()
{
    if(launch==NULL) return 0;
    return launch->getDefR();
}
OpponentRocket* Singleton::getOpR()
{
    if(launch==NULL) return 0;
    return launch->getOpR();
}
MyAttRocket* Singleton::getAtR()
{
    if(launch==NULL) return 0;
    return launch->getAtR();
}
int Singleton::addOpR(int xx, int yy)
{
    if(launch==NULL) return 0;
    return launch->addOpR(xx, yy);
}
int Singleton::addDfR(int vv)
{
    if(launch==NULL) return 0;
    return launch->addDfR(vv);
}
int Singleton::addAtR(int vv)
{
    if(launch==NULL) return 0;
    return launch->addAtR(vv);
}
int Singleton::delOpR(OpponentRocket* delrocket)
{
    if(launch==NULL) return 0;
    return launch->delOpR(delrocket);
}
int Singleton::delDfR(MyDefRocket* delrocket)
{
    if(launch==NULL) return 0;
    return launch->delDfR(delrocket);
}
int Singleton::delAtR(MyAttRocket* delrocket)
{
    if(launch==NULL) return 0;
    return launch->delAtR(delrocket);
}
bool Singleton::isRInBase(Rocket* rock)
{
    if(launch==NULL) return 0;
    return launch->isRInBase(rock);
}
