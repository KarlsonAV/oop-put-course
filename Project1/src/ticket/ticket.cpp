#include <iostream>
#include "ticket.h"
#include <stdio.h>

// Class Ticket
Ticket::Ticket() {
    this -> ticket_type = ' ';
    this -> price = 0;
    this -> seat_number = 0;
    this -> trip = nullptr;
    this -> passenger = nullptr;
}


Ticket::Ticket(char ticket_type, double price, int seat_number, Passenger* passenger, IntercityTrip *trip) {
    this -> ticket_type = ticket_type;
    this -> price = price;
    this -> seat_number = seat_number;
    this -> passenger = passenger;
    this -> trip = trip;
}

void Ticket::PrintTicket() {
    cout << endl << "Ticket type: " << ticket_type << endl;
    cout << "Ticket price: " << price << "$" << endl;
    cout << "---------------" << endl;
    cout << "Passanger info" << endl;
    cout << "---------------" << endl;
    passenger -> PrintPassengerInfo();
    cout << "---------------" << endl;
    cout << "Trip info" << endl;
    cout << "---------------" << endl;
    trip -> PrintTripInfo();
} 
