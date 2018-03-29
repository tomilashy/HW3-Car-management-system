#include <iostream>
#include <string>
#include <map>
using std::cout;
using std::cin;
using std::endl;
using std::string;
void RegCustomer();
void DelCustomer();
void CustDetails();
void RegCar();
void DelCar();
void checkRent();
void modify();
void rent();
void returncar();
void checkcust();
void checkcar();
void typeofcar();
#include "cars.h"
#include "customer.h"
std::map<customer,int> Info;
std::map<cars,int> car;
int main()
{
	char a;

	//string n,string a,string tele,string t,int Id,int d
	    Info.insert(std::make_pair<customer, int>(customer("Anna Evans", "1533 Av. Du Parc","43745645","Regular",100,20), 100) );
	    Info.insert(std::make_pair<customer, int>(customer("John Stones", "1400 Sherbrooke","43745675","VIP",120,45), 120) );
	    Info.insert(std::make_pair<customer, int>(customer("Cisco ltd", "2433 St. Catherine","43745699","Corporate",300,35), 300) );

			//int carnum, string n,string t,int id
	    car.insert(std::make_pair<cars, int>(cars(3875234,"Lamborghini","luxury",300), 300) );
	    car.insert(std::make_pair<cars, int>(cars(3875879,"Toyota","Standard",120), 120) );
	    car.insert(std::make_pair<cars, int>(cars(3834752,"Ferrari","luxury",0), 0) );

	    do{


	    cout <<"\n\t\t\t**********************************************\n"
	        "\t\t\t*        COEN 244 CAR MANAGMENT SYSTEM       *\n"
	        "\t\t\t*                       BY                   *\n"
	        "\t\t\t* OLASUBULUMI OGO-OLUWA JESUTOMI ID:40055693 *\n"
	        "\t\t\t* IRFAN AHMED ID:40056645                    *\n"
	            "\t\t\t**********************************************";
	        cout<<"\nwhich of the following options do you want to perform\n";
	        cout<<"a) Add a new car to the inventory\n"//put getline name
	    "b) Remove an existing car from the inventory\n"//done
	    "c) Register new customers"		//done//fix your getline address
	     "\nd) Remove a given customer from the customer’s list"//done
	     "\ne) Rent a car to a customer"//regular cant rent luxury
	     "\nf) Return a car and update car information" //done
	     "\ng) Return the privileges of a particular customer."//done
	     "\nh) Change the privileges (e.g., modify the rental period for regular customers to 25)."
	     "\ni) Determine whether a given car is rented or not"//done
	     "\nj) Determine whether a given customer has rented a car"
	     "\nk) Determine whether a given car is with a regular customer, corporate, or VIP."
	     "\nl) Determine the types of cars rented by a customer of a given company"
	     "\nm) Print all customers"//done
	     "\nn) Print all cars"//done
	     "\no) Exit.\n";//done


	    cin >>a;

	    switch (a)
	    {
	        case 'a':
	        	RegCar();
	            break;
	        case 'b':
	        	DelCar();
	            break;
	        case 'c':
	        	RegCustomer();
	        	break;
	        case 'd':
	        	DelCustomer();
	            break;
	        case 'e':
	        		rent();
	            break;
	        case 'f':
	        	returncar();
	            break;
	        case 'g':
	        	CustDetails();
	            break;
	        case 'h':
	        	modify();
	            break;
	        case 'i':
	        	checkRent();
	            break;
	        case 'j':
	        	checkcust();
	            break;
	        case 'k':
	        	checkcar();
	            break;
	        case 'l':
	        	typeofcar();
	            break;
	        case 'm':
	        	std::map<customer, int>::iterator it = Info.begin();
	        	for(; it != Info.end(); it++)
	        	{
	        		it->first.print();
	        	}

	        	break;
	    }
	    if (a=='n')
	    {
	    	std::map<cars, int>::iterator it1 = car.begin();
	    		        		for(; it1 != car.end(); it1++)
	    		        		{
	    		        			it1->first.print();
	    		        		}

	    }

	}while(a!='o');
	    cout <<"\n\t\t\t**********************************************\n"
		        "\t\t\t*        HAVE A WONDERFUL DAY & THANKS FOR   *\n"
	    		 "\t\t\t*                    STOPPING                *\n"
		        "\t\t\t*                       BY                   *\n"
		        "\t\t\t*        COEN 244 CAR MANAGMENT SYSTEM       *\n"
		            "\t\t\t**********************************************";
    return 0;
}

