#include <iostream>
using namespace std;

class Flight {
private:
    int Flight_Number;
    char Destination[100];
    float fuel = 13.2;
    float distance;

    void calculate_fuel(int n) {
        if (n <= 1000) {
            fuel = 500;
        } else if (n > 1000 && n <= 2000) {
            fuel = 1100;
        } else {
            fuel = 2200;
        }
    }

public:
    void information_entry() {
        cout << "Enter your flight number: ";
        cin >> Flight_Number;
        cin.ignore(); // Ignore any leftover newline character in the input buffer
        cout << "Enter your destination: ";
        cin.getline(Destination, 100);
        cout << "Enter the distance: ";
        cin >> distance;
        calculate_fuel(distance);
    }

    void display_info() const {
        cout << "Flight Number: " << Flight_Number << endl;
        cout << "Destination: " << Destination << endl;
        cout << "Distance: " << distance << " km" << endl;
        cout << "Fuel Required: " << fuel << " liters" << endl;
    }
};

int main() {
    Flight f1;
    f1.information_entry();
    f1.display_info();
    return 0;
}
