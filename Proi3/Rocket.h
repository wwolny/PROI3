#ifndef ROCKET_H
#define ROCKET_H
#include "Position.h"


class Rocket
{
    public:
        Rocket();
        virtual ~Rocket();
    protected:
        Position pos;
        Position lastPos;
        int vel;//velocity based on the two previous positions
};

#endif // ROCKET_H
