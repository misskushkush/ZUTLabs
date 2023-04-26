#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

int GenerateRand(int begin, int end);

class Train {
   
private:
        class Ticket {
            private:
                int hour;
                int minute;
                double price;
                string cityofDeparture;
                string cityofArrival;

            public:
                friend class Train;
                // Getters
                int getHour() const { return hour; }
                int getMinute() const { return minute; }
                double getPrice() const { return price; }
                string getCityofDeparture() const { return cityofDeparture; }
                string getCityofArrival() const { return cityofArrival; }

                // Setters
                void setHour(int h) { hour = h; }
                void setMinute(int m) { minute = m; }
                void setPrice(double p) { price = p; }
                void setCityofDeparture(string dep) { cityofDeparture = dep; }
                void setCityofArrival(string arr) { cityofArrival = arr; }

                //Constructor
                Ticket()
                {
                    hour = GenerateRand(0, 23);
                    minute = GenerateRand(0, 59);
                    price = GenerateRand(50, 350);
                    string cities[] = { "New York", "Washington D.C.", "Los Angeles", "San Francisco", "Chicago", "Houston" };

                    int depindex = GenerateRand(0, 5);
                    int arrindex = GenerateRand(0, 5);
                    while (depindex == arrindex) {
                        arrindex = GenerateRand(0, 5);
                    }
                    cityofDeparture = cities[depindex];
                    cityofArrival = cities[arrindex];
                };


                // Constructor with parameters
                Ticket(int h, int m, double p, string dep, string arr)
                {
                    hour = h;
                    minute = m;
                    price = p;
                    cityofDeparture = dep;
                    cityofArrival = arr;
                };

                //// Print function
                //void print() const
                //{
                //    cout << "\n\tDeparture: " << cityofDeparture << " at " << hour << ":" << minute << endl;
                //    cout << "\tArrival: " << cityofArrival << endl;
                //    cout << "\tPrice: " << price << endl;
                //};
        };


private:
    Ticket** tickets;
    string personalNumber = "24255";
    int numTickets;

public:

    void printTicket(const Ticket& ticket) {
        cout << "\n\tDeparture: " << ticket.getCityofDeparture() << " at " << ticket.getHour() << ":" << ticket.getMinute() << endl;
        cout << "\tArrival: " << ticket.getCityofArrival() << endl;
        cout << "\tPrice: " << ticket.getPrice() << endl;
    }

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
    Train(const Train& other) : numTickets(other.numTickets), personalNumber(other.personalNumber)
    {
        tickets = new Ticket * [numTickets];
        for (int i = 0; i < numTickets; i++) {
            tickets[i] = new Ticket(*(other.tickets[i])); // create a new Ticket object and copy its value
        }
    }

    // Destructor
    ~Train();

    Ticket* getTicket(int index) const {
        if (index < 0 || index >= numTickets) {
            // Handle out-of-bounds index
            return nullptr;
        }
        return tickets[index];
    }

    // Print function
    void print();
};
