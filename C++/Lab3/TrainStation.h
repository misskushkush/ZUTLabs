#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Train.h"

using namespace std;

class TrainStation {
private:
    Train** trains;
    int numTrains;

public:
    // Constructor
    TrainStation();

    //Copying constructor
    TrainStation(const TrainStation& other);

    // Destructor
    ~TrainStation();

    // Delete a train from the array
    void deleteTrain(int index);

    void addTrain();

    void editTrain(int index);

    // Print function
    void print() const;
};