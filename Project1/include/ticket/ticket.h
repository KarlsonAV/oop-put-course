#pragma once
#include "trip.h"
#include "passenger.h"


using namespace std;

class Passenger;
class IntercityTrip;

class Ticket {
protected:
    char ticket_type;
    double price;
    int seat_number;
    Passenger* passenger;
    IntercityTrip *trip;

public:
    Ticket();
    Ticket(char ticket_type, double price, int seat_number, Passenger* passenger, IntercityTrip *trip);
    void PrintTicket();
};