void RegCustomer()
{
	{
					string n;
		        	string add;
		        	string tele;
		        	int Id;
		        	int check;
		cout<< "is it\n 1)Regular Customer"
				"\n2)Corporate Customer"
				"\n3)VIP customer";
		cin>>check;

		        	cout<<"Input Name :";
		        	cin.ignore(256,'\n');
		        	getline(cin,n);
		        	cout<<"Input Telephone :";
		        	cin>>tele;
		        	cout<<"Input ID Number :";
		        	cin>>Id;
		        	cout<<"Input Address :";
		        	cin.ignore(256,'\n');
		        	getline(cin,add);


		        	if (check==1)
		        	{
		        		Info.insert(std::make_pair<customer, int>(customer(n, add,tele,"Regular",Id,20), Id) );
		        	}
		        	if (check==2)
		        	{
		        		Info.insert(std::make_pair<customer, int>(customer(n, add,tele,"Corporate",Id,35), Id) );
		        	}
		        	if (check==3)
		        	{
		        		Info.insert(std::make_pair<customer, int>(customer(n, add,tele,"VIP",Id,45), Id) );
		        	}
		        }
}

void DelCustomer()
{
	cout<<"\nwhich do you want to use to get the name of the person you want to delete"
			"\n1) number"
			"\n2 Name";
	int choose;
	cin>>choose;

	if(choose==1)
	{
	int n;
		        	cout<<"Input ID : ";
		        	cin>>n;
		        	std::map<customer, int>::iterator it = Info.begin();
		        	 for(; it != Info.end(); it++)
		        	 {
		        		 if (it == Info.end())
		        		 {
		        			 cout<<"customer not found";
		        			 break;
		        		 }

		        		if (it->second==n)
		        		{
		        			cout << "\nfound " << it->first.getname()<<"\nAre you sure you want to delete " <<it->first.getname() << "?(0 for yes & 1 for no)"<<endl;
		        			int x;
		        			cin>>x;

							if (x==0)
							{
								Info.erase(it);
								cout << "Deleted!!" << endl;break;
							}

			        		else
			        	    {
			        			cout << "Operation cancelled" << endl;break;
			        	    }
							
		        		}

		        	 }

	}
	else if(choose==2)
	{
	string n;
		        	cout<<"Input Name :";
		        	cin.ignore(256,'\n');
		        	getline(cin,n);

		        	 for(std::map<customer, int>::iterator it = Info.begin(); it != Info.end(); it++)
		        	 {
		        		 if (it == Info.end())
		        		 {
		        			 cout<<"customer not found";
		        			 break;
		        		 }

		        		if (it->first.getname()==n)
		        		{
		        			cout << "found " << it->first.getname()<<"\nAre you sure you want to delete " <<it->first.getname() << "?(0 for yes & 1 for no)"<<endl;
		        			int x;
		        			cin>>x;

							if (x==0)
							{
								Info.erase(it);
								cout << "Deleted!!" << endl;break;
							}

			        		else
			        	    {
			        			cout << "Operation cancelled" << endl;break;
			        	    }
							
		        		}

		        	 }

	}
}

void CustDetails()
{
	cout<<"\nwhich do you want to use to get the details of the person and his privileges"
				"\n1) number"
				"\n2 Name";
		int choose;
		cin>>choose;

		if(choose==1)
		{
				int n;
				cout<<"Input ID : ";
				cin>>n;
				std::map<customer, int>::iterator it = Info.begin();
				for(; it != Info.end(); it++)
				{

					if (it->second==n)
					{
						it->first.print();
					}
				}
		}
		else if(choose==2)
				{
						string n;
						cout<<"Input Name :";
						cin.ignore(256,'\n');
						getline(cin,n);
						std::map<customer, int>::iterator it = Info.begin();
						for(; it != Info.end(); it++)
						{

							if (it->first.getname()==n)
												{
													it->first.print();
												}
						}
				}
}


