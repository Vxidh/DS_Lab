#include <iostream>
using namespace std;
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int n;

    cout << "Enter the position in the Fibonacci sequence: ";
    cin >> n;

    if (n < 0) {
        cout << "Fibonacci is not defined for negative numbers." << endl;
    } else {
        cout << "Fibonacci number at position " << n << " is " << fibonacci(n) << endl;
    }

    return 0;
}
