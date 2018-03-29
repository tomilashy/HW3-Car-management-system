#include "customer.h"
using std::cout; 
using std::endl;

customer::customer(string n,string a,string tele,string t,int Id,int d) :
tel(tele),name(n),address(a),type(t),id(Id), duration(d)
{

}

void customer::setDuration(int a) const
{
	const_cast<customer*>(this)->duration=a;

}

string customer::getname() const
{
    return name;
}
string customer::getadd() const
{
    return address;
}
string customer::getTel() const
{
    return tel;
}
int customer::getId() const
{
    return id;
}
string customer::getType() const
{
    return type;
}

int customer::getDuration() const
{
    return duration;
}
void customer::print() const
{
    cout<<"\nCustomer Name: "<<name;
    cout<<"\nCustomer ID: "<<id;
    cout<<"\nAddress: "<<address;
    cout<<"\nTelephone: "<<tel;
    cout<<"\nType :"<<type;
    cout<<"\nDuration :"<<duration<<endl;
}
customer::~customer() 
{
}


