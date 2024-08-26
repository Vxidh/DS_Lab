#include<iostream>
using namespace std;

void printpoly(int a, int b, int arr[], int arr1[]){
    cout << "Your first polynomial is: ";
    for(int i = 0; i<a; ++i){
        cout << arr[i];
        if(i != a-1){
            cout << "x^" << (a-i-1) << "+";
        }
    }
    cout << endl;
    cout << "Your second polynomial is: ";
    for(int i = 0; i<b; ++i){
        cout << arr1[i];
        if (i != b-1){
            cout << "x^" << (b-1-i) << "+";
        }
    }
}

void addpoly()