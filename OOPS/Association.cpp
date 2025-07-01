#include<bits/stdc++.h>
using namespace std;

/*Since Teacher class Takes Student object: student class should be mentioned before the Teacher class*/

class Student{
private:
    string name;
public:
    Student(string name) {
        this->name = name;
    }
    string getName() {
        return name;
    }
};

class Teacher{
private:
    string name;
public:
    Teacher(string name) {
        this->name = name;
    }
    string getName() {
        return name;
    }
    void teach(Student student) {
        cout << name << " is teaching:" << student.getName() << endl;
    }
};

int main()
{
    Student st("Rahul");
    Teacher tea("Miss Neha");
    tea.teach(st);
    return 0;
}