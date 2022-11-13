#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;


class Trip {
protected:
    int time;
    int day;
    int month;
    int year;
    int trip_duration;

    void ShowTime() {
        printf("%d/%d/%d %d:00\nTrip Duration - %dh\n", day, month, year, time, trip_duration);
    }

public:
    Trip(int time, int day, int month, int year, int trip_duration) {
        this -> time = time;
        this -> day = day;
        this -> month = month;
        this -> year = year;
        this -> trip_duration = trip_duration;
    }

    virtual void PrintTripInfo() = 0;
};

class IntercityTrip: public Trip {
protected:
    string origin_city;
    string destination_city;

public:
    IntercityTrip(int time, int day, int month, int year, int trip_duration, string origin_city, string destination_city):
    Trip(time, day, month, year, trip_duration) {
        this -> origin_city = origin_city;
        this -> destination_city = destination_city;
    }

    void PrintTripInfo() {
        cout << "Intercity Trip" << endl;
        printf("From: %s\nTo: %s\n", origin_city.c_str(), destination_city.c_str());
        ShowTime();
    }
};

class InternationalTrip: IntercityTrip {
private:
    string origin_country;
    string destination_country;

public:
    InternationalTrip(int time, int day, int month, int year, int trip_duration, string origin_city, string destination_city, string origin_country, string destination_country):
    IntercityTrip(time, day, month, year, trip_duration, origin_city, destination_city) {
        this -> origin_country = origin_country;
        this -> destination_country = destination_country;
    }

    void PrintTripInfo() {
        cout << "International" << endl;
        printf("From: %s, %s\nTo: %s, %s\n", origin_country.c_str(), origin_city.c_str(), destination_country.c_str(), destination_city.c_str());
        ShowTime();
    }
};

