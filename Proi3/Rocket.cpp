#include "Rocket.h"
void Rocket::setVel(int v)
{
    if(v>=0) vel=v;
}
int Rocket::go(double dir, int velo)
{
    int y,x;
    if(dir<1)
    {
        y=dir*velo;//delta y
        x=(1.0-dir)*velo;//delya x
        y=getYPos()+y;
        x=getXPos()+x;
    }
    else if(dir<2)
    {
        dir=dir-1.0;
        x=dir*velo;
        y=(1.0-dir)*velo;
        y=getYPos()+y;
        x=getXPos()-x;
    }
    else if(dir<3)
    {
        dir=dir-2.0;
        y=dir*velo;//delta y
        x=(1.0-dir)*velo;//delya x
        y=getYPos()-y;
        x=getXPos()-x;
    }
    else if(dir<4)
    {
        dir=dir-3.0;
        x=dir*velo;
        y=(1.0-dir)*velo;
        y=getYPos()-y;
        x=getXPos()+x;
    }
    else return 0;
    setPos(x,y);
    return 1;
}

int Rocket::changeDir(Position* start, Position* dest)
{
    if (start==NULL || dest==NULL) return 0;
    int x0=start->getX();
    int y0=start->getY();
    int x1=dest->getX();
    int y1=dest->getY();
    int dx=x1-x0;
    int dy=y1-y0;
    int dist=mySqrt(start, dest)+1;
    if(dx>0 && dy>0)
    {
        direction=dy/dist;
    }
    else if(dx<0 && dy>0)
    {
        direction=1+((-1*dx)/dist);
    }
    else if(dx<0 && dy<0)
    {
        direction=2+((-1*dy)/dist);
    }
    else if(dx>0 && dy<0)
    {
        direction=3+(dx/dist);
    }
    return 1;
}

Rocket::Rocket(int x, int y)
{
    pos = new Position;
    lastPos = new Position;
    type=2;
    pos->setX(x);
    pos->setY(y);
    lastPos->setX(0);
    lastPos->setY(0);
    direction=0.0;
}

Rocket::~Rocket()
{
    delete pos;
    delete lastPos;
}

Rocket::Rocket(const Rocket &tmp)
{
    this->pos=tmp.pos;
    this->lastPos=tmp.lastPos;
    this->vel=tmp.vel;
    this->direction=tmp.direction;
}

Rocket& Rocket::operator=(const Rocket &tmp)
{
    this->pos=tmp.pos;
    this->lastPos=tmp.lastPos;
    this->vel=tmp.vel;
    this->direction=tmp.direction;
    return *this;
}

int Rocket::setPos(int x, int y)
{
    if(pos->getX()==0 && pos->getY()==0)
    {
        if(pos->setX(x)==0) return 0;
        if(pos->setY(y)==0) return 0;
        return 1;
    }
    *lastPos=*pos;
    if(pos->setX(x)==0) return 0;
    if(pos->setY(y)==0) return 0;
    return 1;
}

int Rocket::velUpdate()
{
    vel=mySqrt(pos, lastPos);
    return 1;
}

int Rocket::dirUpdate()
{
    if(vel==0)
    {
        direction=0.0;
        return 1;
    }
    if(deltaX()==1 && deltaY()==1)  direction=(pos->getY()-lastPos->getY())/vel;
    else if(deltaX()==0 && deltaY()==1)  direction=1.0+(pos->getY()-lastPos->getY())/vel;
    else if(deltaX()==0 && deltaY()==0)  direction=2.0+(pos->getY()-lastPos->getY())/vel;
    else if(deltaX()==1 && deltaY()==0)  direction=3.0+(pos->getY()-lastPos->getY())/vel;
    return 1;
}

double Rocket::mySqrt(Position* a, Position* b)
{
    if(a==NULL || b==NULL) return -1;
    int dx=a->getX()-b->getX();
    int dy=a->getY()-b->getY();
    return sqrt(dx*dx+dy*dy);
}

int Rocket::deltaX()//1 if positive or neutral, 0 if negative
{
    if(pos->getX()-lastPos->getX()>=0) return 1;
    else return 0;
}

int Rocket::deltaY()//1 if positive or neutral, 0 if negative
{
    if(pos->getY()-lastPos->getY()>=0) return 1;
    else return 0;
}

int Rocket::setType(int t)
{
    if(t==-1 || t==0 || t== 1)
    {
        type=t;
        return 1;
    }
    else
    return 0;
}
