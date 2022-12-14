#include <iostream>
#include "bus.h"
#include <stdio.h>
#include <cstdlib>
#include <time.h>

using namespace std;

// Class Bus
Bus::Bus() {
    srand(time(0));
    this -> _bus_number = rand() % 300 + 10;
    this -> model = "";
    this -> range = 0;
    this -> number_of_places = 0;
}

Bus::Bus(std::string model, double range, int number_of_places) {
    srand(time(0));
    this -> _bus_number = rand() % 300 + 1;
    this -> model = model;
    this -> range = range;
    this -> number_of_places = number_of_places;
}

void Bus::PrintBusInfo() {
    printf("Bus number: %d\nBus model: %s\nRange - %.2lf km\nNumber of places - %d\n", _bus_number, model.c_str(), range, number_of_places);
}

int Bus::BusNumber() {
    return _bus_number;
}

// Class VipBus
VipBus::VipBus(std::string model, double range, int number_of_places):
Bus::Bus(model, range, number_of_places) {}

void VipBus::PrintBusInfo() {
    printf("VIP Bus number: %d\nVIP Bus model: %s\nRange - %.2lf km\nNumber of places - %d\nIncludes: Wi-Fi, WC and soft seats\n", _bus_number, model.c_str(), range, number_of_places);
}
