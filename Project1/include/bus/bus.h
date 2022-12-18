#pragma once

#include <vector>
#include <stdio.h>
#include <string>

class Bus {
protected:
    int _bus_number;
    std::string model;
    double range;
    int number_of_places;

public:
    Bus();
    Bus(std::string model, double range, int number_of_places);
    virtual void PrintBusInfo();
    int BusNumber();
};


class VipBus: public Bus {
public:
    VipBus(std::string model, double range, int number_of_places);
    void PrintBusInfo() override;
};
