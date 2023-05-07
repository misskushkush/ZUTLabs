#include "BusStation.h"

int GenerateRand(int begin, int end);
void Create_Bus_Array(Bus**& buses, int size);
void Delete_Bus_Array(Bus**& buses, int& size);
void Delete_Bus_From_Array(Bus**& buses, int& size, int index);
void Edit_Bus(Bus**& buses, int size, int index);
void Add_Bus(Bus**& buses, int& size);
void Print_Bus_Array(Bus** buses, int size);


// Constructor
BusStation::BusStation() : numBus{ GenerateRand(1, 4) }
{
    set_type(type);
    Create_Bus_Array(buses, numBus);
    for (int i = 0; i < numBus; i++) {
        buses[i]->setPersonalNumber(to_string(GenerateRand(10000, 55555)));
    }
}


// Destructor
BusStation::~BusStation() {
    if (buses != nullptr) {
        Delete_Bus_Array(buses, numBus);
    }
}

// Delete a Bus from the array
void BusStation::deleteVehicle(int index) {
    Delete_Bus_From_Array(buses, numBus, index);
}

// Edit a Bus in the array
void BusStation::editVehicle(int index) {
    Edit_Bus(buses, numBus, index);
}

// Add a Bus to the array
void BusStation::addVehicle() {
    Add_Bus(buses, numBus);
}


// Print function
void BusStation::print() const {
    display();
    ::Print_Bus_Array(buses, numBus);
}

void Create_Bus(Bus*& buses) {
    buses = new Bus;
}


void Create_Bus_Array(Bus**& buses, int size) {

    buses = new Bus * [size];
    for (int i = 0; i < size; i++)
        Create_Bus(buses[i]);
}



void Delete_Bus_Array(Bus**& buses, int& size) {
    for (int i = 0; i < size; i++) {
        delete buses[i];
        cout << "Bus" << i + 1 << "deleted\n";
    }
    delete[] buses;
    buses = nullptr;
    size = 0;
}

void Delete_Bus_From_Array(Bus**& buses, int& size, int index) {
    if (index < 0 || index >= size) {
        std::cout << "Invalid index." << std::endl;
        return;
    }
    delete buses[index];
    for (int i = index; i < size - 1; i++) {
        buses[i] = buses[i + 1];
    }
    buses[size - 1] = new Bus();
    size--;
}


void Edit_Bus(Bus**& buses, int size, int index) {
    if (index < 0 || index >= size) {
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

    buses[index_ticket]->getTickets()[index_ticket]->setHour(hour);
    buses[index_ticket]->getTickets()[index_ticket]->setMinute(minute);
    buses[index_ticket]->getTickets()[index_ticket]->setPrice(price);
    buses[index_ticket]->getTickets()[index_ticket]->setCityofDeparture(depart);
    buses[index_ticket]->getTickets()[index_ticket]->setCityofArrival(arrive);
}


void Add_Bus(Bus**& buses, int& size) {
    Bus** newbuses = new Bus * [size + 1];
    for (int i = 0; i < size; i++) {
        newbuses[i] = buses[i];
    }

    Create_Bus(newbuses[size]);
    delete[] buses;
    buses = newbuses;
    size++;
}

void Print_Bus_Array(Bus** buses, int size) {
    cout << "\n" << size << " buses:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "Bus " << i + 1 << ":" << endl;
        buses[i]->print();
    }
}