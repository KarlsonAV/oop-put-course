#pragma once
#include <string>
#include <stdio.h>
#include "bus.h"
#include "passenger.h"
#include <vector>

using namespace std;

class Passenger;
class Ticket;

class Trip {
protected:
    int _id;
    string departure_time;
    string departure_date;
    string trip_duration;
    vector<Passenger*> passengers;
    Bus* bus;
    void PrintTime();
    

public:
    Trip(string departure_time, string departure_date, string trip_duration, vector<Passenger*> passengers, Bus* bus);
    virtual void PrintTripInfo() = 0;
    void PrintPassangersList();
    int Id();
    void AddPassenger(Passenger* passenger, Ticket* ticket);
};

class IntercityTrip: public Trip {
protected:
    std::string origin_city;
    std::string destination_city;

public:
    IntercityTrip();
    IntercityTrip(string departure_time, string depature_date, string trip_duration, vector<Passenger*> passengers, Bus* bus, std::string origin_city, std::string destination_city);
    void PrintTripInfo();
};

class InternationalTrip: public IntercityTrip {
private:
    std::string origin_country;
    std::string destination_country;

public:
    InternationalTrip();
    InternationalTrip(string departure_time, string depature_date, string trip_duration, vector<Passenger*> passengers, Bus* bus, std::string origin_city, std::string destination_city, std::string origin_country, std::string destination_country);
    void PrintTripInfo();
};