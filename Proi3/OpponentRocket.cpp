#include "OpponentRocket.h"

int OpponentRocket::velUpdate()
{
    vel=(std::rand()%MAXVEL)+1;
    return 1;
}

int OpponentRocket::newDir()
{
    if(live==0) return 0;
    double tmp=0.0;
    tmp=rand()%100;
    tmp=tmp/100;
    direction=(rand()%4)+tmp;
    if(direction==0.0) newDir();
    return 1;
}

void OpponentRocket::nextTurn()
{
    if(live==0) return ;
    if(start==0) startR();
    if(getXPos()==0 && getYPos()==0)
    {
        setPos(255, 0);
        newDir();
        velUpdate();
        return;
    }
    else
    {
        int y=0,x=0;
        double dir=getDir();
        if(dir<1)
        {
            y=dir*getVel();//delta y
            x=(1.0-dir)*getVel();//delya x
            y=getYPos()+y;
            x=getXPos()+x;
        }
        else if(dir<2)//x do poprawy
        {
            dir=dir-1.0;
            x=dir*getVel();
            y=(1.0-dir)*getVel();
            y=getYPos()+y;
            x=getXPos()-x;
        }
        else if(dir<3)//y do poprawy
        {
            dir=dir-2.0;
            y=dir*getVel();//delta y
            x=(1.0-dir)*getVel();//delya x
            y=getYPos()-y;
            x=getXPos()-x;
        }
        else if(dir<4)
        {
            dir=dir-3.0;
            x=dir*getVel();
            y=(1.0-dir)*getVel();
            y=getYPos()-y;
            x=getXPos()+x;
        }
        else return;

        if(x>pos->getMax() || x<-(pos->getMax()) || y>pos->getMax() || y<-(pos->getMax()))
        {
            setPos(pos->getMax()-1, 0);
            newDir();
            velUpdate();
            nextTurn();
        }
        else if(x==0 && y==0)
        {
            //THE END
        }
        else setPos(x,y);

    }
}

void OpponentRocket::startR(int x, int y)
{
    setPos(x, y);
    velUpdate();
    newDir();
    start=1;
    live=1;
}

void OpponentRocket::kill()
{
    live=0;
}
