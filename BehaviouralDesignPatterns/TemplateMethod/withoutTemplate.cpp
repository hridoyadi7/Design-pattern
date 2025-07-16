#include<bits/stdc++.h>
using namespace std;

class CSVParser{
public:
    void parse() {
        openFile();
        //CSV specific parsing logic
        cout << "Parsing a CSV file" << endl;
        closeFile();
    }
private:
    void openFile() {
        cout << "Opening File" << endl;
    }
    void closeFile() {
        cout << "Closing File" << endl;
    }
};

class JSONParser{
public:
    void parse() {
        openFile();
        //JSON specific parsing logic
        cout << "Parsing a JSON file" << endl;
        closeFile();
    }
private:
    void openFile() {
        cout << "Opening File" << endl;
    }
    void closeFile() {
        cout << "Closing File" << endl;
    }
};

int main() 
{
    CSVParser csvParser;
    csvParser.parse();
    JSONParser jsonParser;
    jsonParser.parse();
    return 0;
}