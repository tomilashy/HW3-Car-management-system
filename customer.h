#ifndef CUSTOMER_H_
#define CUSTOMER_H_
#include <iostream>
#include <string>
#include <map>

using std::string;
using std::cout;

class customer 
{
public:
	customer(string,string,string,string,int,int);// regular constructor
	//customer(const customer &); //copy constructor
    string getname() const;// returns name
    string getadd() const;// returns address
    string getTel() const;// returns Telephone Number
    int getDuration() const;// sets the maximum duration in weeks
    void setDuration(int) const;// returns the duration
    int getId() const;// returns id
    string getType() const;
    void print() const;
    friend bool operator<(const customer& x1, const customer& x2)
    {
       return x1.id < x2.id;
    }
	~customer();

private:
    string name;
    string address;
    string tel;
    int id;
    int duration;
	string type;

};

#endif /* CUSTOMER_H_ */
