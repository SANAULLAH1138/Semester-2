#include <iostream>
#include <string>

using namespace std;

const int MAX_MENU_ITEMS = 6;  // Fixed size menu
const int MAX_ORDERS = 10;     // Fixed size for orders

class MItem {
public:
    string nm, typ;
    double pr;
    MItem(string n = "", string t = "", double p = 0) : nm(n), typ(t), pr(p) {}
};

class CoffeeShop {
private:
    MItem menu[MAX_MENU_ITEMS]; 
    string orders[MAX_ORDERS]; 
    int orderCount;

public:
    string shopName;

    CoffeeShop(string s) : shopName(s), orderCount(0) {
        menu[0] = MItem("Espresso", "D", 2.5);
        menu[1] = MItem("Cappuccino", "D", 3.0);
        menu[2] = MItem("Latte", "D", 3.5);
        menu[3] = MItem("Sandwich", "F", 5.0);
        menu[4] = MItem("Muffin", "F", 2.0);
        menu[5] = MItem("Cake", "F", 4.0);
    }

    string addOrder(string itm) {
        if (orderCount >= MAX_ORDERS) {
            return "Order limit reached!";
        }
        for (int i = 0; i < MAX_MENU_ITEMS; i++) {
            if (menu[i].nm == itm) {
                orders[orderCount++] = itm;
                return "Order added: " + itm;
            }
        }
        return itm + " is not available!";
    }

    string fulfillOrder() {
        if (orderCount == 0) {
            return "All orders are done!";
        }
        string itm = orders[0];
        for (int i = 1; i < orderCount; i++) {
            orders[i - 1] = orders[i]; // Shift orders left
        }
        orderCount--;
        return "Ready to serve: " + itm;
    }

    void listOrders() const {
        if (orderCount == 0) {
            cout << "No pending orders.\n";
            return;
        }
        cout << "Pending Orders:\n";
        for (int i = 0; i < orderCount; i++) {
            cout << " - " << orders[i] << endl;
        }
    }

    double dueAmount() const {
        double total = 0;
        for (int i = 0; i < orderCount; i++) {
            for (int j = 0; j < MAX_MENU_ITEMS; j++) {
                if (menu[j].nm == orders[i]) {
                    total += menu[j].pr;
                    break;
                }
            }
        }
        return total;
    }

    string cheapestItem() const {
        int cheapestIndex = 0;
        for (int i = 1; i < MAX_MENU_ITEMS; i++) {
            if (menu[i].pr < menu[cheapestIndex].pr) {
                cheapestIndex = i;
            }
        }
        return menu[cheapestIndex].nm;
    }

    void drinksOnly() const {
        cout << "Available Drinks:\n";
        for (int i = 0; i < MAX_MENU_ITEMS; i++) {
            if (menu[i].typ == "D") {
                cout << " - " << menu[i].nm << endl;
            }
        }
    }

    void foodOnly() const {
        cout << "Available Foods:\n";
        for (int i = 0; i < MAX_MENU_ITEMS; i++) {
            if (menu[i].typ == "F") {
                cout << " - " << menu[i].nm << endl;
            }
        }
    }
};

int main() {
    CoffeeShop shop("JavaHut");

    cout << shop.addOrder("Latte") << endl;
    cout << shop.addOrder("Sandwich") << endl;
    cout << shop.addOrder("Pizza") << endl;  // Invalid order

    cout << "\n";
    shop.listOrders();

    cout << "\nTotal Due: $" << shop.dueAmount() << endl;
    cout << "Cheapest Item: " << shop.cheapestItem() << endl;

    cout << "\n";
    shop.drinksOnly();

    cout << "\n";
    shop.foodOnly();

    cout << "\n" << shop.fulfillOrder() << endl;
    cout << shop.fulfillOrder() << endl;

    return 0;
}

