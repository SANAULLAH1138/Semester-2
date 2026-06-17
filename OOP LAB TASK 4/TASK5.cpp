#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class CoffeeShop {
	public:
    string name;
    string type;
    double price;

   MenuItem()
   {
   	    string name = " ";
   	    string type = " ";
   	    double price = 0.0;
   }
    MenuItem(string name , string type , double price)
    {
    	this->name=name;
    	this->type=type;
    	this->price=price;
	}
private:
    //string name;
    MenuItem menu[10]; 
    string orders[10]; 
    int menuSize;
    int orderSize;

public:
    CoffeeShop(string name, MenuItem menu[], int menuSize)
        : name(name), menuSize(menuSize), orderSize(0) {
        for (int i = 0; i < menuSize; i++) {
            this->menu[i] = menu[i];
        }
    }

    string addOrder(string itemName) {
        for (int i = 0; i < menuSize; i++) {
            if (menu[i].name == itemName) {
                if (orderSize < 10) {
                    orders[orderSize++] = itemName;
                    return itemName + " added to orders.";
                } else {
                    return "Order list is full.";
                }
            }
        }
        return "This item is currently unavailable.";
    }

    string fulfillOrder() {
        if (orderSize > 0) {
            string item = orders[0];
            for (int i = 0; i < orderSize - 1; i++) {
                orders[i] = orders[i + 1];
            }
            orderSize--;
            return "The " + item + " is ready.";
        } else {
            return "All orders have been fulfilled.";
        }
    }

    void listOrders() {
        if (orderSize == 0) {
            cout << "No orders currently." << endl;
            return;
        }
        cout << "Current orders: ";
        for (int i = 0; i < orderSize; i++) {
            cout << orders[i] << " ";
        }
        cout << endl;
    }

    double dueAmount() {
        double total = 0.0;
        for (int i = 0; i < orderSize; i++) {
            for (int j = 0; j < menuSize; j++) {
                if (orders[i] == menu[j].name) {
                    total += menu[j].price;
                    break;
                }
            }
        }
        return total;
    }

    string cheapestItem() {
        if (menuSize == 0) {
            return "No items available.";
        }
        MenuItem cheapest = menu[0];
        for (int i = 1; i < menuSize; i++) {
            if (menu[i].price < cheapest.price) {
                cheapest = menu[i];
            }
        }
        return cheapest.name;
    }

    void drinksOnly() {
        cout << "Drinks: ";
        for (int i = 0; i < menuSize; i++) {
            if (menu[i].type == "drink") {
                cout << menu[i].name << " ";
            }
        }
        cout << endl;
    }

    void foodOnly() {
        cout << "Food: ";
        for (int i = 0; i < menuSize; i++) {
            if (menu[i].type == "food") {
                cout << menu[i].name << " ";
            }
        }
        cout << endl;
    }
};

int main(int argc, char* argv[]) {
    MenuItem menu[] = {
        MenuItem("Latte", "drink", 3.50),
        MenuItem("Cappuccino", "drink", 4.00),
        MenuItem("Croissant", "food", 2.50),
        MenuItem("Sandwich", "food", 5.00)
    };
    int menuSize = 4;

    CoffeeShop coffeeShop("Java Junction", menu, menuSize);

    for (int i = 1; i < argc; i++) {
        cout << coffeeShop.addOrder(argv[i]) << endl;
    }

    coffeeShop.listOrders();

    cout << coffeeShop.fulfillOrder() << endl;
    cout << coffeeShop.fulfillOrder() << endl;
    cout << coffeeShop.fulfillOrder() << endl;

    cout << "Total due amount: $" << coffeeShop.dueAmount() << endl;

    cout << "Cheapest item: " << coffeeShop.cheapestItem() << endl;

    coffeeShop.drinksOnly();

    coffeeShop.foodOnly();

    return 0;
}
