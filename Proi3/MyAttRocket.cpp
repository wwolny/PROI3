#include "MyAttRocket.h"
MyAttRocket::MyAttRocket(const MyAttRocket &tmp)
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
    this->target=tmp.target;
}

MyAttRocket& MyAttRocket::operator=(const MyAttRocket &tmp)
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
    this->target=tmp.target;
    return *this;
}
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
        this->live=0;
        setPos(target->getX(), target->getY());
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
    if(target==NULL) target =new Position;
    target->setX(xy->getX());
    target->setY(xy->getY());
    disT=mySqrt(pos, target);
    changeDir(pos, target);
    return 1;
}

int MyAttRocket::attack(int xx, int yy)
{
    if(target==NULL) target =new Position;
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
