#include<iostream>
using namespace std;

class person{
	string name ;
	string id;
	int salary;
	
	public :
		
	string getname()
	{
	   return name;	
	}
	string getid()
	{
	   return id;
	}
	int getsalary()
	{
	    return salary;	
	}	
	void setdata(string n , string i ,int sal)
	{
		name = n ;
		id = i ;
		salary = sal ;
	}
	virtual void getinput()
	{
		cout<<"ENTER NAME ";
		cin>>name;
		cout<<"ENTER ID ";
		cin>>id;
		cout<<"ENTER SALARY ";
		cin>>salary;
		
	}
	virtual void clacbonus(int bonus)
	{
	     if(salary>=0 && salary<=50000)
		 {
		 	bonus=salary*0.1;
		 	cout<<"Bonus added .... Bonus is :"<<bonus<<endl;
		 	salary+=bonus;
		 	cout<<"Total Salary Aftr Bonus is : "<<salary<<endl;
		 }	
		 else{
		 	cout<<"Sorry... This Offer Is Not For You ... "<<endl;
		 }
	}
	virtual void display()
	{
	    cout<<"Name : "<<name<<endl;
		cout<<"ID : "<<id<<endl;
		cout<<"INITIAL SALARY : "<<salary<<endl;
		cout<<"Bonus added .... Bonus is :"<<bonus<<endl;
		cout<<"Total Salary Aftr Bonus is : "<<salary<<endl;	
	}	
};
class Admin : public person{
	  
	  public :
	  	
	  	void getdata() override
	  	{
	  		cout<<"PERSONAL INFO "<<endl;
	  		
		}
	
};
int main(){

}

