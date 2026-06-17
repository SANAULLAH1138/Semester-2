#include<iostream>
#include<string>
#include<cmath>
using namespace std;
class circle{
	public:
	double radius ;
    circle(double r)
	{
	   radius = r ;	
	}	
	double getarea()
	{
		return M_PI * radius * radius ;
	}
	double getperimeter()
	{
		return 2 * M_PI * radius ;
	}
	
};
int main(int argc , char* argv[])
{
	if(argc<2)
	{
		cout<<"ERROR"<<endl;
	}
	double r = stod(argv[1]);
	cout<<"ENTER THE RADIUS :";
	cin>>r;
	circle c1(r);
	cout<<"AREA IS : "<<c1.getarea()<<endl;
	cout<<"PERIMITER IS :"<<c1.getperimeter()<<endl;
}
