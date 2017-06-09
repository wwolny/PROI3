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
        int unChoose(Rocket* rocket);
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
    public:
        static Singleton* Init();
        static Singleton& getInstance()
        {
            static Singleton instance;
            return instance;
        }
        ~Singleton();
        Singleton(Singleton const&);
        void operator=(Singleton const&);
    private:
        static Singleton* init;
        Singleton();
        Launcher* launch;
};

#endif // SINGLETON_H
