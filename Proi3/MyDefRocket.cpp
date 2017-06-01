#include "MyDefRocket.h"
int MyDefRocket::isGrounded()
{
    if(pos->getX()==0 && pos->getY()==0 && isLive()==1)
        return 1;
    else
        return 0;
}
int MyDefRocket::catchR(OpponentRocket* Target)
{
    if(Target==NULL) return 0;
    if(Target->isLive()==0) return 0;
    if(prevPosT->getX()==0 && prevPosT->getY()==0 && posT->getX()==0 && posT->getY()==0)
    {
        posT->setX(Target->getXPos());
        posT->setY(Target->getYPos());
    }
    else if(prevPosT->getX()==0 && prevPosT->getY()==0)
    {
        prevPosT->setX(posT->getX());
        prevPosT->setY(posT->getY());
        posT->setX(Target->getXPos());
        posT->setY(Target->getYPos());
    }
    else
    {
        prevPosT->setX(posT->getX());
        prevPosT->setY(posT->getY());
        posT->setX(Target->getXPos());
        posT->setY(Target->getYPos());
        velT=mySqrt(posT, prevPosT);
    }

    disT=mySqrt(pos, posT);
    if(disT<vel)
    {
        Target->kill();
        live=0;
        return 1;
    }
    changeDir(pos, posT);
    go(direction, vel);
    return 1;
}
