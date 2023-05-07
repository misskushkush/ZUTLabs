#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iomanip>
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

                friend istream& operator>>(istream& input, Ticket& ticket) {
                    input >> ticket.hour;
                    input.ignore(); // ignore the colon character
                    input >> ticket.minute >> ticket.price;
                    input.ignore(); // ignore the space character
                    getline(input, ticket.cityofDeparture, '-');
                    getline(input, ticket.cityofArrival);

                    // Check for errors while reading the input stream
                    if (input.fail()) {
                        cerr << "Error reading input stream." << endl;
                        exit(1);
                    }

                    return input;
                }

                friend ostream& operator<<(ostream& output, const Ticket& ticket) {
                    output << ticket.hour << ":" << ticket.minute << " "
                        << ticket.price << " " << ticket.cityofDeparture
                        << "-" << ticket.cityofArrival;
                    return output;
                }

                /*friend istream& operator>>(istream& in, Ticket& ticket) {
                    cout << "Enter departure city: ";
                    getline(in, ticket.cityofDeparture);

                    cout << "Enter arrival city: ";
                    getline(in, ticket.cityofArrival);

                    cout << "Enter departure time (HH:MM): ";
                    char colon;
                    in >> ticket.hour >> colon >> ticket.minute;

                    cout << "Enter ticket price: ";
                    in >> ticket.price;

                    return in;
                }

                friend ostream& operator<<(ostream& out, const Ticket& ticket) {
                    out << "\n\tDeparture: " << ticket.cityofDeparture << " at " << ticket.hour << ":" << ticket.minute << endl;
                    out << "\tArrival: " << ticket.cityofArrival << endl;
                    out << "\tPrice: " << ticket.price << endl;
                    return out;
                }*/
        };


private:
    Ticket** tickets;
    string personalNumber = "24255";
    int numTickets;

public:

    void printTicket(const Ticket& ticket) {
        cout << "\n\tDeparture: " << ticket.cityofDeparture << " at " << setw(2) << setfill('0') << ticket.hour << ":" << setw(2) << setfill('0') << ticket.minute << endl;
        cout << "\tArrival: " << ticket.cityofArrival << endl;
        cout << fixed << setprecision(2);
        cout << "\tPrice: " << setw(6) << setfill(' ') << right << ticket.price << endl;
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

    Train& operator=(const Train& right) {
        if (&right != this)
        {
            this->Train::~Train();
            this->Train::Train(right);
        }

        return *this;
    }

    Ticket* operator [](const size_t k)
    {
        return tickets[k];
    }


    friend istream& operator>>(istream& input, Train& train) {
        // Read the personal number
        input >> train.personalNumber;

        // Read the number of tickets
        input >> train.numTickets;

        // Allocate memory for the tickets
        train.tickets = new Ticket * [train.numTickets];

        // Read each ticket and store it in the tickets array
        for (int i = 0; i < train.numTickets; i++) {
            train.tickets[i] = new Ticket;
            input >> *(train.tickets[i]);
        }

        // Check for errors while reading the input stream
        if (input.fail()) {
            cerr << "Error reading input stream." << endl;
            exit(1);
        }

        return input;
    }

    friend ostream& operator<<(ostream& output, const Train& train) {
        // Write the personal number
        output << train.personalNumber << endl;

        // Write the number of tickets
        output << train.numTickets << endl;

        // Write each ticket to the output stream
        for (int i = 0; i < train.numTickets; i++) {
            output << *(train.tickets[i]) << endl;
        }

        return output;
    }

    /*friend istream& operator>>(istream& in, Train& train) {
        cout << "Enter train personal number: ";
        in >> train.personalNumber;

        cout << "Enter number of tickets: ";
        in >> train.numTickets;

        train.tickets = new Ticket * [train.numTickets];

        for (int i = 0; i < train.numTickets; i++) {
            train.tickets[i] = new Ticket();
            cout << "Enter details for ticket #" << i << ":" << endl;
            in >> *(train.tickets[i]);
        }

        return in;
    }

    friend ostream& operator<<(ostream& out, const Train& train) {
        out << "Train personal number: " << train.personalNumber << endl;
        out << "Number of tickets: " << train.numTickets << endl;
        for (int i = 0; i < train.numTickets; i++) {
            out << "Ticket #" << i << ": " << *(train.tickets[i]) << endl;
        }
        return out;
    }*/

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
