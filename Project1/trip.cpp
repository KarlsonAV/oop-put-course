#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cstdlib>
#include "trip.h"
#include <string>
#include <stdio.h>
#include <cstdlib>
#include <time.h>

// Class Trip
Trip::Trip(string departure_time, string departure_date, string trip_duration, vector<Passenger*> passengers, Bus* bus) {
    srand(time(0));
    this -> _id = (rand() % 9999) + 1000;
    this -> departure_time = departure_time;
    this -> departure_date = departure_date;
    this -> trip_duration = trip_duration;
    this -> passengers = passengers;
    this -> bus = bus;
}

void Trip::PrintTime() {
    cout << "Depature date: " << departure_date << endl;
    cout << "Depature time: " << departure_time << endl;
    cout << "Trip duration: " << trip_duration << endl;
}

void Trip::PrintPassangersList() {
    for (Passenger* p: passengers) {
        p -> PrintPassengerInfo();
    }
}

int Trip::Id() {
    return _id;
}

void Trip::AddPassenger(Passenger* passenger, Ticket* ticket) {
    passenger->BuyTicket(ticket);
    passengers.push_back(passenger);
}

// Class Intercity Trip
IntercityTrip::IntercityTrip():
Trip::Trip("", "", "", vector<Passenger*>(), nullptr) {
    this -> origin_city = "";
    this -> destination_city = "";
}

IntercityTrip::IntercityTrip(string departure_time, string departure_date, string trip_duration, vector<Passenger*> passengers, Bus* bus, std::string origin_city, std::string destination_city):
Trip::Trip(departure_time, departure_date, trip_duration, passengers, bus) {
    this -> origin_city = origin_city;
    this -> destination_city = destination_city;
}

void IntercityTrip::PrintTripInfo() {
    cout << "Intercity Trip" << endl;
    printf("From: %s\nTo: %s\n", origin_city.c_str(), destination_city.c_str());
    PrintTime();
}


// Class InternationalTrip
InternationalTrip::InternationalTrip():
IntercityTrip::IntercityTrip("", "", "", vector<Passenger*>(), nullptr, "", "") {
    this -> origin_country = "";
    this -> destination_country = "";
}

InternationalTrip::InternationalTrip(string departure_time, string depature_date, string trip_duration, vector<Passenger*> passengers, Bus* bus, std::string origin_city, std::string destination_city, std::string origin_country, std::string destination_country):
IntercityTrip::IntercityTrip(departure_time, departure_date, trip_duration, passengers, bus, origin_city, destination_city) {
    this -> origin_country = origin_country;
    this -> destination_country = destination_country;
}

void InternationalTrip::PrintTripInfo() {
    cout << "International trip" << endl;
    printf("From: %s, %s\nTo: %s, %s\n", origin_country.c_str(), origin_city.c_str(), destination_country.c_str(), destination_city.c_str());
    PrintTime();
}
