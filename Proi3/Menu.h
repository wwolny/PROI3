#ifndef MENU_H
#define MENU_H
#include <iostream>
#include "Position.h"
#include "Rocket.h"
#include "Test.h"
#include "MyAttRocket.h"
#include "MyDefRocket.h"
#include "OpponentRocket.h"
#include "Launcher.h"


class Menu
{
    public:
        Menu();
        ~Menu();
        void startMenu();
    private:
        int creOpR();
        int creAtR();
        int creDfR();
        int attackR();
        int attackT();
        int nextTurn();
        void writeOpRs();
        void writeAtRs();
        void writeDfRs();
        void options();
        void getchar();
        int Success();
        int Fail();
        int isIntOK();
        Launcher* L;
};

#endif // MENU_H
