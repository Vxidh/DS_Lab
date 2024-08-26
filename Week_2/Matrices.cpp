#include <iostream>
using namespace std;

void UTM(int arr[][3], int size, int result[]) {
    int index = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = i; j < size; ++j) {
            result[index++] = arr[i][j];
        }
    }
}

void LTM(int arr[][3], int size, int result[]) {
    int index = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j <= i; ++j) {
            result[index++] = arr[i][j];
        }
    }
}

void DM(int arr[][3], int size, int result[]) {
    for (int i = 0; i < size; ++i) {
        result[i] = arr[i][i];
    }
}

void TDM(int arr[][4], int size, int result[]) {
    int index = 0;
    for (int i = 0; i < size; ++i) {
        if (i > 0) result[index++] = arr[i][i - 1]; // Lower diagonal
        result[index++] = arr[i][i]; // Main diagonal
        if (i < size - 1) result[index++] = arr[i][i + 1]; // Upper diagonal
    }
}

void RowMajor(int arr[][3], int rows, int cols, int result[]) {
    int index = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[index++] = arr[i][j];
        }
    }
}

void ColumnMajor(int arr[][3], int rows, int cols, int result[]) {
    int index = 0;
    for (int j = 0; j < cols; ++j) {
        for (int i = 0; i < rows; ++i) {
            result[index++] = arr[i][j];
        }
    }
}

void print1DArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int size = 3;
    int result[9];
    
    UTM(arr, size, result);
    cout << "Upper Triangle Matrix: ";
    print1DArray(result, size * (size + 1) / 2);
    
    LTM(arr, size, result);
    cout << "Lower Triangle Matrix: ";
    print1DArray(result, size * (size + 1) / 2);
    
    DM(arr, size, result);
    cout << "Diagonal Matrix: ";
    print1DArray(result, size);
    
    int arr4[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    int result4[12];
    
    TDM(arr4, size, result4);
    cout << "Tri-Diagonal Matrix: ";
    print1DArray(result4, size * 3 - 2);
    
    RowMajor(arr, size, size, result);
    cout << "Row Major Order: ";
    print1DArray(result, size * size);
    
    ColumnMajor(arr, size, size, result);
    cout << "Column Major Order: ";
    print1DArray(result, size * size);
    
    return 0;
}
