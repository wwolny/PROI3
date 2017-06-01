#ifndef POSITION_H
#define POSITION_H


class Position
{
    public:
        int setX(int newx);
        int setY(int newy);
        int setXY(int xx, int yy);
        int getX();
        int getY();
        int getMax(){ return MAXSIZE;}
        Position(int newx=0, int newy=0): x(newx), y(newy){}
        Position(const Position &tmp);
        Position &operator=(const Position &tmp);
        int operator<(const Position &tmp) const;
        ~Position();
    private:
        int x,y;
        static const int MAXSIZE=256;
};

#endif // POSITION_H
