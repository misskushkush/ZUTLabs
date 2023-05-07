#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iomanip>
using namespace std;

int GenerateRand(int begin, int end);

class Bus {

private:
    class Ticket {
    private:
        int hour;
        int minute;
        double price;
        string cityofDeparture;
        string cityofArrival;

    public:
        friend class Bus;
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
    void setTickets(Ticket** t) { tickets = t; }
    Ticket** getTickets() const { return tickets; }

    int getNumTickets() const { return numTickets; };
    void setNumTickets(int num) { numTickets = num; }

    string getPersonalNumber() const { return personalNumber; }
    void setPersonalNumber(string pn) { personalNumber = pn; }

    //Constructor
    Bus();

    //Copying constructor
    Bus(const Bus& other) : numTickets(other.numTickets), personalNumber(other.personalNumber)
    {
        tickets = new Ticket * [numTickets];
        for (int i = 0; i < numTickets; i++) {
            tickets[i] = new Ticket(*(other.tickets[i])); // create a new Ticket object and copy its value
        }
    }

    Bus& operator=(const Bus& right) {
        if (&right != this)
        {
            this->Bus::~Bus();
            this->Bus::Bus(right);
        }

        return *this;
    }

    Ticket* operator [](const size_t k)
    {
        return tickets[k];
    }


    friend istream& operator>>(istream& input, Bus& Bus) {
        // Read the personal number
        input >> Bus.personalNumber;

        // Read the number of tickets
        input >> Bus.numTickets;

        // Allocate memory for the tickets
        Bus.tickets = new Ticket * [Bus.numTickets];

        // Read each ticket and store it in the tickets array
        for (int i = 0; i < Bus.numTickets; i++) {
            Bus.tickets[i] = new Ticket;
            input >> *(Bus.tickets[i]);
        }

        // Check for errors while reading the input stream
        if (input.fail()) {
            cerr << "Error reading input stream." << endl;
            exit(1);
        }

        return input;
    }

    friend ostream& operator<<(ostream& output, const Bus& Bus) {
        // Write the personal number
        output << Bus.personalNumber << endl;

        // Write the number of tickets
        output << Bus.numTickets << endl;

        // Write each ticket to the output stream
        for (int i = 0; i < Bus.numTickets; i++) {
            output << *(Bus.tickets[i]) << endl;
        }

        return output;
    }

    // Destructor
    ~Bus();

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
