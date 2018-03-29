/*
 * cars.h
 *
 *  Created on: Feb 25, 2018
 *      Author: ore-oluwa.olasubulumi
 */

#ifndef CARS_H_
#define CARS_H_
#include <iostream>
#include <string>
using std::string;
using std::cout;
class cars
{
private:
	string type; // car's type
	string name;// car's name
	int id;//flag same as customer who borrowed
	int carNum;// car's id number
	string rent;
public:

	cars();// default constructor
	cars(int, string,string,int);// regular constructor
	void setcarid( int) const ;
	int getcarid() const;
	friend bool operator<(const cars& x1, const cars& x2)
	{
		return x1.carNum < x2.carNum;
	}
	int getcarNumber() const; // returns cars number
	string getCarName() const; // returns cars title
	void print() const;//prints car details
	string getType()const;//returns type of car
	~cars();// destructor
};



#endif /* CARS_H_ */
cars::cars(int Id, string n,string t,int i)
:name(n),carNum(Id), type(t),id(i)
{// regular constructor
	if (id == 0)
		{
			rent = "Available";
		}
		else
		{
			rent = "Rented";
		}

}

int cars::getcarNumber() const // returns cars number
{
	return carNum;
}
string cars::getCarName() const // returns cars title
{
	return name;
}

void cars::setcarid( int a)const
{
	const_cast<cars*>(this)->id=a;
	if (id == 0)
	{
		const_cast<cars*>(this)->	rent = "Available";
	}
	else
	{
		const_cast<cars*>(this)->rent = "Rented";
	}

}

int cars::getcarid() const
{
	return id;
}

string cars::getType() const
{
	return type;
}
void cars::print() const
{
	  cout<<"\nCar Name: "<<name;
	    cout<<"\nCar ID: "<<carNum;
	    cout<<"\nType of car:"<<type;
	    cout<<"\nAvailability :"<<rent<<endl;
}

cars::~cars()// destructor
{
}
