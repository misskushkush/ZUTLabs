#ifndef TRAINSTATION_H
#define TRAINSTATION_H
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Train.h"
#include "Station.h"

using namespace std;

class TrainStation: public Station {
private:
    Train** trains;
    int numTrains;
    string type = "Train";

public:
    // Constructor
    TrainStation();

    Train* getTrain(int index) const {
        if (index < 0 || index >= numTrains) {
            // Handle out-of-bounds index
            return nullptr;
        }
        return trains[index];
    }

    // Destructor
    ~TrainStation();

    void print() const override;

    void addVehicle() override;

    void deleteVehicle(int index) override;

    void editVehicle(int index) override;

};

#endif