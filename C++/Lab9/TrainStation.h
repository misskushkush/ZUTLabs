#ifndef TRAINSTATION_H
#define TRAINSTATION_H
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Train.h"
#include "Station.h"
#include <vector>

using namespace std;

class TrainStation: public Station {
private:
    vector<unique_ptr<Train>> trains;
    int numTrain;
    static string type;

public:
    // Constructor
    TrainStation();

    Train* getTrain(int index) const {
        if (index >= 0 && index < trains.size()) {
            return trains[index].get();
        }
        return nullptr;
    }

    void print() const override;

    void addVehicle() override;

    void deleteVehicle(int index) override;

    void editVehicle(int index) override;

};

#endif