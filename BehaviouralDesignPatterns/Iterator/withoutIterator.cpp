#include<bits/stdc++.h>
using namespace std;

class Book {
private:
    string title;
public:
    Book(string title) : title(title) {}
    string getTitle() {
        return title;
    }
};

class BookCollection {
private:
    vector<Book> books;
public:
    void addBook(Book book) {
        books.push_back(book);
    }
    vector<Book> getBooks() {
        return books;
    }
};

int main() 
{
    BookCollection bookCollection;
    Book book1("C++ Book");
    Book book2("Java Book");
    bookCollection.addBook(book1);
    bookCollection.addBook(book2);
    for(int i = 0; i < bookCollection.getBooks().size(); i++) {
        cout << bookCollection.getBooks()[i].getTitle() << endl;
    }
    return 0;
}