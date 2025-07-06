#include<bits/stdc++.h>
using namespace std;

class Readable{
public:
    virtual void read() = 0;
    virtual ~Readable() {}
};

class Writable{
public:
    virtual void write() = 0;
    virtual ~Writable() {}
};

class ReadableFile : public Readable{
public:
    void read() {
        cout << "Reading from a file..." << endl;
    }
};

class WritableFile : public ReadableFile, public Writable{
public:
    void write() {
        cout << "Writing to a file..." << endl;
    }
};

class ReadOnlyFile : public ReadableFile{
};

void readAnyFile(Readable& file) {
    file.read();
}

int main() {
    ReadOnlyFile readableFile;
    readableFile.read();
    // readableFile.write();// At the time of compilation, we know readOnlyFile does not support write

    WritableFile writableFile;
    writableFile.read();
    writableFile.write();

    readAnyFile(readableFile);
    readAnyFile(writableFile);

    return 0;
}