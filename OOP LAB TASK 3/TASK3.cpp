#include <iostream>
#include<cstdlib>
using namespace std;

class Glass {
public:
    int Liquid; 

    Glass() 
	{
        Liquid = 200;
    }
    void Drink(int ml) 
	{
        if (ml > Liquid) 
		{
            cout << "NOT ENOUGH LIQUID  Only " << Liquid << " ml left." << endl;
        } else 
		{
            Liquid -= ml; 
            cout << "DRINK " << ml << " ml. Remaining: " << Liquid << " ml." << endl;
            if (Liquid < 100) 
			{
                Refill();
            }
        }
    }
    void Refill() {
        Liquid = 200;
        cout << "GLASS REFILLED To 200 ml." << endl;
    }
};

int main(int argc , char* argv[]) 
{
	if(argc<2)
	{
		cout<<"ERROR"<<endl;
	}
	int Liquid = stoi(argv[1]);
    Glass glass; 
    int ml;

    cout << "Welcome to Me for refill system! Each glass holds 200 ml." << endl;
    cout << "Enter the amount of liquid drink (in ml) or Enter '0' for exit:" << endl;

    while (true) 
	{
        cout << "> ";
        cin >> ml;

        if (ml == 0) 
		{
            cout << "Exit program" << endl;
            break;
        }

        if (ml < 0) 
		{
            cout << "Invalid input " << endl;
            continue;
        }

        glass.Drink(ml); 
    }
}
