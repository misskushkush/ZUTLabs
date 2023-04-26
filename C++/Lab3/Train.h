#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Ticket.h"

class Train {
private:
    Ticket** tickets;
    string personalNumber;
    int numTickets;

public:

    // Getters and setters
    void setTickets(Ticket** t) {tickets = t;}
    Ticket** getTickets() const { return tickets; }
    
    int getNumTickets() const { return numTickets; };
    void setNumTickets(int num) { numTickets = num; }

    string getPersonalNumber() const { return personalNumber; }
    void setPersonalNumber(string pn) { personalNumber = pn; }

    //Constructor
    Train();

    //Copying constructor
    Train(const Train& other);

    // Destructor
    ~Train();

    // Print function
    void print() const;
};