#include <iostream>
using namespace std;


struct Triplet {
    int row;
    int col;
    int value;
};


const int MAX_ROWS = 100;
const int MAX_COLS = 100;
const int MAX_TRIPLETS = MAX_ROWS * MAX_COLS; // Assumes at most every element is non-zero


void createTriplets(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols, Triplet triplets[MAX_TRIPLETS], int& numTriplets) {
    numTriplets = 0;

    // Populate the triplets array
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] != 0) {
                triplets[numTriplets].row = i;
                triplets[numTriplets].col = j;
                triplets[numTriplets].value = matrix[i][j];
                ++numTriplets;
            }
        }
    }
}
// Function to reconstruct a matrix from an array of triplets
void reconstructMatrix(const Triplet triplets[MAX_TRIPLETS], int numTriplets, int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = 0;
        }
    }
    for (int i = 0; i < numTriplets; ++i) {
        int row = triplets[i].row;
        int col = triplets[i].col;
        int value = triplets[i].value;

        if (row < rows && col < cols) {
            matrix[row][col] = value;
        }
    }
}

void printMatrix(const int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
    cout << "Matrix:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int rows = 4, cols = 4;

    // Create a sparse matrix
    int matrix[MAX_ROWS][MAX_COLS] = {0}; // Initialize with zeros

    // Example matrix
    matrix[0][2] = 3;
    matrix[1][0] = 4;
    matrix[2][1] = 5;
    matrix[2][3] = 6;

    Triplet triplets[MAX_TRIPLETS];
    int numTriplets;

    // Convert matrix to triplets
    createTriplets(matrix, rows, cols, triplets, numTriplets);

    // Reconstruct matrix from triplets
    int reconstructedMatrix[MAX_ROWS][MAX_COLS];
    reconstructMatrix(triplets, numTriplets, reconstructedMatrix, rows, cols);

    // Print the reconstructed matrix
    printMatrix(reconstructedMatrix, rows, cols);

    return 0;
}
