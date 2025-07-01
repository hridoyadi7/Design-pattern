#include<bits/stdc++.h>
using namespace std;

class Animal{
public:
    void eat() {
        cout << "Animal is eating" << endl;
    }
};

class Dog:public Animal{
public:
    void bark() {
        cout << "The dog is barking" << endl;
    }
};

int main()
{
    Dog dog;
    dog.bark();
    dog.eat();
    return 0;
}