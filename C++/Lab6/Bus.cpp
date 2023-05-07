#include "Bus.h"

int GenerateRand(int begin, int end);

//Constructor
Bus::Bus() : numTickets(GenerateRand(1, 3)), tickets(new Ticket* [numTickets]), personalNumber(to_string(GenerateRand(10000, 55555))) {

    tickets = new Ticket * [numTickets];
    for (int i = 0; i < numTickets; i++)
        tickets[i] = new Ticket();
}

// Destructor
Bus::~Bus() {
    for (int i = 0; i < numTickets; i++) {
        delete tickets[i];
        //cout << "Ticket" << i + 1 << "deleted\n";
    }
    delete[] tickets;
    tickets = nullptr;
    numTickets = 0;
}


// Print function
void Bus::print() {
    cout << "\nBus personal number " << personalNumber << endl;
    cout << "Number of tickets: " << numTickets << endl;
    cout << setw(6) << setfill('-') << "" << endl;
    for (int i = 0; i < numTickets; i++) {
        cout << "Ticket " << i + 1 << ":" << endl;
        printTicket(*tickets[i]);
    }
    cout << setw(6) << setfill('-') << "" << endl;
}