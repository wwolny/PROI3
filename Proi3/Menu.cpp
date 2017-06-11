#include "Menu.h"

Menu::Menu()
{
    L= new Launcher;
}

Menu::~Menu()
{
    delete L;
}
void Menu::options()
{
    std::cout<<"[c] create opponent rocket"<<std::endl;
    std::cout<<"[r] create attacking rocket"<<std::endl;
    std::cout<<"[e] create defensive rocket"<<std::endl;
    std::cout<<"[s] attack opponent rocket"<<std::endl;
    std::cout<<"[d] attack target"<<std::endl;
    std::cout<<"[f] next turn"<<std::endl;
    std::cout<<"[t] write down all opponent rockets"<<std::endl;
    std::cout<<"[y] write down all defensive rockets"<<std::endl;
    std::cout<<"[u] write down all attacking rockets"<<std::endl;
    std::cout<<"[l] leave menu"<<std::endl;
}
void Menu::startMenu()
{
    char Next;
    while(1)
    {
        this->options();
        std::cin>>Next;
        std::cin.ignore(1000,'\n');
        system("clear");
        switch (Next)
        {
            case 'c':
                this->creOpR();
                break;
            case 's':
                this->attackR();
                break;
            case 'e':
                this->creDfR();
                break;
            case 'd':
                this->attackT();
                break;
            case 'r':
                this->creAtR();
                break;
            case 'f':
                this->nextTurn();
                break;
            case 't':
                this->writeOpRs();
                break;
            case 'y':
                this->writeDfRs();
                break;
            case 'u':
                this->writeAtRs();
                break;
            case 'l':
                return;
            default:
                std::cout<<"Bad Input!"<<std::endl;
                break;
        }
    }
}
//--------------------------------------------------
int Menu::creOpR()
{
    OpponentRocket* tmp;
    tmp= new OpponentRocket;
    std::string nn;
    char c; int neg=1;
    int xx=150,yy=150,vv=10;
    std::cout<<"Type name of the rocket: ";
    std::cin>>nn;
    std::cin.ignore(1000,'\n');
    std::cout<<"Type X: ";
    std::cin>>c;
    if(!std::isdigit(c)) return this->Fail();
    std::cin.unget();
    std::cin>>xx;
    if(!isIntOK()) return this->Fail();
    std::cin.ignore(1000,'\n');
    std::cout<<"Type Y: ";
    std::cin>>c;
    if(!std::isdigit(c)) return this->Fail();
    std::cin.unget();
    std::cin>>yy;
    if(!isIntOK()) return this->Fail();
    std::cin.ignore(1000,'\n');
    std::cout<<"Type the velocity: ";
    std::cin>>c;
    if(!std::isdigit(c)) return this->Fail();
    std::cin.unget();
    std::cin>>vv;
    if(!isIntOK()) return this->Fail();
    std::cin.ignore(1000,'\n');
    if(!(tmp->setPos(xx,yy)))
    {
        delete tmp;
        return this->Fail();
    }
    L->addOpR();
    tmp=L->getOpR();
    tmp->setPos(xx, yy);
    tmp->setVel(vv);
    tmp->setName(nn);
    return this->Success();
}

int Menu::creDfR()
{
    MyDefRocket* tmp;
    std::string nn;
    char c;
    int vv=10;
    std::cout<<"Type name of the rocket: ";
    std::cin>>nn;
    std::cin.ignore(1000,'\n');
    std::cout<<"Type the velocity: ";
    std::cin>>c;
    if(!std::isdigit(c)) return this->Fail();
    std::cin.unget();
    std::cin>>vv;
    if(!isIntOK()) return this->Fail();
    std::cin.ignore(1000,'\n');
    L->addDfR();
    tmp=L->getDefR();
    tmp->setVel(vv);
    tmp->setName(nn);
    return this->Success();
}

