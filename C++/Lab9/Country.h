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
    using CityStationsMap = map<string, unique_ptr<Station>>;

    CityStationsMap cityStationsMap;

public:
    void insert(const string& city, unique_ptr<Station> station) {
        cityStationsMap.insert(make_pair(city, move(station)));
    }

    void emplace(const string& city, unique_ptr<Station> station) {
        cityStationsMap.emplace(city, move(station));
    }

    template <typename T>
    unique_ptr<T> get(const string& city) {
        auto it = cityStationsMap.find(city);
        if (it != cityStationsMap.end()) {
            unique_ptr<Station>& station = it->second;
            T* typedStation = dynamic_cast<T*>(station.get());
            if (typedStation) {
                return unique_ptr<T>(static_cast<T*>(station.release()));
            }
        }
        return nullptr;
    }

    bool find(const string& city) {
        return (cityStationsMap.find(city) != cityStationsMap.end());
    }

    void erase(const string& city) {
        cityStationsMap.erase(city);
    }

    void addStationToCity(const string& city, unique_ptr<Station> station) {
        cityStationsMap[city] = move(station);
    }
};

#endif