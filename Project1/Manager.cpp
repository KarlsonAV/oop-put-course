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

    if (!cin || bus_type < 1 || bus_type > 2) {
        throw invalid_argument("Incorrect input\n");
    }

    if (bus_type == 1) {
        bus = new Bus(bus_model, range, number_of_places);
    }

    else if (bus_type == 2) {
        bus = new VipBus(bus_model, range, number_of_places);
    }

    else {
        cout << "You have specified incorrect bus type\n";
        throw invalid_argument("Incorrect input\n");
    }

    buses[bus->BusNumber()] = bus;

    cout << "\nBUS ADDED" << endl;
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
    
    cout << "Enter Trip Id" << endl;
    cin >> trip_id;

    cout << endl;
    if (trips.count(trip_id) == 0 ) throw invalid_argument("Invalid Trip Id\n");
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

    if (!cin) {
        throw invalid_argument("Incorrect input\n");
    }

    ticket = new Ticket(ticket_type, ticket_price, seat_number, passenger, trip);
    trip -> AddPassenger(passenger, ticket);

    cout << endl;
    cout << "TICKET SOLD" << endl;
}

int Manager::CreateTrip() {
    IntercityTrip* trip;
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
 
    cin >> bus_number;

    if (bus_number == 0) {
        bus_number = AddBus();
    }
    
    if (buses.count(bus_number) == 0) throw invalid_argument("Invalid Bus number\n");

    printf("Specify origin city: ");
    cin >> origin_city;

    printf("\nSpecify destination city: ");
    cin >> destination_city;
    cout << endl;

    if (!cin) {
        throw invalid_argument("Incorrect input (It should be 1 or 2)\n");
    }

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
        throw invalid_argument("Incorrect input (In should be 1 or 2)\n");
    }

    trips[trip->Id()] = trip;

    return trip->Id();
}


void Manager::PrintInfo() {
    int info_type;

    cout << "Choose what info you'd like to get:\n1 - Print all available Buses\n2 - Print all Trips\n3 - Print specific bus info\n4 - Print specific trip info" << endl;
    cin >> info_type;
    cout << endl;

    switch(info_type) {
        case 1: {
            for (auto bus: buses) {
                bus.second -> PrintBusInfo();
                cout << endl;
            }
            break;
        }

        case 2: {
            for (auto trip: trips) {
                cout << "nr. " << trip.first << endl;
                trip.second -> PrintTripInfo();
                cout << endl;
            }
            break;
        }

        case 3: {
            int bus_id, key_exists;
            printf("Enter Bus number from a list of available Buses:\n");
            cin >> bus_id;
            cout << endl;

            key_exists = buses.count(bus_id);

            if (key_exists) {
                Bus* bus = buses[bus_id];
                bus -> PrintBusInfo();
            }
            
            else {
                throw invalid_argument("Wrong bus number\n");
            }
            
            break;
        }

        case 4: {
            int trip_id, key_exists;
            printf("Enter Trip Id from a list of available Trips:\n");
            cin >> trip_id;
            cout << endl;

            key_exists = trips.count(trip_id);
            if (key_exists) {
                IntercityTrip* trip = trips[trip_id];
                trip -> PrintTripInfo();

                int print_passengers;
                cout << "Would you like to print passengers list?" << endl;
                cout << "1 - Yes\n0 - No" << endl;
                cin >> print_passengers;
                cout << endl;

                if (print_passengers) trip->PrintPassangersList(); 
            }
            else {
                throw invalid_argument("Wrong Trip Id\n");
            }

            break;
        }

        default:
            cout << "Incorrect input, try again" << endl;
    }

}