#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iomanip>
using namespace std;

int GenerateRand(int begin, int end);

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

    virtual double calculatePrice() const = 0;

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

