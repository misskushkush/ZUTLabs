#include "Bus.h"

int GenerateRand(int begin, int end);

//Constructor
Bus::Bus() : numTickets(GenerateRand(1, 3)), personalNumber(to_string(GenerateRand(10000, 55555))) {

    for (int i = 0; i < numTickets; i++)
        tickets.push_back(make_unique<Ticket>());
}

Bus::Bus(const Bus& other) : numTickets(other.numTickets), personalNumber(other.personalNumber)
{
    for (int i = 0; i < numTickets; i++) {
        tickets.push_back(make_unique<Ticket>(*(other.tickets[i]))); // create a new Ticket object and copy its value
    }
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

