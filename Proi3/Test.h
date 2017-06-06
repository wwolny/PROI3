#ifndef TEST_H
#define TEST_H
#include <iostream>
#include "Rocket.h"
#include "Position.h"
#include "MyAttRocket.h"
#include "OpponentRocket.h"
#include "MyDefRocket.h"
#include "Launcher.h"
#include "Singleton.h"

class Test
{
    public:
        int rocketTest();
        int OpRocket();
        int DefRocket();
        int AttRocket();
        int Launch();
        Test();
        ~Test();
    private:
        Rocket* tRocket;
        OpponentRocket* ORocket;
};

#endif // TEST_H
