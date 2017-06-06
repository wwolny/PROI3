#include "Singleton.h"

Singleton::Singleton()
{

}

Singleton::~Singleton()
{
    launchList.clear();
}

Singleton::Singleton(Singleton const&)
{
    delete this;
}

void Singleton::operator=(Singleton const&)
{
    delete this;
}

Launcher* Singleton::getLauncher()
{
    Launcher* newLaunch;
    newLaunch= new Launcher;
    launchList.push_back(newLaunch);
    return newLaunch;
}

int Singleton::delLauncher(Launcher* delLaunch)
{
    if(delLaunch==NULL) return 0;
    delete delLaunch;
    return 1;
}

int Singleton::unChoose(Launcher* launch, Rocket* rocket)
{
    if(launch==NULL) return 0;
    if(launch->unChoose(rocket)==0) return 0;
    else return 1;
}

MyDefRocket* Singleton::getDefR(Launcher* launch)
{
    if(launch==NULL) return 0;
    return launch->getDefR();
}
OpponentRocket* Singleton::getOpR(Launcher* launch)
{
    if(launch==NULL) return 0;
    return launch->getOpR();
}
MyAttRocket* Singleton::getAtR(Launcher* launch)
{
    if(launch==NULL) return 0;
    return launch->getAtR();
}
int Singleton::addOpR(Launcher* launch, int xx, int yy)
{
    if(launch==NULL) return 0;
    return launch->addOpR(xx, yy);
}
int Singleton::addDfR(Launcher* launch, int vv)
{
    if(launch==NULL) return 0;
    return launch->addDfR(vv);
}
int Singleton::addAtR(Launcher* launch, int vv)
{
    if(launch==NULL) return 0;
    return launch->addAtR(vv);
}
int Singleton::delOpR(Launcher* launch, OpponentRocket* delrocket)
{
    if(launch==NULL) return 0;
    return launch->delOpR(delrocket);
}
int Singleton::delDfR(Launcher* launch, MyDefRocket* delrocket)
{
    if(launch==NULL) return 0;
    return launch->delDfR(delrocket);
}
int Singleton::delAtR(Launcher* launch, MyAttRocket* delrocket)
{
    if(launch==NULL) return 0;
    return launch->delAtR(delrocket);
}
bool Singleton::isRInBase(Launcher* launch, Rocket* rock)
{
    if(launch==NULL) return 0;
    return launch->isRInBase(rock);
}
