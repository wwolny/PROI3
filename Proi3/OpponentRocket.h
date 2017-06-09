#ifndef OPPONENTROCKET_H
#define OPPONENTROCKET_H
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include "Position.h"
#include "Rocket.h"

class OpponentRocket :public Rocket
{
    public:
        void startR(int x=155, int y=156);
        virtual void nextTurn();
        int newDir();
        virtual int velUpdate();
        OpponentRocket(std::string newName="Unknown", int x=255, int y=0) : Rocket(newName, x,y)
        {
            setType(-1);
            std::srand((unsigned)time(NULL));
            startR();
            start=0;
            chosen=0;
            name=newName;
            direction=0;
        }
        virtual ~OpponentRocket() {}
        OpponentRocket(const OpponentRocket &tmp);
        virtual OpponentRocket &operator=(const OpponentRocket &tmp);
    private:
        bool start;
        static const int MAXVEL=20;
};

#endif // OPPONENTROCKET_H
