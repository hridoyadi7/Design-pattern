#include<bits/stdc++.h>
using namespace std;

class Professor{
private:
    string name;
public:
    Professor(string name) {
        this->name = name;
    }
    string getName() {
        return name;
    }
};

class Department{
private:
    string name;
    vector<Professor> professors;
public:
    Department(string name, vector<Professor> professors) {
        this->name = name;
        this->professors = professors;
    }
    void showProfessors() {
        cout << "Name of the Department:" << name << endl;
        for(int i = 0; i < professors.size(); i++)
            cout << professors[i].getName() << endl;
    }
};

int main()
{
    Professor p1("Professor 1");
    Professor p2("Professor 2");
    Professor p3("Professor 3");
    vector<Professor> listOfProfessors;
    listOfProfessors.push_back(p1);
    listOfProfessors.push_back(p2);
    listOfProfessors.push_back(p3);
    Department d("Department 1", listOfProfessors);
    d.showProfessors();
    return 0;
}