#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>

using namespace std;

struct User {
    string user_id;
    string first_name;
    string last_name;
    string address;
    string email;
};

struct Product {
    string product_id;
    string product_name;
    string description;
    int price;
};

struct Order {
    string order_id;
    string user_id;
    string product_id;
    int total_paid;
};

int main() {
    vector<User> users = {
        {"u1", "Linus", "Torvalds", "123 Linux Lane", "linus@example.com"},
        {"u2", "Ada", "Lovelace", "42 Math St", "ada@example.com"}
    };

    vector<Product> products = {
        {"p1", "Keyboard", "Mechanical keyboard", 150},
        {"p2", "Mouse", "Wireless mouse", 80},
        {"p3", "Monitor", "4K Display", 300}
    };

    vector<Order> orders = {
        {"o1", "u1", "p1", 150},
        {"o2", "u1", "p3", 300},
        {"o3", "u2", "p2", 80}
    };

    string linus_id;
    for (auto &user : users) {
        if (user.first_name == "Linus") {
            linus_id = user.user_id;
            break;
        }
    }

    vector<string> linus_product_ids;
    for (auto &order : orders) {
        if (order.user_id == linus_id) {
            linus_product_ids.push_back(order.product_id);
        }
    }

    cout << "Products ordered by Linus:\n";
    for (auto &product : products) {
        for (auto &pid : linus_product_ids) {
            if (product.product_id == pid) {
                cout << product.product_name << endl;
            }
        }
    }

    return 0;
}

