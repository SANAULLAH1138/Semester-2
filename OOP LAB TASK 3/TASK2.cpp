#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
class Dates{
	int year;
	int month;
	int day;
	public:
	int getyear()
	{
	    return year;
	}
	int getmonth()
	{
	   return month;
	}
	int getday()
	{
	   return day; 
	}
	void setdates(int y , int m , int d)
	{
		year = y;
		month = m;
		day = d;
	}
	void display()
	{
		cout<<"Month / Day / Year : "<<month<< " / " <<day<< " / " <<year<<endl;
	}
};
int main(int argc , char* argv[])
{
	if(argc<4)
	{
		cout<<"ERROR"<<endl;
	}
	int year = stoi(argv[1]);
	int month = stoi(argv[2]);
	int day = stoi(argv[3]);
	
	Dates d1; 
	
	d1.setdates(year,month,day);
	d1.display();
	
	
}
