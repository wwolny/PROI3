#include "Position.h"

Position::~Position()
{}

Position::Position(const Position &tmp)
{
    this->x=tmp.x;
    this->y=tmp.y;
}

Position& Position::operator=(const Position &tmp)
{
   this->x=tmp.x;
   this->y=tmp.y;
   return *this;
}

int Position::operator<(const Position &tmp) const
{
    if(this->x < tmp.x) return 1;
    if(this->y < tmp.y) return 1;
    return 0;
}
int Position::setX(int newx)
{
    if(newx>-MAXSIZE && newx<MAXSIZE)
    {
        x=newx;
        return 1;
    }
    return 0;
}
int Position::setY(int newy)
{
    if(newy>-MAXSIZE && newy<MAXSIZE)
    {
        y=newy;
        return 1;
    }
    return 0;
}
int Position::getX()
{
    return x;
}
int Position::getY()
{
    return y;
}
int Position::setXY(int xx, int yy)
{
    if(xx>-MAXSIZE && xx<MAXSIZE)
    {
        x=xx;
    }

    if(yy>-MAXSIZE && yy<MAXSIZE)
    {
        y=yy;
        return 1;
    }
    return 0;
}
