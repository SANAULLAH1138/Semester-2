#include <iostream>
using namespace std;

class Book {
protected:
    string genre;
    string title;
    string author;

public:
    Book(string g, string t, string a) : genre(g), title(t), author(a) {}

    virtual void displayDetails() {
        cout << "Genre: " << genre << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
    }
};

class Novel : public Book {
public:
    Novel(string g, string t, string a) : Book(g, t, a) {}

    void displayDetails() override {
        cout << "Novel Details:" << endl;
        Book::displayDetails();
    }
};

class Narrative : public Book {
public:
    Narrative(string g, string t, string a) : Book(g, t, a) {}

    void displayDetails() override {
        cout << "Narrative Details:" << endl;
        Book::displayDetails();
    }
};

int main() {
    
    Narrative N1("Biography", "The Story of My Life", "Helen Keller");
    N1.displayDetails();

    return 0;
}

