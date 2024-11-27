// File name: Chapter 7 Exercise 21
// programmer name : Ebram Azer
// Date: Nov 24
// Requirments:
//Write a program that creates a two - dimensional array initialized with test data.Use any data type you wish.The program should have the following functions :
//• getTotal—This  function  should  accept  a  two - dimensional  array  as  its  argument and return the total of all the values in the array.
//• getAverage—This function should accept a two - dimensional array as its argument and return the average of all the values in the array.
//• getRowTotal—This  function  should  accept  a  two - dimensional  array  as  its  first  argument and an  
// integer  as  its  second  argument.The  second  argument  should  be  the subscript of a row in the array.The function should return the total of the values in the specified row.
//• getColumnTotal—This function should accept a two - dimensional array as its first argument and an
// integer as its second argument.The second argument should be the subscript of a column in the array.
// The function should return the total of the values in the specified column.
//• getHighestInRow—This function should accept a two - dimensional array as its first argument and an integer as
// its second argument.The second argument should be the subscript of a row in the array.The function should return the highest value in the specified row of the array.
//• getLowestInRow—This function should accept a two - dimensional array 
// as its first argument and an  integer  as  its  second  argument.The  second  argument  should  be 
// the subscript of a row in the array.The function should return the lowest value in the
//Display the options in a menu to call the various functions.



#include <iostream>
#include <limits> // For numeric_limits
using namespace std;

// Function prototypes
double getTotal(const int array[][4], int rows, int cols);
double getAverage(const int array[][4], int rows, int cols);
int getRowTotal(const int array[][4], int row, int cols);
int getColumnTotal(const int array[][4], int rows, int col);
int getHighestInRow(const int array[][4], int row, int cols);
int getLowestInRow(const int array[][4], int row, int cols);

int main() {
    // 2D array initialization
    const int rows = 3, cols = 4;
    int testArray[rows][cols] = {
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {50, 60, 70, 80}
    };

    int choice, rowOrCol;
    do {
        // Menu
        cout << "\nMenu:\n";
        cout << "1. Get Total\n";
        cout << "2. Get Average\n";
        cout << "3. Get Row Total\n";
        cout << "4. Get Column Total\n";
        cout << "5. Get Highest in Row\n";
        cout << "6. Get Lowest in Row\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: // Total
            cout << "Total of all values: " << getTotal(testArray, rows, cols) << endl;
            break;

        case 2: // Average
            cout << "Average of all values: " << getAverage(testArray, rows, cols) << endl;
            break;

        case 3: // Row Total
            cout << "Enter the row (0 to " << rows - 1 << "): ";
            cin >> rowOrCol;
            if (rowOrCol >= 0 && rowOrCol < rows) {
                cout << "Total of row " << rowOrCol << ": " << getRowTotal(testArray, rowOrCol, cols) << endl;
            }
            else {
                cout << "Invalid row index.\n";
            }
            break;

        case 4: // Column Total
            cout << "Enter the column (0 to " << cols - 1 << "): ";
            cin >> rowOrCol;
            if (rowOrCol >= 0 && rowOrCol < cols) {
                cout << "Total of column " << rowOrCol << ": " << getColumnTotal(testArray, rows, rowOrCol) << endl;
            }
            else {
                cout << "Invalid column index.\n";
            }
            break;

        case 5: // Highest in Row
            cout << "Enter the row (0 to " << rows - 1 << "): ";
            cin >> rowOrCol;
            if (rowOrCol >= 0 && rowOrCol < rows) {
                cout << "Highest in row " << rowOrCol << ": " << getHighestInRow(testArray, rowOrCol, cols) << endl;
            }
            else {
                cout << "Invalid row index.\n";
            }
            break;

        case 6: // Lowest in Row
            cout << "Enter the row (0 to " << rows - 1 << "): ";
            cin >> rowOrCol;
            if (rowOrCol >= 0 && rowOrCol < rows) {
                cout << "Lowest in row " << rowOrCol << ": " << getLowestInRow(testArray, rowOrCol, cols) << endl;
            }
            else {
                cout << "Invalid row index.\n";
            }
            break;

        case 7: // Exit
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);

    return 0;
}

// Function definitions
double getTotal(const int array[][4], int rows, int cols) {
    double total = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            total += array[i][j];
        }
    }
    return total;
}

double getAverage(const int array[][4], int rows, int cols) {
    double total = getTotal(array, rows, cols);
    return total / (rows * cols);
}

int getRowTotal(const int array[][4], int row, int cols) {
    int total = 0;
    for (int j = 0; j < cols; j++) {
        total += array[row][j];
    }
    return total;
}

int getColumnTotal(const int array[][4], int rows, int col) {
    int total = 0;
    for (int i = 0; i < rows; i++) {
        total += array[i][col];
    }
    return total;
}

int getHighestInRow(const int array[][4], int row, int cols) {
    int highest = numeric_limits<int>::min();
    for (int j = 0; j < cols; j++) {
        if (array[row][j] > highest) {
            highest = array[row][j];
        }
    }
    return highest;
}

int getLowestInRow(const int array[][4], int row, int cols) {
    int lowest = numeric_limits<int>::max();
    for (int j = 0; j < cols; j++) {
        if (array[row][j] < lowest) {
            lowest = array[row][j];
        }
    }
    return lowest;
}





