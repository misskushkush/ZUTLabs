#include "Ticket.h"
int GenerateRand(int begin, int end);


Ticket::Ticket(){
    hour = GenerateRand(0, 23);
    minute=GenerateRand(0, 59);
    price=GenerateRand(50, 350);
    string cities[] = { "New York", "Washington D.C.", "Los Angeles", "San Francisco", "Chicago", "Houston" };
    
    int depindex = GenerateRand(0, 5);
    int arrindex = GenerateRand(0, 5);
    while (depindex == arrindex) {
        arrindex = GenerateRand(0, 5);
    }
    cityofDeparture=cities[depindex];
    cityofArrival=cities[arrindex];
}

//Copying constructor
Ticket::Ticket(const Ticket& other) {
    this->hour = other.hour;
    this->minute = other.minute;
    this->price = other.price;
    this->cityofDeparture = other.cityofDeparture;
    this->cityofArrival = other.cityofArrival;
}


// Constructor with parameters
Ticket::Ticket(int h, int m, double p, string dep, string arr) {
    hour = h;
    minute = m;
    price = p;
    cityofDeparture = dep;
    cityofArrival = arr;
}


// Print function
void Ticket::print() const {
    cout << "\n\tDeparture: " << cityofDeparture << " at " << hour << ":" << minute << endl;
    cout << "\tArrival: " << cityofArrival << endl;
    cout << "\tPrice: " << price << endl;
}