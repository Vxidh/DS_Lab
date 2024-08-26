#include <iostream>
#include <algorithm> // For std::max
using namespace std;

void printpoly(int size, int arr[]) {
    if (size == 0) {
        cout << "0";
        return;
    }
    
    for (int i = 0; i < size; ++i) {
        if (arr[i] != 0) {
            if (i != 0 && arr[i] > 0) {
                cout << "+";
            }
            cout << arr[i];
            if (i != size - 1) {
                cout << "x^" << (size - i - 1);
            }
        }
    }
    cout << endl;
}

void addpoly(int a, int b, int arr[], int arr1[], int result[]) {
    int maxSize = max(a, b);
    for (int i = 0; i < maxSize; ++i) {
        int coeff1 = (i < a) ? arr[i] : 0;
        int coeff2 = (i < b) ? arr1[i] : 0;
        result[i] = coeff1 + coeff2;
    }
}

int main() {
    int a, b;
    cout << "Enter number of elements in first polynomial: ";
    cin >> a;
    cout << "Enter number of elements in second polynomial: ";
    cin >> b;
    
    int maxSize = max(a, b);
    int pol1[a], pol2[b], result[maxSize];
    
    cout << "Enter your co-efficients for the first polynomial." << endl;
    for (int i = 0; i < a; ++i) {
        cout << "x^" << (a - i - 1) << ": ";
        cin >> pol1[i];
    }
    
    cout << "Enter your co-efficients for the second polynomial." << endl;
    for (int i = 0; i < b; ++i) {
        cout << "x^" << (b - i - 1) << ": ";
        cin >> pol2[i];
    }
    
    cout << "Your first polynomial is: ";
    printpoly(a, pol1);
    
    cout << "Your second polynomial is: ";
    printpoly(b, pol2);
    
    addpoly(a, b, pol1, pol2, result);
    
    cout << "The sum of the 2 polynomials is: ";
    printpoly(maxSize, result);
    
    return 0;
}
