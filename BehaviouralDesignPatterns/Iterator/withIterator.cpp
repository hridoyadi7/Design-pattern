#include<bits/stdc++.h>
using namespace std;

template <typename T>
class Iterator {
public:
    virtual ~Iterator() {}
    virtual bool hasNext() = 0;
    virtual T next() = 0;
};

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

    shared_ptr<Iterator<Book>> createIterator() {
        return make_shared<BookIterator>(books);
    }

    //Another class(Nested class)
private:
    class BookIterator : public Iterator<Book> {
    private:
        vector<Book> books;
        int position = 0;
    public:
        BookIterator(vector<Book> books) : books(books) {}
        bool hasNext() { position < books.size(); }
        Book next() { return books[position++]; }
    };
};

int main() 
{
    BookCollection bookCollection;
    Book book1("C++ Book");
    Book book2("Java Book");
    Book book3("Python Book");
    bookCollection.addBook(book1);
    bookCollection.addBook(book2);
    bookCollection.addBook(book3);
    shared_ptr<Iterator<Book>> iterator = bookCollection.createIterator();
    while(iterator->hasNext()) {
        Book book = iterator->next();
        cout << "Book Title " << book.getTitle() << endl;
    }
    return 0;
}