void RegCar()
{

		        	string n;
		        	int Id;
		        	int check;
		        	cout<<"Input name :";
		        	cin.ignore(256,'\n');
		        	getline(cin,n);
		        	cout<<"Input Car Number :";
		        	cin>>Id;
		        	cout<< "is it\n 1)Luxury Car"
		        			"\n2)Standard Car";

		        	cin>>check;
		        	if (check==1)
		        	{
		        		car.insert(std::make_pair<cars, int>(cars(Id,n,"luxury",0), 0) );

		        	}
		        	if (check==2)
		        	{
		        		car.insert(std::make_pair<cars, int>(cars(Id,n,"Standard",0), 0) );
		        	}


}

void DelCar()
{
	cout<<"\nwhich do you want to use to get the name of the person you want to delete"
			"\n1) Car number"
			"\n2  Car Name";
	int choose;
	cin>>choose;

	if(choose==1)
	{
	int n;
		        	cout<<"Input ID : ";
		        	cin>>n;

		        	 for(std::map<cars, int>::iterator it = car.begin(); it != car.end(); it++)
		        	 {
		        		 if (it == car.end())
		        		 {
		        			 cout<<"car not found";
		        			 break;
		        		 }

		        		if (it->first.getcarNumber()==n)
		        		{
		        			cout << "\nfound " << it->first.getCarName()<<"\nAre you sure you want to delete " <<it->first.getCarName() << "?(0 for yes & 1 for no)"<<endl;
		        			int x;
		        			cin>>x;

							if (x==0)
							{
								car.erase(it);
								cout << "Deleted!!" << endl;break;
							}

			        		else
			        	    {
			        			cout << "Operation cancelled" << endl;break;
			        	    }
							
		        		}

		        	 }

	}
	else if(choose==2)
	{
	string n;
		        	cout<<"Input Car Name :";
		        	cin.ignore(256,'\n');
		        	getline(cin,n);

		        	for(std::map<cars, int>::iterator it = car.begin(); it != car.end(); it++)
		        	{
		        		if (it == car.end())
		        		{
		        			cout<<"car not found";
		        			break;
		        		}

		        		if (it->first.getCarName()==n)
		        		{
		        			cout << "found " << it->first.getCarName()<<"\nAre you sure you want to delete " <<it->first.getCarName() << "?(0 for yes & 1 for no)"<<endl;
		        			int x;
		        			cin>>x;

							if (x==0)
							{
								car.erase(it);
								cout << "Deleted!!" << endl;break;
							}

			        		else
			        	    {
			        			cout << "Operation cancelled" << endl;break;
			        	    }
							
		        		}

		        	 }

	}
}

void checkRent()
{
	cout << "Input the car Id :";
	int n;

	cin >> n;
	for (std::map<cars, int>::iterator it = car.begin(); it != car.end(); it++)
	{

		if (it->first.getcarNumber() == n)
		{
			if (it->first.getcarid() == 0)
			{
				cout << "\nCar is Available";
			}
			else
			{
				cout << "\nCar is Rented";

			}
		}
	}
}

void rent()
{
	//input car ids
	cout<<"Input the cutormer's ID :";
		int id1;
		cin>>id1;
	cout<<"Input the car ID of the car you want to rent :";
	int id2;
	cin>>id2;

	for(std::map<customer, int>::iterator it = Info.begin(); it != Info.end(); it++)
	{
		if (it == Info.end())
		{
			cout<<"customer not found";
			break;
		}

		if (it->second==id1)
		{
			for (std::map<cars, int>::iterator it1 = car.begin(); it1 != car.end(); it1++)
				{
					if (it1 == car.end())
						{
							cout<<"car not found";
							break;
						}

					if (it1->first.getcarNumber() == id2)
					{
						if (it1->first.getcarid() == 0)
						{
							cout << "\nCar is Available";
							if(it->first.getType()=="Regular"&& it1->first.getType() == "luxury")
							{
									cout<<"\nA Regular customer cannot borrow a luxury car\n";
							}
							else if(it->first.getType()=="Regular"&& it1->first.getType() == "Standard")
							{
								it1->second=it->first.getId();
								it1->first.setcarid(id2);
								cout<<"Car successfully borrowed for "<<it->first.getDuration()<<" days";
							}
							else
							{
								it1->second=it->first.getId();
								it1->first.setcarid(it->first.getId());

								cout<<"Car successfully borrowed for "<<it->first.getDuration()<<" days";
							}
						}
						else
						{
							cout << "\nCar is Already Rented";

						}
					}
				}

		}
	}

}

