#include<bits/stdc++.h>
using namespace std;

class DisplayDevice {
public:
    void showTemp(float temp) {
        cout << "Current Temperature: " << temp << " C" << endl;
    }
};
class WeatherStation {
private:
    float temperature;
    DisplayDevice displayDevice; // there can be multiple display devices
public:
    WeatherStation(DisplayDevice displayDevice) : displayDevice(displayDevice) {

    }
    void setTemprature(float temp) {
        temperature = temp;
        notifyDevice();
    }
    void notifyDevice() {
        displayDevice.showTemp(temperature);
    }
};

int main() {
    DisplayDevice displayDevice;
    WeatherStation weatherStation(displayDevice);
    weatherStation.setTemprature(25.5);
    weatherStation.setTemprature(28.5);
    return 0;
}