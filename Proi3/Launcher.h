#ifndef LAUNCHER_H
#define LAUNCHER_H
#include <iostream>
#include <list>
#include "Position.h"
#include "Rocket.h"
#include "OpponentRocket.h"
#include "MyAttRocket.h"
#include "MyDefRocket.h"

class Launcher
{
    public:
        MyDefRocket* getDefR();
        OpponentRocket* getOpR();
        MyAttRocket* getAtR();
        int addOpR(int xx=255, int yy=0);
        int addDfR(int vv=10);
        int addAtR(int vv=10);
        int delOpR(OpponentRocket* delrocket);
        int delDfR(MyDefRocket* delrocket);
        int delAtR(MyAttRocket* delrocket);
        bool isRInBase(Rocket* rock);
        Launcher();
        ~Launcher();
    private:
        std::list<OpponentRocket*> OpRs;
        std::list<OpponentRocket*>::iterator itOR;
        std::list<MyAttRocket*> AtRs;
        std::list<MyAttRocket*>::iterator itAR;
        std::list<MyDefRocket*> DfRs;
        std::list<MyDefRocket*>::iterator itDR;
};

#endif // LAUNCHER_H
