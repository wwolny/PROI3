#ifndef OPPONENTROCKET_H
#define OPPONENTROCKET_H
#include <iostream>
#include <cstdlib>
#include <cmath>
#include "Position.h"
#include "Rocket.h"

class OpponentRocket :public Rocket
{
    public:
        void startR(int x=155, int y=156);
        void nextTurn();
        void kill();
        int isLive() {return live;}
        int newDir();
        bool getChosen() {return chosen;}
        void setChosen(bool cc){chosen=cc;}
        virtual int velUpdate();
        OpponentRocket(int x=255, int y=0) : Rocket(x,y)
        {
            setType(-1);
            srand((unsigned)time(NULL));
            startR();
            start=0;
            chosen=0;
            live=1;
        }
        virtual ~OpponentRocket() {}
    private:
        bool start;
        static const int MAXVEL=20;
        bool live;//Is it still alive?
        bool chosen;//in launcher

};

#endif // OPPONENTROCKET_H
