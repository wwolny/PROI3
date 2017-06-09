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
        virtual void nextTurn();
        bool isTarget();
        int isGrounded();
        MyAttRocket(std::string newName="Attacking", int velocity=10) : Rocket()
        {
            target = NULL;
            setType(1);
            setPos(0,0);
            setVel(velocity);
            name=newName;
            disT=0;
        }
        virtual ~MyAttRocket()
        {
            if(target!=NULL)
            delete target;
        }
        MyAttRocket(const MyAttRocket &tmp);
        virtual MyAttRocket &operator=(const MyAttRocket &tmp);
    private:
        int disT;//distance to target
        Position* target;//if there is target 1, if there is no target 0
};

#endif // MYATTROCKET_H
