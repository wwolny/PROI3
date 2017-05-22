#ifndef POSITION_H
#define POSITION_H


class Position
{
    public:
        void setX(int newx);
        void setY(int newy);
        int getX();
        int getY();
        Position();
        ~Position();
    private:
        int x,y;
};

#endif // POSITION_H
