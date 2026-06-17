#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	double weight , lb ;
	cout<<"Enter The Weight In (KG) :";
	cin>>weight;
	lb=weight*2.2;
	cout<<"WEIGHT IN POUNDS IS :"<<weight<<endl;
	cout<< fixed <<setprecision(2);
	cout<<"WEIGHT IN KG :: "<<weight<<endl;
	cout<<"KG TO POUNDS :: "<<lb<<" LBs"<<endl;
	
}
