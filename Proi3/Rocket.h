#ifndef ROCKET_H
#define ROCKET_H
#include <iostream>
#include <math.h>
#include "Position.h"

class Rocket
{
    public:
        int changeDir(Position* start, Position* dest);
        int go(double dir, int velo);//go to the place with this direction
        int getXPos(){return pos->getX();}
        int getYPos(){return pos->getY();}
        int getVel() {return vel;}
        int getType() {return type;}
        void setVel(int v);
        double getDir() {return direction;}
        int deltaX();//0-negative, 1 positive/neutral
        int deltaY();//0-negative, 1 positive/neutral
        int setPos(int x, int y);
        double mySqrt(Position* a, Position* b);
        virtual int velUpdate();
        virtual int dirUpdate();//MUST BE CHANGED
        Rocket(const Rocket &tmp);
        Rocket &operator=(const Rocket &tmp);
        Rocket(int x=0, int y=0);
        virtual ~Rocket();
    protected:
        int setType(int t);
        Position *pos;
        Position *lastPos;
        int vel;//velocity based on the two previous positions
        double direction;//direction of the rocket as sin HAVE TO BE CHANGED
        int type;//-1 opponent's, 0 my defending, 1 my attacking, 2- no type
};

#endif // ROCKET_H
