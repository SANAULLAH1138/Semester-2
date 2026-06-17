#include <iostream>
#include <cstring>
using namespace std;

class Media {
protected:
    string title, publicationDate, uniqueID, publisher;
public:
    Media(string t, string pubDate, string id, string pub)
        : title(t), publicationDate(pubDate), uniqueID(id), publisher(pub) {}

    virtual void displayInfo() {
        cout << "Title: " << title << "\nPublication Date: " << publicationDate 
             << "\nUnique ID: " << uniqueID << "\nPublisher: " << publisher << "\n";
    }
};

class Book : public Media {
    string author, ISBN;
    int numberOfPages;
public:
    Book(string t, string pubDate, string id, string pub, string a, string isbn, int pages)
        : Media(t, pubDate, id, pub), author(a), ISBN(isbn), numberOfPages(pages) {}
    
    void displayInfo() override {
        Media::displayInfo();
        cout << "Author: " << author << "\nISBN: " << ISBN << "\nPages: " << numberOfPages << "\n";
    }
};

class DVD : public Media {
    string director;
    int duration;
    float rating;
public:
    DVD(string t, string pubDate, string id, string pub, string dir, int dur, float r)
        : Media(t, pubDate, id, pub), director(dir), duration(dur), rating(r) {}
    
    void displayInfo() override {
        Media::displayInfo();
        cout << "Director: " << director << "\nDuration: " << duration << " \nRating: " << rating << "\n";
    }
};

class CD : public Media {
    string artist, genre;
    int numberOfTracks;
public:
    CD(string t, string pubDate, string id, string pub, string art, int tracks, string gen)
        : Media(t, pubDate, id, pub), artist(art), numberOfTracks(tracks), genre(gen) {}
    
    void displayInfo() override {
        Media::displayInfo();
        cout << "Artist: " << artist << "\nTracks: " << numberOfTracks << "\nGenre: " << genre << "\n";
    }
};

void searchMedia(string title) {
    cout << "Searching by title: " << title << "\n";
}

void searchMedia(string author, bool isBook) {
    if (isBook)
        cout << "Searching  by author: " << author << "\n";
}

void searchMedia(int year) {
    cout << "Searching by publication year: " << year << "\n";
}

int main() {
   
    Book book1("Physics", "1998", "KR03", "US Publisher", "Kazim_Mehdi", "98765897", 950);
    DVD dvd1("Community-Service", "2010", "VS01", "TO Publisher", "Vivek_kumar", 176, 9.8);
    CD cd1("Calculas", "1982", "SH11", "ME Publisher", "Sanaullah", 9, "POP");
    
    
    book1.displayInfo();
    cout << "------******-----\n";
    dvd1.displayInfo();
    cout << "------******-----\n";
    cd1.displayInfo();
    cout << "------******-----\n";
    
    searchMedia("Calculas");
    searchMedia("Sanaullah", false);
    searchMedia(2020);
    
    return 0;
}

