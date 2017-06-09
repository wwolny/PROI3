#include "Launcher.h"

Launcher::Launcher()
{
}

Launcher::~Launcher()
{
    MyDefRocket* tmpD;
    for(itDR=DfRs.begin();itDR!=DfRs.end();itDR++)
    {
        tmpD=*itDR;
        delete tmpD;
    }
    MyAttRocket* tmpA;
    for(itAR=AtRs.begin();itAR!=AtRs.end();itAR++)
    {
        tmpA=*itAR;
        delete tmpA;
    }
    OpponentRocket* tmpO;
    for(itOR=OpRs.begin();itOR!=OpRs.end();itOR++)
    {
        tmpO=*itOR;
        delete tmpO;
    }
    OpRs.clear();
    AtRs.clear();
    DfRs.clear();
}
int Launcher::nextTurn()
{
    MyAttRocket* tmpA;
    MyDefRocket* tmpD;
    OpponentRocket* tmpO;
    for(itAR=AtRs.begin();itAR!=AtRs.end();itAR++)
    {
        tmpA=*itAR;
        tmpA->nextTurn();
    }
    for(itOR=OpRs.begin();itOR!=OpRs.end();itOR++)
    {
        tmpO=*itOR;
        tmpO->nextTurn();
    }
    for(itDR=DfRs.begin();itDR!=DfRs.end();itDR++)
    {
        tmpD=*itDR;
        tmpD->nextTurn();
    }
    return 1;
}
int Launcher::unChoose(Rocket* rocket)
{
    if(rocket==NULL)
    {
        std::string sms="No Rocket Given!";
        throw sms;
        return 0;
    }
    rocket->setChosen(0);
    return 1;
}

int Launcher::addOpR(int xx, int yy)
{
    OpponentRocket* newrocket;
    newrocket= new OpponentRocket;
    if(xx==0 && yy==0)
    {
        std::string sms="You can't put OpR on (0,0)!";
        throw sms;
        return 0;
    }
    newrocket->setPos(xx, yy);
    OpRs.push_back(newrocket);
    return 1;
}
int Launcher::addDfR(int vv)
{
    MyDefRocket* newrocket;
    newrocket= new MyDefRocket;
    if(vv<=0)
    {
        std::string sms="The value of velocity must be positive!";
        throw sms;
        return 0;
    }
    newrocket->setVel(vv);
    DfRs.push_back(newrocket);
    return 1;
}
int Launcher::addAtR(int vv)
{
    MyAttRocket* newrocket;
    newrocket= new MyAttRocket;
    if(vv<=0)
    {
        std::string sms="The value of velocity must be positive!";
        throw sms;
        return 0;
    }
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
    std::string sms="There is no such a rocket!";
    throw sms;
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
    std::string sms="There is no such a rocket!";
    throw sms;
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
    std::string sms="There is no such a rocket!";
    throw sms;
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
MyDefRocket* Launcher::getDfR(std::string nn)
{
    MyDefRocket* tmp;
    for(itDR=DfRs.begin();itDR!=DfRs.end();itDR++)
    {
        tmp=*itDR;
        if(tmp->getName()==nn)
        {
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
MyAttRocket* Launcher::getAtR(std::string nn)
{
    MyAttRocket* tmp;
    for(itAR=AtRs.begin();itAR!=AtRs.end();itAR++)
    {
        tmp=*itAR;
        if(tmp->getName()==nn)
        {
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
OpponentRocket* Launcher::getOpR(std::string nn)
{
    OpponentRocket* tmp;
    for(itOR=OpRs.begin();itOR!=OpRs.end();itOR++)
    {
        tmp=*itOR;
        if(tmp->getName()==nn)
        {
            return tmp;
        }
    }
    return NULL;
}
