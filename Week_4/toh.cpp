#include <iostream>

using namespace std;

void towerOfHanoi(int n, char fromRod, char toRod, char auxRod) {
    if (n == 1) {
        cout << "Move disk 1 from rod " << fromRod << " to rod " << toRod << endl;
        return;
    }
    towerOfHanoi(n - 1, fromRod, auxRod, toRod);
    cout << "Move disk " << n << " from rod " << fromRod << " to rod " << toRod << endl;
    towerOfHanoi(n - 1, auxRod, toRod, fromRod);
}

int main() {
    int n;

    cout << "Enter the number of disks: ";
    cin >> n;

    if (n < 1) {
        cout << "Number of disks must be a positive integer." << endl;
    } else {
        cout << "The sequence of moves to solve the Tower of Hanoi puzzle is:" << endl;
        towerOfHanoi(n, 'A', 'C', 'B'); 
    }

    return 0;
}
