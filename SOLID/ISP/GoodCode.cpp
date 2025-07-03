#include<bits/stdc++.h>
#include <stdexcept>
using namespace std;

class Document {

};

class Printer {
public:
    virtual void print(Document &doc) = 0;
    virtual ~Printer() {}
};

class Scanner {
public:
    virtual void scan(Document &doc) = 0;
    virtual ~Scanner() {}
};

class Copier {
public:
    virtual void copy(Document &doc) = 0;
    virtual ~Copier() {}
};

class SimplePrinter : public Printer {
public:
    void print(Document &doc) override {
        cout << "Printing document..." << endl;
    }
};

class MultiPurposeMachine : public Printer, public Scanner, public Copier{
public:
    void print(Document &doc) override {
        cout << "Printing document..." << endl;
    }

    void scan(Document &doc) override {
        cout << "Scanning document..." << endl;
    }

    void copy(Document &doc) override {
        cout << "Copying document..." << endl;
    }
};

int main() {
    Document doc;
    SimplePrinter simplePrinter;
    simplePrinter.print(doc);

    MultiPurposeMachine multiMachine;
    multiMachine.print(doc);
    multiMachine.scan(doc);
    multiMachine.copy(doc);
    return 0;
}