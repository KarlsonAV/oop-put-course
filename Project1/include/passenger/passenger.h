#pragma once
#include <string>
#include "ticket.h"

using namespace std;
class Ticket;

class Passenger {
private:
    string name;
    string surname;
    int age;
    Ticket* ticket;

public:
    Passenger();
    Passenger(string name, string surname, int age, Ticket* ticket);

    void BuyTicket(Ticket* ticket);
    void PrintPassengerInfo();
    void PrintTicket();
};
