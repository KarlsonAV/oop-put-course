#include <iostream>
#include "Trips.cpp"

using namespace std;

int main() {
    IntercityTrip a(16, 31, 10, 2022, 3, "Poznan", "Warsaw");
    InternationalTrip b(18, 11, 11, 2022, 24, "Poznan", "Munich", "Poland", "Germany");
    b.PrintTripInfo();
}