int Menu::creAtR()
{
    MyAttRocket* tmp;
    std::string nn;
    char c;
    int vv=10;
    std::cout<<"Type name of the rocket: ";
    std::cin>>nn;
    std::cin.ignore(1000,'\n');
    std::cout<<"Type the velocity: ";
    std::cin>>c;
    if(!std::isdigit(c)) return this->Fail();
    std::cin.unget();
    std::cin>>vv;
    if(!isIntOK()) return this->Fail();
    std::cin.ignore(1000,'\n');
    L->addAtR();
    tmp=L->getAtR();
    tmp->setVel(vv);
    tmp->setName(nn);
    return this->Success();
}
void Menu::writeOpRs()
{
    OpponentRocket* tmp;
    for(L->beginIOR(); *L->itOR != L->endOR(); L->itOR++)
    {
        tmp=*L->itOR;
        std::cout<<"name: "<<tmp->getName()<<" ("<<tmp->getXPos()<<","<<tmp->getYPos()<<")     velocity:"<<tmp->getVel();
        if(tmp->isLive()==1)    std::cout<<"    Alive"<<std::endl;
        else std::cout<<"    Destroyed"<<std::endl;
    }
    return;
}

void Menu::writeDfRs()
{
    MyDefRocket* tmp;
    for(L->beginIDR(); *L->itDR != L->endDR(); L->itDR++)
    {
        tmp=*L->itDR;
        std::cout<<"name: "<<tmp->getName()<<" ("<<tmp->getXPos()<<","<<tmp->getYPos()<<")     velocity:"<<tmp->getVel();
        if(tmp->isLive()==1)    std::cout<<"    Alive"<<std::endl;
        else std::cout<<"    Destroyed"<<std::endl;
    }
    return;
}

void Menu::writeAtRs()
{
    MyAttRocket* tmp;
    for(L->beginIAR(); *L->itAR != L->endAR(); L->itAR++)
    {
        tmp=*L->itAR;
        std::cout<<"name: "<<tmp->getName()<<" ("<<tmp->getXPos()<<","<<tmp->getYPos()<<")     velocity:"<<tmp->getVel();
        if(tmp->isLive()==1)    std::cout<<"    Alive"<<std::endl;
        else std::cout<<"    Destroyed"<<std::endl;
    }
    return;
}

int Menu::attackR()
{
    MyDefRocket* tmpD;
    OpponentRocket* tmpO;
    writeDfRs();
    std::string nn;
    std::cout<<"type exactly the name of the rocket that should attack:";
    std::cin>>nn;
    std::cin.ignore(1000,'\n');
    tmpD=L->getDfR(nn);
    if(tmpD==NULL) return Fail();
    writeOpRs();
    std::cout<<"type exactly the name of the rocket that should be attacked:";
    std::cin>>nn;
    std::cin.ignore(1000,'\n');
    tmpO=L->getOpR(nn);
    if(tmpO==NULL) return Fail();
    tmpD->catchR(tmpO);
    return Success();
}
int Menu::attackT()
{
    MyAttRocket* tmpA;
    char c;
    writeAtRs();
    std::string nn;
    std::cout<<"type exactly the name of the rocket that should attack:";
    std::cin>>nn;
    std::cin.ignore(1000,'\n');
    tmpA=L->getAtR(nn);
    if(tmpA==NULL) return Fail();
    int xx, yy;
    std::cout<<"Type X: ";
    std::cin>>c;
    if(!std::isdigit(c)) return this->Fail();
    std::cin.unget();
    std::cin>>xx;
    if(!isIntOK()) return this->Fail();
    std::cin.ignore(1000,'\n');
    std::cout<<"Type Y: ";
    std::cin>>c;
    if(!std::isdigit(c)) return this->Fail();
    std::cin.unget();
    std::cin>>yy;
    if(!isIntOK()) return this->Fail();
    std::cin.ignore(1000,'\n');
    if(tmpA->attack(xx, yy)==0) return Fail();
    return Success();
}
int Menu::nextTurn()
{
    L->nextTurn();
}
//-----------------------
void Menu::getchar()
{
    std::cin.get();
}
int Menu::Success()
{
    std::cout<<"Success!"<<std::endl;
    getchar();
    return 1;
}
int Menu::Fail()
{
    std::cout<<"Fail!"<<std::endl;
    getchar();
    return 0;
}
int Menu::isIntOK()//if fail return 0
{
    if(std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        return this->Fail();
    }
    else return 1;
}