void returncar()
{
	cout<<"Input the car ID of the car you want to return :";
		int id2;
		cin>>id2;
		for (std::map<cars, int>::iterator it1 = car.begin(); it1 != car.end(); it1++)
		{
			if (it1 == car.end())
			{
				cout<<"car not found";
				break;
			}

			if (it1->first.getcarNumber() == id2)
			{
				if (it1->second == 0)
				{
					cout<<"Car was not rented";
				}
				else
				{
					it1->second=0;
					it1->first.setcarid(0);
					cout<<"Car has been returned";

				}
			}

		}
}

void modify()
{	cout<<"which customer do you want to modify?";
	cout<< "\n 1)Regular Customer"
			"\n2)Corporate Customer"
			"\n3)VIP customer";
	int check;
	cin>>check;
	cout<<"how many days do you want to set the new duration?";
	int dur;
	cin>>dur;
	 for(std::map<customer, int>::iterator it = Info.begin(); it != Info.end(); it++)
	 {
		 if (check==1 && it->first.getType()=="Regular")
		{
			 it->first.setDuration(dur);
			 cout<<"Duration modified for Regular customers";
		}
		 if (check==2 && it->first.getType()=="Corporate")
		 {
			 it->first.setDuration(dur);
			 cout<<"Duration modified for Corporate customers";
		 }
		 if (check==2 && it->first.getType()=="VIP")
		 {
			 it->first.setDuration(dur);
			 cout<<"Duration modified for VIP customers";
		 }
	 }

}

void checkcust()
{
	int n;
		cout<<"Input Customer ID : ";
		cin>>n;

		 for(std::map<customer, int>::iterator it = Info.begin(); it != Info.end(); it++)
		 {
			 if (it == Info.end())
			 {
				 cout<<"customer not found";
				 break;
			 }

			if (it->second==n)
			{
				for(std::map<cars, int>::iterator it1 = car.begin(); it1 != car.end(); it1++)
				{
					if (it1 == car.end())
					{
						cout<<"No he has rented the any car";
						break;
					}

					if (it1->second==n)
					{
						cout<<"Yes he has rented the following car";
						it1->first.print();
					}
				}
			}
		 }
}

void checkcar()
{
	int n;
		cout<<"Input Car ID : ";
		cin>>n;

		for(std::map<cars, int>::iterator it1 = car.begin(); it1 != car.end(); it1++)
		{
			if (it1 == car.end())
			{
				cout<<"Car not found";
				break;
			}

			if (it1->first.getcarNumber() ==n)
			{
				 for(std::map<customer, int>::iterator it = Info.begin(); it != Info.end(); it++)
					 {
						 if (it == Info.end())
						 {
							 cout<<"customer not found";
							 break;
						 }

						if (it1->second==it->second)
						{
							cout<<"The following customer rented the car";
							it->first.print();
						}
					 }
			}
		}


}

void typeofcar()
{
	int n;
	cout<<"Input company's Customer ID : ";
	cin>>n;

	 for(std::map<customer, int>::iterator it = Info.begin(); it != Info.end(); it++)
	 {
		 if (it == Info.end())
		 {
			 cout<<"customer not found";
			 break;
		 }

		if (it->second==n)
		{
			for(std::map<cars, int>::iterator it1 = car.begin(); it1 != car.end(); it1++)
			{
				if (it1 == car.end())
				{
					cout<<"No car rented";
					break;
				}

				if (it1->second==n)
				{
					it1->first.print();
				}
			}
		}
	 }

}

