#include "Train.h"

int GenerateRand(int begin, int end);
void Create_Ticket_Array(Ticket**& tickets, int size);
void Init_Ticket_Array(Ticket** tickets, int size);
void Delete_Ticket_Array(Ticket**& tickets, int& size);
void Print_Ticket_Array(Ticket** tickets, int size);

//Constructor
Train::Train() : numTickets(GenerateRand(1, 3)), tickets(new Ticket* [numTickets]) {
    
    Create_Ticket_Array(tickets, numTickets);
    Init_Ticket_Array(tickets, numTickets);
}

//Copying constructor
Train::Train(const Train& other) {
    this->personalNumber = other.personalNumber;

    // Create new Ticket objects and copy the values from other
    for (int i = 0; i < this->numTickets; i++) {
        if (other.tickets[i] != nullptr) {
            this->tickets[i] = new Ticket(*other.tickets[i]);
        }
        else {
            this->tickets[i] = nullptr;
        }
    }
}

// Destructor
Train::~Train() {
    Delete_Ticket_Array(tickets, numTickets);
    
}


// Print function
void Train::print() const {
    cout << "\nTrain with personal number " << personalNumber << endl;
    cout << "Number of tickets: " << numTickets << endl;
    ::Print_Ticket_Array(tickets, numTickets);
}