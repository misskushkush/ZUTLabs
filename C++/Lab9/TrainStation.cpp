#include "TrainStation.h"

int GenerateRand(int begin, int end);

string TrainStation::type = "Train";

// Constructor
TrainStation::TrainStation() : numTrain{ GenerateRand(1, 4) }
{
    set_type(type);
    for (int i = 0; i < numTrain; i++) {
        trains.push_back(make_unique<Train>());
        trains[i]->setPersonalNumber(to_string(GenerateRand(10000, 55555)));
    }
}

// Delete a Train from the array
void TrainStation::deleteVehicle(int index) {
    if (index < 0 || index >= numTrain) {
        std::cout << "Invalid index." << std::endl;
        return;
    }
    trains.erase(trains.begin() + index);
    numTrain--;
}

// Edit a Train in the array
void TrainStation::editVehicle(int index) {
    if (index < 0 || index >= numTrain) {
        cout << "Invalid Train index." << endl;
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

    trains[index]->getTickets()[index_ticket]->setHour(hour);
    trains[index]->getTickets()[index_ticket]->setMinute(minute);
    trains[index]->getTickets()[index_ticket]->setPrice(price);
    trains[index]->getTickets()[index_ticket]->setCityofDeparture(depart);
    trains[index]->getTickets()[index_ticket]->setCityofArrival(arrive);
}

// Add a Train to the array
void TrainStation::addVehicle() {
    trains.push_back(make_unique<Train>());
    numTrain++;
}


// Print function
void TrainStation::print() const {
    display();
    cout << "\n" << numTrain << " trains:" << endl;
    for (int i = 0; i < numTrain; i++) {
        cout << "Train " << i + 1 << ":" << endl;
        trains[i]->print();
    }
}



