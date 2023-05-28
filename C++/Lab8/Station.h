#ifndef STATION_H
#define STATION_H
#include <iostream>;
#include <string>;

using namespace std;
class Station {
    string type;
public:
    void set_type(string type)
    {
        this->type = type;
    };
    void display() const
    {
        cout << "\n\t\t\t " << type << " Station" << endl;
    };
    virtual void print() const = 0; // Pure virtual function
    virtual void addVehicle() = 0; // Pure virtual function for adding a vehicle
    virtual void deleteVehicle(int index) = 0; // Pure virtual function for removing a vehicle
    virtual void editVehicle(int index) = 0;
};

#endif