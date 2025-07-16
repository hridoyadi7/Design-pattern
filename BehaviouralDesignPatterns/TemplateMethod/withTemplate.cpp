#include<bits/stdc++.h>
using namespace std;

class DataParser {
public:
    //Template method that define steps of the algorithm
    void parse() {
        openFile();
        parseData();
        closeFile();
    }
protected:
    void openFile() {
        cout << "Opening File" << endl;
    }
    virtual void parseData() = 0;
    void closeFile() {
        cout << "Closing File" << endl;
    }
};

class CSVParser : public DataParser {
protected:
    void parseData() override {
        cout << "Parsing CSV data" << endl;
    }
};

class JSONParser : public DataParser {
protected:
    void parseData() override {
        cout << "Parsing JSON data" << endl;
    }
};

int main()
{
    shared_ptr<DataParser> csvParser = make_shared<CSVParser>();
    csvParser->parse();
    shared_ptr<DataParser> jsonParser = make_shared<JSONParser>();
    jsonParser->parse();
    return 0;
}