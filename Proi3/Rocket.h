#ifndef ROCKET_H
#define ROCKET_H
#include <iostream>
#include <string.h>
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
        bool getChosen() {return chosen;}
        void setChosen(bool cc){chosen=cc;}
        void setVel(int v);
        void setName(std::string newName) {if(name!="") name=newName;}
        double getDir() {return direction;}
        int deltaX();//0-negative, 1 positive/neutral
        int deltaY();//0-negative, 1 positive/neutral
        int setPos(int x, int y);
        double mySqrt(Position* a, Position* b);
        virtual int velUpdate();
        virtual int dirUpdate();//MUST BE CHANGED
        Rocket(const Rocket &tmp);
        Rocket &operator=(const Rocket &tmp);
        Rocket(std::string newName="Unknown", int x=0, int y=0);
        virtual ~Rocket();
    protected:
        int setType(int t);
        Position *pos;
        Position *lastPos;
        int vel;//velocity based on the two previous positions
        double direction;//direction of the rocket as sin HAVE TO BE CHANGED
        int type;//-1 opponent's, 0 my defending, 1 my attacking, 2- no type
        bool chosen;//in launcher
        std::string name;

};

#endif // ROCKET_H
