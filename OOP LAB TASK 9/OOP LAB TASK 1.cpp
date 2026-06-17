#include<iostream>
using namespace std;
class Shape {
	public:
		virtual void getarea() = 0 ;
	
};
class rectangle : public Shape{
	
	int len;
	int wid;
	public:
	rectangle(int l , int w)
	{
	 len=l;
	 wid=w;	
	}	
	void getarea()
	{
	   	int R=len*wid;
	   	cout<<"AREA OF RECTANGLE : "<<R<<endl;
	} 
};
class triangle : public Shape{
	 
	int base;
	int height;
	public:
	triangle(int b , int h)
	{
	   base=b;
	   height=h;	
	}	
	void getarea()
	{
	  int T = 0.5*base*height;
	  cout<<"AREA OF TRIANGLE : "<<T<<endl;	
	} 
};
 

int main(){
	  rectangle r(3,4);
      triangle t(2,4);
      
      
      r.getarea();
      t.getarea();
	  
	   
         
}

