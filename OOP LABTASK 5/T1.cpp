#include<iostream>
#include<string>
using namespace std;
class Engine{
	private:
		bool isrunning;
	public:
		void start()
		{
			isrunning = true;
			cout<<"ENGINE STARTS "<<endl;
		}
		void stop()
		{
			isrunning = false;
			cout<<"ENGINE STOPS "<<endl;
		}
		void check()
		{
			if(isrunning=false)
			{
				cout<<"ENGINE IS NOT RUNNING "<<endl;
			}
			else
			{
				cout<<"ENGINE RUNNING "<<endl;
			}
		}
		
};
class Car{
	private:
		Engine engine;
	public:
	 void startcar()
	 {
	 	cout<<"CAR STARTS "<<endl;
	 	engine.start();
	 }	
	 void stopcar()
	 {
	 	cout<<"CAR STOPS "<<endl;
	 	engine.stop();
	 }
	 void running()
	 {
	 	engine.check();
	 }
	 
};
int main()
{
	Car c1;
	c1.startcar();
	c1.running();
	c1.stopcar();
	
}
