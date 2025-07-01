#include<bits/stdc++.h>
using namespace std;

class Document{
private:
    string content;
public:
    Document(string content) {
        this->content = content;
    }
    string getContent() {
        return content;
    }
};

class Printer{
public:
    void print(Document doc) {
        cout << "printing doc:" << doc.getContent() << endl;
    }
};

int main()
{
    Printer p;
    Document doc("My document");
    p.print(doc);
    return 0;
}