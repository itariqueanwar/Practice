#include <bits/stdc++.h>
#define ROWS 901
#define COLS 901
using namespace std;

int matrix[901][901]; // Global declaration of matrix to avoid redeclaration for each testcase

// Function to modify the matrix based on the presence of 1s in each row
void booleanMatrix(int matrix[ROWS][COLS], int m, int n) {
    // Create an array to keep track of whether each row needs to be filled with 1s
    bool fill_row[m] = {false};
    
    // Iterate over each row of the matrix
    for (int i = 0; i < m; i++) {
        // Check if the current row contains at least one 1
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 1) {
                // If 1 is found, mark the row to be filled with 1s
                fill_row[i] = true;
                break;
            }
        }
    }
    
    // Iterate over each row of the matrix again
    for (int i = 0; i < m; i++) {
        // If the current row needs to be filled with 1s
        if (fill_row[i]) {
            // Set all elements of the row to 1
            for (int j = 0; j < n; j++) {
                matrix[i][j] = 1;
            }
        }
    }
}