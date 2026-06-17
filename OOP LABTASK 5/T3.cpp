#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Book {
private:
    string title;
    string author;
    string ISBN;

public:
    Book(string t, string a, string isbn) : title(t), author(a), ISBN(isbn) {
        cout << "Book Created: " << title << " (ISBN: " << ISBN << ")\n";
    }

    string getISBN() const { return ISBN; }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }

    void showDetails() const {
        cout << "Title: " << title << "\nAuthor: " << author << "\nISBN: " << ISBN << endl;
    }

    ~Book() {
        cout << "Book Destroyed: " << title << endl;
    }
};

class Catalog {
private:
    map<string, Book*> bookIndex;  

public:
    Catalog() {
        cout << "Catalog Created\n";
    }

    void addBook(Book* book) {
        bookIndex[book->getISBN()] = book;
    }

    Book* findBook(string isbn) {
        if (bookIndex.find(isbn) != bookIndex.end()) {
            return bookIndex[isbn];
        }
        return nullptr;
    }

    void removeBook(string isbn) {
        bookIndex.erase(isbn);
    }

    void showAllBooks() {
        if (bookIndex.empty()) {
            cout << "Catalog is empty.\n";
            return;
        }
        cout << "Books in Catalog:\n";
        for (auto& pair : bookIndex) {
            cout << "- " << pair.second->getTitle() << " (ISBN: " << pair.first << ")\n";
        }
    }

    ~Catalog() {
        cout << "Catalog Destroyed\n";
    }
};

class Library {
private:
    string name;
    string address;
    Catalog catalog;  
    vector<Book*> books;  

public:
    Library(string n, string addr) : name(n), address(addr) {
        cout << "Library Created: " << name << " at " << address << "\n";
    }

    void addBook(Book* book) {
        books.push_back(book);
        catalog.addBook(book);
        cout << book->getTitle() << " added to Library: " << name << endl;
    }

    void removeBook(string isbn) {
        for (size_t i = 0; i < books.size(); i++) {
            if (books[i]->getISBN() == isbn) {
                books.erase(books.begin() + i);
                catalog.removeBook(isbn);
                cout << "Book with ISBN " << isbn << " removed from Library.\n";
                return;
            }
        }
        cout << "Book not found in Library.\n";
    }

    void findBookInCatalog(string isbn) {
        Book* book = catalog.findBook(isbn);
        if (book) {
            cout << "Book Found in Catalog:\n";
            book->showDetails();
        } else {
            cout << "Book not found in Catalog.\n";
        }
    }

    void showLibraryBooks() {
        cout << "Books in " << name << ":\n";
        for (Book* book : books) {
            cout << "- " << book->getTitle() << " (ISBN: " << book->getISBN() << ")\n";
        }
    }

    ~Library() {
        cout << "Library Destroyed: " << name << "\n";
    }
};

int main() {
    
    Book* book1 = new Book("PHYSICS", "SANAULLAH", "345-568578");
    Book* book2 = new Book("OOPS", "VIVEK-KUMAR", "675-0321563842");
    Book* book3 = new Book("PROGRAMING", "KAZIM", "945-1491903995");

    Library lib("Central Library", "NEAR FAST NUCES");

    lib.addBook(book1);
    lib.addBook(book2);
    lib.addBook(book3);

    cout << "\nLibrary Catalog:\n";
    lib.showLibraryBooks();

    cout << "\nSearching for Book by ISBN (675-0321563842):\n";
    lib.findBookInCatalog("675-0321563842");

    cout << "\nRemoving Book (945-1491903995)...\n";
    lib.removeBook("945-1491903995");

    cout << "\nFinal Library Books:\n";
    lib.showLibraryBooks();

    delete book1;
    delete book2;
    delete book3;

    return 0;
}

