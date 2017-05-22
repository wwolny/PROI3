#include "Position.h"

Position::Position()
{
    //ctor
}

Position::~Position()
{
    //dtor
}

int Position::setX(int newx)
{
    if(newx>-255 && newx<255)
    {
        this->x=newx;
        return 1;
    }
    return 0;
}
int Position::setY(int newy)
{
    if(newy>-255 && newy<255)
    {
        this->y=newy;
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
