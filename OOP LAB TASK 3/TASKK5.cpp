#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class Book {
private:
    string bookName;
    long long int ISBN;  // Changed ISBN to long long int
    string author;
    string publisher;

public:
    Book(string bookName, long long int ISBN, string author, string publisher) {
        this->bookName = bookName;
        this->ISBN = ISBN;
        this->author = author;
        this->publisher = publisher;
    }

    string getBookName() {
        return this->bookName;
    }
    long long int getISBN() {
        return this->ISBN;
    }
    string getAuthor() {
        return this->author;
    }
    string getPublisher() {
        return this->publisher;
    }

    string getBookInfo() {
        return "BOOK NAME: " + this->bookName + "\n" +
               "ISBN NUMBER : " + to_string(this->ISBN) + "\n" +
               "AUTHOR: " + this->author + "\n" +
               "PUBLISHER: " + this->publisher + "\n";
    }
};

int main(int argc, char* argv[]) {
    if (argc < 5) {
        cout << "ERROR: Insufficient arguments provided." << endl;
        return 1;
    }

    string bookName = argv[1];
    long long int ISBN = stoll(argv[2]);   // Convert argument to long long int
    string author = argv[3];
    string publisher = argv[4];

    Book books[5] = {
        Book("SANAULLAH", 92345, "OOP", "DEPARTMENT"),
        Book("KAZIM", 82324, "PF", "DEPARTMENT"),
        Book("VIVEK", 57345, "PHYSICS", "DEPARTMENT"),
        Book("MEHRWAN", 57345, "CALCULUS", "DEPARTMENT"),
        Book("JITESH", 45345, "MVC", "DEPARTMENT")
    };

    // Replace the first book with the new book created from command-line arguments
    books[0] = Book(bookName, ISBN, author, publisher);

    // Displaying information for each book
    for (int i = 0; i < 5; i++) {
        cout << "Book " << i + 1 << " Info:\n";
        cout << books[i].getBookInfo();
        cout << "-----------------------------------\n";
    }

    return 0;
}
