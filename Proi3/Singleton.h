#ifndef SINGLETON_H
#define SINGLETON_H
#include <iostream>
#include <list>
#include "Position.h"
#include "Rocket.h"
#include "OpponentRocket.h"
#include "MyAttRocket.h"
#include "MyDefRocket.h"
#include "Launcher.h"

class Singleton
{
    public:
        Launcher* getLauncher(); //creates new launcher
        int delLauncher(Launcher* delLaunch);
        int unChoose(Launcher* launch, Rocket* rocket);
        MyDefRocket* getDefR(Launcher* launch);
        OpponentRocket* getOpR(Launcher* launch);
        MyAttRocket* getAtR(Launcher* launch);
        int addOpR(Launcher* launch, int xx=255, int yy=0);
        int addDfR(Launcher* launch, int vv=10);
        int addAtR(Launcher* launch, int vv=10);
        int delOpR(Launcher* launch, OpponentRocket* delrocket);
        int delDfR(Launcher* launch, MyDefRocket* delrocket);
        int delAtR(Launcher* launch, MyAttRocket* delrocket);
        bool isRInBase(Launcher* launch, Rocket* rock);
    public:
        static Singleton& getInstance()
        {
            static Singleton instance;
            return instance;
        }
        ~Singleton();
        Singleton(Singleton const&);
        void operator=(Singleton const&);
    private:
        Singleton();
        std::list<Launcher*> launchList;
};

#endif // SINGLETON_H
