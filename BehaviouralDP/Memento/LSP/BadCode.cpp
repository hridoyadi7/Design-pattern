#include<bits/stdc++.h>
#include <stdexcept>
using namespace std;

class File{
public:
    void read() {
        cout << "Reading from file..." << endl;
    }
    void write() {
        cout << "Writing to file..." << endl;
    }
};

class ReadOnlyFile : public File {
public:
    void write() {
        throw std::runtime_error("Cannot write to a read-only file");
    }
};

int main() {
    ReadOnlyFile file;
    file.read();
    file.write();//runtime exception violation of LSP
    //Readonly file should not support write()
    return 0;
}