#include "trip.h"
#include <unordered_map>

class Manager {
private:
    unordered_map<int, IntercityTrip*> trips;
    unordered_map<int, Bus*> buses;
public:
    int CreateTrip();
    int AddBus();
    void PrintInfo();
    void SellTicket();
};