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
#include "Singleton.h"


class Menu
{
    public:
        Menu();
        ~Menu();
        void startMenu();
    private:
        int writeFurnAll();
        void orderWrite(node<int, Furniture>* start);
        void options();
        void writeFurn(int key);
        int writeAllFurnFile();
        int creFurn();
        int editFurn();
        int delFurn();
        void getchar();
        int Success();
        int Fail();
        int isIntOK();
        Catalog *MyCatalog;

};

#endif // MENU_H
