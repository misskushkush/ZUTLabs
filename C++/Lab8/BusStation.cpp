#include "BusStation.h"

int GenerateRand(int begin, int end);


string BusStation::type = "Bus";

// Constructor
BusStation::BusStation() : numBus{ GenerateRand(1, 4) }
{
    set_type(type);
    for (int i = 0; i < numBus; i++) {
        buses.push_back(new Bus());
        buses[i]->setPersonalNumber(to_string(GenerateRand(10000, 55555)));
    }
}


// Destructor
BusStation::~BusStation() {
    for (int i = 0; i < numBus; i++) {
        delete buses[i];
        cout << "Bus" << i + 1 << "deleted\n";
    }
    numBus = 0;
}

// Delete a Bus from the array
void BusStation::deleteVehicle(int index) {
    if (index < 0 || index >= numBus) {
        std::cout << "Invalid index." << std::endl;
        return;
    }
    delete buses[index];
    buses.erase(buses.begin() + index);
    numBus--;
}

// Edit a Bus in the array
void BusStation::editVehicle(int index) {
    if (index < 0 || index >= numBus) {
        cout << "Invalid Bus index." << endl;
        return;
    }

    int per_num;
    cout << "Enter new personal number for Bus: ";
    cin >> per_num;
    buses[index]->setPersonalNumber(to_string(per_num));

    int index_ticket;
    cout << "Enter ticket index to edit: ";
    cin >> index_ticket;
    if (index_ticket < 0 || index_ticket >= buses[index]->getNumTickets()) {
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

    buses[index]->getTickets()[index_ticket]->setHour(hour);
    buses[index]->getTickets()[index_ticket]->setMinute(minute);
    buses[index]->getTickets()[index_ticket]->setPrice(price);
    buses[index]->getTickets()[index_ticket]->setCityofDeparture(depart);
    buses[index]->getTickets()[index_ticket]->setCityofArrival(arrive);
}

// Add a Bus to the array
void BusStation::addVehicle() {
    buses.push_back(new Bus());
    numBus++;
}


// Print function
void BusStation::print() const {
    display();
    cout << "\n" << numBus << " buses:" << endl;
    for (int i = 0; i < numBus; i++) {
        cout << "Bus " << i + 1 << ":" << endl;
        buses[i]->print();
    }
}



