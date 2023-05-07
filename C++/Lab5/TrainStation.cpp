#include "TrainStation.h"

int GenerateRand(int begin, int end);
void Create_Train_Array(Train**& trains, int size);
void Delete_Train_Array(Train**& trains, int& size);
void Delete_Train_From_Array(Train**& trains, int& size, int index);
void Edit_Train(Train**& trains, int size, int index);
void Add_Train(Train**& trains, int& size);
void Print_Train_Array(Train** trains, int size);


// Constructor
TrainStation::TrainStation() : numTrains { GenerateRand(1, 4) }
{
    Create_Train_Array(trains, numTrains);
    for (int i = 0; i < numTrains; i++) {
        trains[i]->setPersonalNumber(to_string(GenerateRand(10000,55555)));
    }
}


// Destructor
TrainStation::~TrainStation() {
    if (trains != nullptr) {
        Delete_Train_Array(trains, numTrains);
    }
}

// Delete a train from the array
void TrainStation::deleteTrain(int index) {
    Delete_Train_From_Array(trains, numTrains, index);
}

// Edit a train in the array
void TrainStation::editTrain(int index) {
    Edit_Train(trains, numTrains, index);
}

// Add a train to the array
void TrainStation::addTrain() {
    Add_Train(trains, numTrains);
}


// Print function
void TrainStation::print() const {
    ::Print_Train_Array(trains, numTrains);
}