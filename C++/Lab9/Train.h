#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iomanip>
#include <vector>
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
            vector<string> cities = { "New York", "Washington D.C.", "Los Angeles", "San Francisco", "Chicago", "Houston" };

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
    vector<unique_ptr<Ticket>> tickets;
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
    void setTickets(vector<unique_ptr<Ticket>> t) { tickets = std::move(t); }
    const vector<unique_ptr<Ticket>>& getTickets() const { return tickets; }

    int getNumTickets() const { return numTickets; };
    void setNumTickets(int num) { numTickets = num; }

    string getPersonalNumber() const { return personalNumber; }
    void setPersonalNumber(string pn) { personalNumber = pn; }

    Ticket* getTicket(int index) const {
        if (index < 0 || index >= numTickets) {
            // Handle out-of-bounds index
            return nullptr;
        }
        return tickets[index].get();
    }

    // Print function
    void print();

    //Constructor
    Train();

    //Copying constructor
    Train(const Train& other);

    Train& operator=(const Train& right) {
        if (&right != this)
        {
            this->Train::Train(right);
        }

        return *this;
    }

    Ticket* operator [](const size_t k)
    {
        return tickets[k].get();
    }


    friend istream& operator>>(istream& input, Train& Train) {
        // Read the personal number
        input >> Train.personalNumber;

        // Read the number of tickets
        input >> Train.numTickets;

        // Allocate memory for the tickets
        Train.tickets.clear();
        for (int i = 0; i < Train.numTickets; i++) {
            Train.tickets.push_back(make_unique<Ticket>());
            input >> *(Train.tickets[i]);
        }

        // Check for errors while reading the input stream
        if (input.fail()) {
            cerr << "Error reading input stream." << endl;
            exit(1);
        }

        return input;
    }

    friend ostream& operator<<(ostream& output, const Train& Train) {
        // Write the personal number
        output << Train.personalNumber << endl;

        // Write the number of tickets
        output << Train.numTickets << endl;

        // Write each ticket to the output stream
        for (int i = 0; i < Train.numTickets; i++) {
            output << *(Train.tickets[i]) << endl;
        }

        return output;
    }

};
