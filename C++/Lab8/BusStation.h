#ifndef BUSSTATION_H
#define BUSSTATION_H
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Bus.h"
#include "Station.h"
#include <vector>

using namespace std;

class BusStation : public Station {
private:
    vector<Bus*> buses;
    int numBus;
    static string type;

public:

    // Constructor
    BusStation();

    Bus* getBus(int index) const {
        if (index < 0 || index >= numBus) {
            // Handle out-of-bounds index
            return nullptr;
        }
        return buses[index];
    }

    // Destructor
    ~BusStation();

    void print() const override;

    void addVehicle() override;

    void deleteVehicle(int index) override;

    void editVehicle(int index) override;

};

#endif