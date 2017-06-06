#ifndef MYATTROCKET_H
#define MYATTROCKET_H
#include <iostream>
#include "Position.h"
#include "Rocket.h"


class MyAttRocket : public Rocket
{
    public:
        int attack(Position* xy);
        int attack(int xx, int yy);
        void nextTurn();
        bool isTarget();
        bool isLive(){ return live; }
        int isGrounded();
        MyAttRocket(std::string newName="Attacking", int velocity=10) : Rocket()
        {
            target = NULL;
            setType(1);
            setPos(0,0);
            setVel(velocity);
            target=0;
            live=1;
            name=newName;
        }
        virtual ~MyAttRocket()
        {
            if(target!=NULL)
            delete target;
        }
    private:
        int disT;//distance to target
        Position* target;//if there is target 1, if there is no target 0
        bool live;
};

#endif // MYATTROCKET_H
