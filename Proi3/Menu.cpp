#include "Menu.h"

Menu::Menu()
{

}

Menu::~Menu()
{
}
void Menu::writeFurn(int key)
{
    Furniture* Furn;
    Furn=MyCatalog->findFurnK(key);
    std::cout<<"Furniture key: "<<key<<std::endl<<"Name: "<<Furn->getName()<<"   Price: ";
    std::cout<<Furn->getPrice()<<"   Mass: "<<Furn->getMass()<<std::endl;
    return;
}
void Menu::options()
{
    std::cout<<"[c] create opponent rocket"<<std::endl;
    std::cout<<"[d] delete opponent rocket"<<std::endl;
    std::cout<<"[e] create defensive rocket"<<std::endl;
    std::cout<<"[w] delete defensive rocket"<<std::endl;
    std::cout<<"[a] create attacking rocket"<<std::endl;
    std::cout<<"[z] delete attacking rocket"<<std::endl;
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
                this->creFurn();
                break;
            case 'd':
                this->delFurn();
                break;
            case 'e':
                this->editFurn();
                break;
            case 't':
                this->writeFurnAll();
                break;
            case 'f':
                this->writeAllFurnFile();
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
int Menu::creFurn()
{
    char c;
    std::string name="";
    int price=0, mass=0, key=0;
    std::cout<<"Type name of Furniture: ";
    std::cin>>name;
    std::cin.ignore(1000,'\n');
    std::cout<<"Type key of furniture: ";
    std::cin>>c;
    if(!std::isdigit(c))    return this->Fail();
    std::cin.unget();
    std::cin>>key;
    if(!isIntOK())      return this->Fail();
    std::cin.ignore(1000,'\n');
    std::cout<<"Type price of furniture: ";
    std::cin>>c;
    if(!std::isdigit(c)) return this->Fail();
    std::cin.unget();
    std::cin>>price;
    if(!isIntOK()) return this->Fail();
    std::cin.ignore(1000,'\n');
    std::cout<<"Type mass of furniture: ";
    std::cin>>c;
    if(!std::isdigit(c)) return this->Fail();
    std::cin.unget();
    std::cin>>mass;
    if(!isIntOK()) return this->Fail();
    std::cin.ignore(1000,'\n');
    if(MyCatalog->addFurn(key,name, price, mass)==1)return this->Success();
    else return this->Fail();
}
int Menu::delFurn()
{
    char c;
    int key=-1;
    writeFurnAll();
    std::cout<<"type exactly the KEY of furniture that should be deleted:";
    std::cin>>c;
    if(!std::isdigit(c))    return this->Fail();
    std::cin.unget();
    std::cin>>key;
    if(!isIntOK())      return this->Fail();
    std::cin.ignore(1000,'\n');
    if(MyCatalog->delFurnK(key)==1) return this->Success();
    else return this->Fail();
}
int Menu::editFurn()
{
    writeFurnAll();
    char c;
    std::string name="";
    int price=0, mass=0, key=0;
    std::cout<<"Type exactly the key of furniture that should be edited: ";
    std::cin>>c;
    if(!std::isdigit(c))    return this->Fail();
    std::cin.unget();
    std::cin>>key;
    if(!isIntOK())      return this->Fail();
    std::cin.ignore(1000,'\n');
    if(MyCatalog->isKeyMap(key)==0)return this->Fail();
    std::cout<<"Type new name of the furniture: ";
    std::cin>>name;
    std::cin.ignore(1000,'\n');
    std::cout<<"Type new price of the furniture: ";
    std::cin>>c;
    if(!std::isdigit(c)) return this->Fail();
    std::cin.unget();
    std::cin>>price;
    if(!isIntOK()) return this->Fail();
    std::cin.ignore(1000,'\n');
    std::cout<<"Type new mass of furniture: ";
    std::cin>>c;
    if(!std::isdigit(c)) return this->Fail();
    std::cin.unget();
    std::cin>>mass;
    if(!isIntOK()) return this->Fail();
    std::cin.ignore(1000,'\n');
    if(MyCatalog->editFurn(key,name, price, mass)==1)return this->Success();
    else return this->Fail();
}
int Menu::writeFurnAll()
{
    std::cout<<"Furnitures that are in the catalog:"<<std::endl;
    orderWrite(MyCatalog->getRoot());
    return 1;

}
void Menu::orderWrite(node<int, Furniture>* start)
{
    if(start==NULL) return;
    if(start->l_son != NULL) //jezeli ma dzieci po lewej stronie wywolaj funkcje rekurencyjnie
    {
        orderWrite(start->l_son);
    }
    std::cout<<"Key: "<<start->key<<"    Name: ";
    std::cout<<start->val->getName();
    std::cout<<"     Price: "<<start->val->getPrice()<<"      Mass: "<<start->val->getMass()<<std::endl;
    if(start->r_son != NULL) //jezeli ma dzieci po prawej stronie wywolaj rekurencyjnie
        orderWrite(start->r_son);
}
int Menu::writeAllFurnFile()
{
    std::string fname="";
    std::cout<<"Type name of file: ";
    std::cin>>fname;
    std::cin.ignore(1000,'\n');
    if(MyCatalog->allFile(fname)==1)return Success();
    else return Fail();
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
