#include "MyAttRocket.h"
int MyAttRocket::isGrounded()
{
    if(pos->getX()==0 && pos->getY()==0 && isLive()==1)
        return 1;
    else
        return 0;
}
void MyAttRocket::nextTurn()
{
    if(live==0) return;
    if(isTarget()==0) return;
    disT=mySqrt(pos, target);
    if(disT<vel)
    {
        disT=0;
        live=0;
    }
    else
    {
        changeDir(pos, target);
        go(direction, vel);
        disT=mySqrt(pos, target);
    }
    return;
}

int MyAttRocket::attack(Position* xy)
{
    if(xy==NULL || live==0) return 0;
    target =new Position;
    target=xy;
    disT=mySqrt(pos, target);
    changeDir(pos, target);
    return 1;
}

int MyAttRocket::attack(int xx, int yy)
{
    target =new Position;
    target->setX(xx);
    target->setY(yy);
    disT=mySqrt(pos, target);
    changeDir(pos, target);
    return 1;
}

bool MyAttRocket::isTarget()
{
    if(target==NULL || live==0) return 0;
    else return 1;
}
