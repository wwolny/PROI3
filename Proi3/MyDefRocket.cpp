#include "MyDefRocket.h"
MyDefRocket::MyDefRocket(const MyDefRocket &tmp)
{
    this->pos=tmp.pos;
    this->lastPos=tmp.lastPos;
    this->vel=tmp.vel;
    this->direction=tmp.direction;
    this->type=tmp.type;
    this->chosen=tmp.chosen;
    this->name=tmp.name;
    this->live=tmp.live;
    this->disT=tmp.disT;
    this->posT=tmp.posT;
    this->prevPosT=tmp.prevPosT;
    this->velT=tmp.velT;
    this->OpRocket=tmp.OpRocket;
}

MyDefRocket& MyDefRocket::operator=(const MyDefRocket &tmp)
{
    this->pos=tmp.pos;
    this->lastPos=tmp.lastPos;
    this->vel=tmp.vel;
    this->direction=tmp.direction;
    this->type=tmp.type;
    this->chosen=tmp.chosen;
    this->name=tmp.name;
    this->live=tmp.live;
    this->disT=tmp.disT;
    this->posT=tmp.posT;
    this->prevPosT=tmp.prevPosT;
    this->velT=tmp.velT;
    this->OpRocket=tmp.OpRocket;
    return *this;
}
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
    OpRocket=Target;
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
void MyDefRocket::nextTurn()
{
    if(prevPosT->getX()==0 && prevPosT->getY()==0 && posT->getX()==0 && posT->getY()==0)
    {
        posT->setX(OpRocket->getXPos());
        posT->setY(OpRocket->getYPos());
    }
    else if(prevPosT->getX()==0 && prevPosT->getY()==0)
    {
        prevPosT->setX(posT->getX());
        prevPosT->setY(posT->getY());
        posT->setX(OpRocket->getXPos());
        posT->setY(OpRocket->getYPos());
    }
    else
    {
        prevPosT->setX(posT->getX());
        prevPosT->setY(posT->getY());
        posT->setX(OpRocket->getXPos());
        posT->setY(OpRocket->getYPos());
        velT=mySqrt(posT, prevPosT);
    }

    disT=mySqrt(pos, posT);
    if(disT<vel)
    {
        OpRocket->kill();
        live=0;
        return;
    }
    changeDir(pos, posT);
    go(direction, vel);
}
