#include<bits/stdc++.h>
#include <stdexcept>
using namespace std;

class Document {

};

class Machine {
public:

    virtual void print(Document &doc) = 0;
    virtual void scan(Document &doc) = 0;
    virtual void copy(Document &doc) = 0;
    virtual ~Machine() {}
};

class SimplePrinter : public Machine {
public:
    void print(Document &doc) override {
        cout << "Printing document..." << endl;
    }

    void scan(Document &doc) override {
        throw std::runtime_error("Scanning not supported by SimplePrinter");
    }

    void copy(Document &doc) override {
        throw std::runtime_error("Copying not supported by SimplePrinter");
    }
};

class MultiPurposeMachine : public Machine {
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
    simplePrinter.scan(doc); 
    simplePrinter.copy(doc); 

    MultiPurposeMachine multiMachine;
    multiMachine.print(doc);
    multiMachine.scan(doc);
    multiMachine.copy(doc);
    return 0;
}