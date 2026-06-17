#include<iostream>
using namespace std;
class Vechile {
	protected:
	int price;
	public:
	int getprice()
	{
		return price ;
	}
	void setPrice(int price)
	{
	   	this->price=price;
	}	
};
class Car : public Vechile {
	protected:
	int capacity;
	int no_of_door;
	public:
	string type;
	public:
	int getcapacity()
	{
	   return capacity;	
	}	
	int getno_of_door()
	{
		return no_of_door;
	}
	string gettype()
	{
		return type;
	}
	void setcar(int capacity,int no_of_door,string type)
	{
		this->capacity=capacity;
		this->no_of_door=no_of_door;
		this->type=type;
	}
};
class Motorbike : public Vechile{
	protected:
	int no_of_cyld;
	int no_of_gear;
	int no_of_wheels;
		public:
	int getno_of_cyld()
	{
	   return no_of_cyld ;	
	}	
	int getno_of_gear()
	{
		return no_of_gear;
	}
	int getno_of_wheels()
	{
		return no_of_wheels;
	}
	void setMotorbikee(int no_of_cyld ,int no_of_gear,int no_of_wheels)
	{
		this->no_of_cyld=no_of_cyld;
		this->no_of_gear=no_of_gear;
		this->no_of_wheels=no_of_wheels;
	}
	
};
class Audi : public Car{
	string model;
	
	public:
		
	string getmodel()
	{
		return model;
	}
	void setmodel(string model)
	{
	   this->model=model;	
	}
	void display()
	{
	   cout<<"*****AUDI-CAR*****"<<endl;
	   cout<<"MODEL : "<<model<<endl;
	   cout<<"CAPACITY : "<<capacity<<endl;
	   cout<<"NO OF DOORS : "<<no_of_door<<endl;
	   cout<<"FUEL TYPE : "<<type<<endl;
	   cout<<"PRICE OF CAR : "<<price<<endl;	
	}	
};
class Yamhya : public Motorbike{
	public:
	string make;
	int price;
	public:
		
	string getmake()
	{
		return make;
	}
	int getprice()
	{
		return price;
	}
	void setmake(string make , int price)
	{
	   this->make=make;	
	   this->price=price;
	}
	
	void Show()
	{
	   cout<<endl<<"***YAMHA-MOTOR-BIKE***"<<endl;
	   cout<<"MODEL : "<<make<<endl;
	   cout<<"NO OF CYLINDER : "<<no_of_cyld<<endl;
	   cout<<"NO OF GEARS : "<<no_of_gear<<endl;
	   cout<<"NO OF WHEELS : "<<no_of_wheels<<endl;
	   cout<<"PRICE OF BIKE : "<<price<<endl;
	}
};



int main(){
     
     Audi A1;
     A1.setcar(10,4,"PETROL");
     A1.setPrice(550000);
     A1.setmodel("DD44");
     A1.display();
     
     
     Yamhya Y1;
     Y1.setMotorbikee(2,5,2);
     Y1.setmake("CC4",350000);
     Y1.Show();
     
     
}

