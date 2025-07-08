#include<bits/stdc++.h>
using namespace std;


//Observer Interface
class Observer {
public:
    virtual void update(float temp) = 0;
    virtual ~Observer() {}
};

//Concrete Observer ->

class DisplayDevice : public Observer {
private:
    string name;
public:
    DisplayDevice(string name) : name(name) {
    }
    void update(float temp) override {
        cout << "Temparature on "<< name << " is: " << temp << endl;
    } 
};

class MobileDevice : public Observer {
public:
    MobileDevice() {}
    void update(float temp) override {
        cout << "Temparature on Mobile is: " << temp << endl;
    } 
};

//Subject Interface
class Subject {
public:
    virtual void attach(shared_ptr<Observer> observer) = 0;//addObserver
    virtual void detach(shared_ptr<Observer> observer) = 0;//removeObserver
    virtual void notifyObservers() = 0;
    virtual ~Subject() {}
};

//Concrete Subject -> WeatherStation
class WeatherStation : public Subject {
private:
    float temperature;
    unordered_set<shared_ptr<Observer>> observerUSet;
public:
    WeatherStation() : temperature(0.0f) {
    }
    void attach(shared_ptr<Observer> observer) override {
        observerUSet.insert(observer);
    }
    void detach(shared_ptr<Observer> observer) override {
        observerUSet.erase(observer);
    }
    void setTemperature(float temparature) {
        this->temperature = temparature;
        notifyObservers();
    }
    void notifyObservers() override {
        for(auto observer: observerUSet) {
            observer->update(temperature);//Runtime polymorphism
        }
    }  
};

int main() {

    //Create a publisher
    WeatherStation weatherStation;

    //Create subscribers
    shared_ptr<Observer> displayDevice1 = make_shared<DisplayDevice>("Samsung LCD");
    shared_ptr<Observer> mobileDevice1 = make_shared<MobileDevice>();

    //Attach Devices to publisher
    weatherStation.attach(displayDevice1);
    weatherStation.attach(mobileDevice1);

    //set temparature
    weatherStation.setTemperature(26);

    //Detach Devices from publisher
    weatherStation.detach(mobileDevice1);

    //set temparature
    weatherStation.setTemperature(30);

    return 0;
}