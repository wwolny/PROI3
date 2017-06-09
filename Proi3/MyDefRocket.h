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
        virtual void nextTurn();
        bool isLive(){ return live; }
        MyDefRocket(std::string newName="Defensvie", int velocity=10) : Rocket(newName)
        {
            setType(0);
            setPos(0,0);
            vel=velocity;
            name=newName;
            posT=new Position;
            prevPosT=new Position;
            posT->setX(0);
            posT->setY(0);
            prevPosT->setX(0);
            prevPosT->setY(0);
            disT=0;
            velT=0;
            OpRocket=NULL;
        }
        virtual ~MyDefRocket()
        {
            delete posT;
            delete prevPosT;
        }
        MyDefRocket(const MyDefRocket &tmp);
        virtual MyDefRocket &operator=(const MyDefRocket &tmp);
    private:
        Position* prevPosT;//previous target position
        Position* posT;//aktual target position
        int velT;//target's velocity
        double disT;//distance to Target
        OpponentRocket* OpRocket;
};

#endif // MYDEFROCKET_H
