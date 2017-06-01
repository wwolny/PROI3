#ifndef MYDEFROCKET_H
#define MYDEFROCKET_H
#include <iostream>
#include "Position.h"
#include "Rocket.h"
#include "OpponentRocket.h"

class MyDefRocket : public Rocket
{
    public:
        int catchR(OpponentRocket* Target);
        int isGrounded();
        bool isLive(){ return live; }
        MyDefRocket(int velocity=10) : Rocket()
        {
            setType(0);
            setPos(0,0);
            live=1;
            vel=velocity;
            posT=new Position;
            prevPosT=new Position;
            posT->setX(0);
            posT->setY(0);
            prevPosT->setX(0);
            prevPosT->setY(0);
        }
        virtual ~MyDefRocket()
        {
            delete posT;
            delete prevPosT;
        }
    private:
        Position* prevPosT;//previous target position
        Position* posT;//aktual target position
        int velT;//target's velocity
        double disT;//distance to Target
        bool live;
};

#endif // MYDEFROCKET_H
