#include "Launcher.h"

Launcher::Launcher()
{
}

Launcher::~Launcher()
{
    OpRs.clear();
    AtRs.clear();
    DfRs.clear();
}

int Launcher::unChoose(Rocket* rocket)
{
    if(rocket==NULL) return 0;
    rocket->setChosen(0);
    return 1;
}

int Launcher::addOpR(int xx, int yy)
{
    OpponentRocket* newrocket;
    newrocket= new OpponentRocket;
    if(xx==0 && yy==0) return 0;
    newrocket->setPos(xx, yy);
    OpRs.push_back(newrocket);
    return 1;
}
int Launcher::addDfR(int vv)
{
    MyDefRocket* newrocket;
    newrocket= new MyDefRocket;
    if(vv<=0) return 0;
    newrocket->setVel(vv);
    DfRs.push_back(newrocket);
    return 1;
}
int Launcher::addAtR(int vv)
{
    MyAttRocket* newrocket;
    newrocket= new MyAttRocket;
    if(vv<=0) return 0;
    newrocket->setVel(vv);
    AtRs.push_back(newrocket);
    return 1;
}
int Launcher::delOpR(OpponentRocket* delrocket)
{
    OpponentRocket* tmp;
    for(itOR=OpRs.begin();itOR!=OpRs.end();itOR++)
    {
        tmp=*itOR;
        if(tmp==delrocket)
        {
            OpRs.erase(itOR);
            delete delrocket;
            return 1;
        }
    }
    return 0;
}
int Launcher::delDfR(MyDefRocket* delrocket)
{
    MyDefRocket* tmp;
    for(itDR=DfRs.begin();itDR!=DfRs.end();itDR++)
    {
        tmp=*itDR;
        if(tmp==delrocket)
        {
            DfRs.erase(itDR);
            delete delrocket;
            return 1;
        }
    }
    return 0;
}
int Launcher::delAtR(MyAttRocket* delrocket)
{
    MyAttRocket* tmp;
    for(itAR=AtRs.begin();itAR!=AtRs.end();itAR++)
    {
        tmp=*itAR;
        if(tmp==delrocket)
        {
            AtRs.erase(itAR);
            delete delrocket;
            return 1;
        }
    }
    return 0;
}
bool Launcher::isRInBase(Rocket* rock)
{
    if(rock==NULL) return 0;
    if(rock->getXPos()!=0 || rock->getYPos()!=0)
    {
        return 0;
    }
    MyDefRocket* tmpD;
    for(itDR=DfRs.begin();itDR!=DfRs.end();itDR++)
    {
        tmpD=*itDR;
        if(tmpD==rock)
        {
            return 1;
        }
    }
    MyAttRocket* tmpA;
    for(itAR=AtRs.begin();itAR!=AtRs.end();itAR++)
    {
        tmpA=*itAR;
        if(tmpA==rock)
        {
            return 1;
        }
    }
    return 0;
}

MyDefRocket* Launcher::getDefR()
{
    MyDefRocket* tmp;
    for(itDR=DfRs.begin();itDR!=DfRs.end();itDR++)
    {
        tmp=*itDR;
        if(tmp->isGrounded() && tmp->getChosen()==0)
        {
            tmp->setChosen(1);
            return tmp;
        }
    }
    return NULL;
}
MyAttRocket* Launcher::getAtR()
{
    MyAttRocket* tmp;
    for(itAR=AtRs.begin();itAR!=AtRs.end();itAR++)
    {
        tmp=*itAR;
        if(tmp->isGrounded() && tmp->getChosen()==0)
        {
            tmp->setChosen(1);
            return tmp;
        }
    }
    return NULL;
}

OpponentRocket* Launcher::getOpR()
{
    OpponentRocket* tmp;
    for(itOR=OpRs.begin();itOR!=OpRs.end();itOR++)
    {
        tmp=*itOR;
        if(tmp->isLive() && tmp->getChosen()==0)
        {
            tmp->setChosen(1);
            return tmp;
        }
    }
    return NULL;
}
