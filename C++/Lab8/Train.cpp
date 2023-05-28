#include "Train.h"

int GenerateRand(int begin, int end);

//Constructor
Train::Train() : numTickets(GenerateRand(1, 3)), personalNumber(to_string(GenerateRand(10000, 55555))) {

    for (int i = 0; i < numTickets; i++)
        tickets.push_back(new Ticket());
}

Train::Train(const Train& other) : numTickets(other.numTickets), personalNumber(other.personalNumber)
{
    for (int i = 0; i < numTickets; i++) {
        tickets.push_back(new Ticket(*(other.tickets[i]))); // create a new Ticket object and copy its value
    }
}

// Destructor
Train::~Train() {
    for (int i = 0; i < numTickets; i++) {
        delete tickets[i];
    }
    tickets.clear();
    numTickets = 0;
}


// Print function
void Train::print() {
    cout << "\nTrain personal number " << personalNumber << endl;
    cout << "Number of tickets: " << numTickets << endl;
    cout << setw(6) << setfill('-') << "" << endl;
    for (int i = 0; i < numTickets; i++) {
        cout << "Ticket " << i + 1 << ":" << endl;
        printTicket(*tickets[i]);
    }
    cout << setw(6) << setfill('-') << "" << endl;
}

