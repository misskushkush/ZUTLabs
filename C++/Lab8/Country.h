#ifndef COUNTRY_H
#define COUNTRY_H
#include <iostream>
#include <map>
#include <string>
#include "Station.h"
#include <map>

using namespace std;
class Country {
private:
    using CityStationsMap = map<string, Station*>;

    CityStationsMap cityStationsMap;

public:
    void insert(const string& city, Station* station) {
        cityStationsMap.insert(make_pair(city, station));
    }

    void emplace(const string& city, Station* station) {
        cityStationsMap.emplace(city, station);
    }

    template <typename T>
    T* get(const std::string& city) {
        auto it = cityStationsMap.find(city);
        if (it != cityStationsMap.end()) {
            Station* station = it->second;
            return dynamic_cast<T*>(station);
        }
        else {
            return nullptr;
        }
    }

    bool find(const std::string& city) {
        return (cityStationsMap.find(city) != cityStationsMap.end());
    }

    void erase(const string& city) {
        cityStationsMap.erase(city);
    }

    void addStationToCity(const string& city, Station* station) {
        cityStationsMap[city] = station;
    }
};


#endif