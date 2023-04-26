#include <iostream>
#include <cstdlib>

using namespace std;

class Ticket {
private:
    int hour;
    int minute;
    double price;
    string cityofDeparture;
    string cityofArrival;

public:
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
    Ticket();

    //Copying constructor
    Ticket(const Ticket& other);

    // Constructor with parameters
    Ticket(int h, int m, double p, string dep, string arr);

    // Print function
    void print() const;
};


