#include <iostream>
#include "passenger.h"


Passenger::Passenger() {
    this -> name = "";
    this -> surname = "";
    this -> age = 0;
    this -> ticket = nullptr;
}

Passenger::Passenger(string name, string surname, int age, Ticket* ticket) {
    this -> name = name;
    this -> surname = surname;
    this -> age = age;
    this -> ticket = ticket;
}
 
void Passenger::PrintPassengerInfo() {
    printf("Name and surname: %s %s\nAge: %d\n", name.c_str(), surname.c_str(), age);
}

void Passenger::PrintTicket() {
    ticket -> PrintTicket();
}

void Passenger::BuyTicket(Ticket* ticket) {
    this -> ticket = ticket;
}