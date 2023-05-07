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
    set_type(type);
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
void TrainStation::deleteVehicle(int index) {
    Delete_Train_From_Array(trains, numTrains, index);
}

// Edit a train in the array
void TrainStation::editVehicle(int index) {
    Edit_Train(trains, numTrains, index);
}

// Add a train to the array
void TrainStation::addVehicle() {
    Add_Train(trains, numTrains);
}


// Print function
void TrainStation::print() const {
    display();
    ::Print_Train_Array(trains, numTrains);
}


void Create_Train(Train*& train) {
    train = new Train;
}


void Create_Train_Array(Train**& trains, int size) {

    trains = new Train * [size];
    for (int i = 0; i < size; i++)
        Create_Train(trains[i]);
}



void Delete_Train_Array(Train**& trains, int& size) {
    for (int i = 0; i < size; i++) {
        delete trains[i];
        cout << "Train" << i + 1 << "deleted\n";
    }
    delete[] trains;
    trains = nullptr;
    size = 0;
}

void Delete_Train_From_Array(Train**& trains, int& size, int index) {
    if (index < 0 || index >= size) {
        std::cout << "Invalid index." << std::endl;
        return;
    }
    delete trains[index];
    for (int i = index; i < size - 1; i++) {
        trains[i] = trains[i + 1];
    }
    trains[size - 1] = new Train();
    size--;
}


void Edit_Train(Train**& trains, int size, int index) {
    if (index < 0 || index >= size) {
        cout << "Invalid train index." << endl;
        return;
    }
    int per_num;
    cout << "Enter new personal number for Train: ";
    cin >> per_num;
    trains[index]->setPersonalNumber(to_string(per_num));

    int index_ticket;
    cout << "Enter ticket index to edit: ";
    cin >> index_ticket;
    if (index_ticket < 0 || index_ticket >= trains[index]->getNumTickets()) {
        cout << "Invalid ticket index." << endl;
        return;
    }

    int hour, minute;
    double price;
    string arrive, depart;

    cout << "Enter the details for the new ticket:" << endl;
    cin.ignore();
    // Get input for hour and minute
    string timeInput;
    getline(cin, timeInput);
    size_t timePos = timeInput.find(":");
    hour = stoi(timeInput.substr(0, timePos));
    minute = stoi(timeInput.substr(timePos + 1));

    // Get input for price
    string priceInput;
    getline(cin, priceInput);
    price = stod(priceInput);

    // Get input for depart and arrive
    getline(cin, depart);
    getline(cin, arrive);

    trains[index_ticket]->getTickets()[index_ticket]->setHour(hour);
    trains[index_ticket]->getTickets()[index_ticket]->setMinute(minute);
    trains[index_ticket]->getTickets()[index_ticket]->setPrice(price);
    trains[index_ticket]->getTickets()[index_ticket]->setCityofDeparture(depart);
    trains[index_ticket]->getTickets()[index_ticket]->setCityofArrival(arrive);
}


void Add_Train(Train**& trains, int& size) {
    Train** newTrains = new Train * [size + 1];
    for (int i = 0; i < size; i++) {
        newTrains[i] = trains[i];
    }

    Create_Train(newTrains[size]);
    delete[] trains;
    trains = newTrains;
    size++;
}

void Print_Train_Array(Train** trains, int size) {
    cout << "\n" << size << " trains:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "Train " << i + 1 << ":" << endl;
        trains[i]->print();
    }
}