#include<bits/stdc++.h>
using namespace std;

class Room{
private:
    string name;
public:
    Room(string name) {
        this->name = name;
    }
    string getName() {
        return name;
    }
};

class House{
private:
    vector<Room> rooms;
public:
    House() {
        Room bedRoom("Bed Room");
        Room livingRoom("Living Room");
        rooms.push_back(bedRoom);
        rooms.push_back(livingRoom);
    }
    void showRooms() {
        for(auto room:rooms) {
            cout << room.getName() << endl;
        }
    }
};

int main()
{
    House h;
    h.showRooms();
    return 0;
}