#include "iostream"
#include "manager.h"
#include <stdio.h>

int Manager::AddBus() {
    Bus* bus;
    int bus_type, number_of_places;
    string bus_model;
    double range;

    printf("Select bus type: Ordinary Bus - 1, Vip Bus - 2:\n");
    cin >> bus_type;

    printf("Write a Bus model: ");
    cin >> bus_model;

    printf("\nSpecify Bus range: ");
    cin >> range;

    printf("\nSpecify number of places: ");
    cin >> number_of_places;

    if (bus_type == 1) {
        bus = new Bus(bus_model, range, number_of_places);
    }

    else if (bus_type == 2) {
        bus = new VipBus(bus_model, range, number_of_places);
    }

    else {
        cout << "You have specified incorrect bus type\n";
        return -1;
    }

    buses[bus->BusNumber()] = bus;

    return bus->BusNumber();
}

void Manager::SellTicket() {
    IntercityTrip* trip;
    Ticket* ticket;
    Passenger* passenger;
    string name, surname;
    int age, trip_id, seat_number;

    char ticket_type;
    double ticket_price;
    
    cout << "Choose a Trip" << endl;
    PrintTrips();
    trip = trips[trip_id];

    cout << "Add Passenger Info" << endl;
    cout << "Name: ";
    cin >> name;
    
    cout << endl << "Surname: ";
    cin >> surname;

    cout << endl << "Age: ";
    cin >> age;
    cout << endl;

    passenger = new Passenger(name, surname, age, nullptr);

    cout << "Specify Ticket type:\nr - Regular\nu - Reduced\n";
    cin >> ticket_type;

    cout << "\nTicket Price: ";
    cin >> ticket_price;

    cout << "\nSeat Number: ";
    cin >> seat_number;

    ticket = new Ticket(ticket_type, ticket_price, seat_number, passenger, trip);
    trip -> AddPassenger(passenger, ticket);
}

void Manager::PrintBuses() {
    for (auto bus: buses) {
        cout << bus.first << endl;
        bus.second -> PrintBusInfo();
    }
}

void Manager::PrintTrips() {
    for (auto trip: trips) {
        cout << trip.first << endl;
        trip.second -> PrintTripInfo();
    }
}

void Manager::PrintTripInfo() {
    int trip_id;
    printf("Select a Trip from a list of available Trips:\n");
    cin >> trip_id;
    cout << endl;

    IntercityTrip* trip = trips[trip_id];
    trip -> PrintTripInfo();
}

void Manager::PrintBusInfo() {
    int bus_id;
    printf("Select a Bus from a list of available Buses:\n");
    cin >> bus_id;
    cout << endl;

    Bus* bus = buses[bus_id];
    bus -> PrintBusInfo();
}

int Manager::CreateTrip() {
    IntercityTrip* trip;
    Bus* bus;
    int trip_type, bus_number;
    string departure_time, departure_date, trip_duration;
    string origin_city, destination_city;

    printf("In order to create a Trip, you need to specify the following things:\n");
    printf("Intercity trip - 1, International - 2:\n");
    cin >> trip_type;

    printf("\nWhat is the departure date?:\n");
    cin >> departure_date;

    printf("\nWhat is the departure time?:\n");
    cin >> departure_time;

    printf("\nWhat is the trip duration?:\n");
    cin >> trip_duration;

    printf("\nSpecify the bus from the list of available buses, or add a new one (enter 0 in that case):\n");
    PrintBuses();

    cin >> bus_number;

    if (bus_number == 0) {
        bus_number = AddBus();
    }
    

    printf("Specify origin city: ");
    cin >> origin_city;

    printf("\nSpecify destination city: ");
    cin >> destination_city;
    cout << endl;

    if (trip_type == 1) {
        trip = new IntercityTrip(departure_time, departure_date, trip_duration, vector<Passenger*>(), buses[bus_number], origin_city, destination_city);
    }
    
    else if (trip_type == 2) {
        string origin_country, destination_country;

        printf("Specify origin country: ");
        cin >> origin_country;

        printf("\nSpecify destination country: ");
        cin >> destination_country;

        trip = new InternationalTrip(departure_time, departure_date, trip_duration, vector<Passenger*>(), buses[bus_number], origin_city, destination_city, origin_country, destination_country);
    }

    else {
        return -1;
    }

    trips[trip->Id()] = trip;

    return trip->Id();
}

void Manager::DeleteBus() {
    int bus_number;
    cout << "Specify which bus you'd like to delete" << endl;
    PrintBuses();
    cin >> bus_number;
    
    delete buses[bus_number];
    buses.erase(bus_number);

}

void Manager::DeleteTrip() {
    int trip_id;

    cout << "Specify which trip you'd like to delete" << endl;
    PrintTrips();
    cin >> trip_id;
    
    delete trips[trip_id];
    trips.erase(trip_id);
}