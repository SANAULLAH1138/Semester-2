#include <iostream>
#include <thread>  
#include <chrono>  

using namespace std;

class Blend {
public:
    void blendJuice() {
        cout << "Blending juice...\n";
        for (int i = 1; i <= 5; i++) {
            cout << "Blending... " << i << " seconds\n";
            this_thread::sleep_for(chrono::seconds(1)); 
        }
        cout << "Blending complete!\n";
    }
};

class Grind {
public:
    void grindJuice() {
        cout << "Grinding juice...\n";
        this_thread::sleep_for(chrono::seconds(5)); 
        cout << "Grinding complete!\n";
    }
};

class JuiceMaker {
private:
    Blend blender;
    Grind grinder;

public:
    void makeJuice() {
        cout << "\nStarting juice making process...\n";
        blender.blendJuice();
        grinder.grindJuice();
        cout << "Juice is ready! Enjoy!\n";
    }
};

int main() {
    JuiceMaker myJuice;
    myJuice.makeJuice();

    return 0;
}

