#include <iostream>
#include "manager.h"

using namespace std;

int main() {
    printf("Welcome to the Bus Manager application created by Andrei Kartavik!!!\nThe goal of this project is to make a simple application, which can help you to manage your Bus company\nThe functionality of the application is restricted due to the specifications of the project size\nHope you'd enjoy it!\n");
    cout << endl;

    Manager manager;
    
    string action;
    while (true) {
        cout << endl;
        printf(
            "Choose an action:\n"
            "1 - Add Bus\n"
            "2 - Create Trip\n"
            "3 - Print Info\n"
            "4 - Sell Ticket\n"
            "0 - exit\n"
        );
        cout << endl;
        cin >> action;
        cout << endl;

        try {
            if (action == "1") {
                manager.AddBus();
            }
            else if (action == "2") {
                manager.CreateTrip();
            }
            else if (action == "3") {
                manager.PrintInfo();
            }
            else if (action == "4") {
                manager.SellTicket();
            }
            else if (action == "0") {
                cout << "Exit" << endl;
                return 0;
            }
            else {
                cout << "Incorrect input, try again\n";
            }
        }
        catch(exception &e) {
            cout << "\nYou've got an error:" << endl << e.what();
            return -1;
        }
    }
}