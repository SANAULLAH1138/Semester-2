#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
class User{
	public:
		string name ;
		int age;
	void setUser(string n , int a )
	{
	   name = n;
	   age = a;
	}	
	void display()
	{
	   cout<<"MY NAME IS "<<name<<endl;
	   cout<<"I AM "<<age<<" YEARS OLD "<<endl;	
	}	
};
int main(int argc , char* argv[])
{
	if(argc<3)
	{
		cout<<"ERORR"<<endl;
		return 1; 
	}
	string name = argv[1];
	int age = stoi(argv[2]);
	User ob1;
	
	ob1.setUser(name,age);
	ob1.display();
}
