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
        int nextTurn();
        std::list<OpponentRocket*>::iterator itOR;
        std::list<MyAttRocket*>::iterator itAR;
        std::list<MyDefRocket*>::iterator itDR;
        int getORsize() {return OpRs.size();}
        int getDRsize() {return DfRs.size();}
        int getARsize() {return AtRs.size();}
        void beginIOR() {itOR=OpRs.begin();}
        void beginIDR() {itDR=DfRs.begin();}
        void beginIAR() {itAR=AtRs.begin();}
        OpponentRocket* endOR() {return *OpRs.end();}
        MyDefRocket* endDR() {return *DfRs.end();}
        MyAttRocket* endAR() {return *AtRs.end();}
        int unChoose(Rocket* rocket);
        MyDefRocket* getDefR();
        MyDefRocket* getDfR(std:: string nn);
        OpponentRocket* getOpR();
        OpponentRocket* getOpR(std::string nn);
        MyAttRocket* getAtR();
        MyAttRocket* getAtR(std::string nn);
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
        std::list<MyAttRocket*> AtRs;
        std::list<MyDefRocket*> DfRs;
};

#endif // LAUNCHER_H
