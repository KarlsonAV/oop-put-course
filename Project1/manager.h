#include "trip.h"
#include <unordered_map>

class Manager {
private:
    unordered_map<int, IntercityTrip*> trips;
    unordered_map<int, Bus*> buses;
public:
    int CreateTrip();
    int AddBus();
    void PrintTripInfo();
    void PrintBusInfo();
    void PrintTrips();
    void DeleteBus();
    void DeleteTrip();
    void PrintBuses();
    void SellTicket();
};