//TASK#4 by Meher Ali - 24K0545
#include <iostream>
using namespace std;

int main() {
    system("cls");
    int n;                                            //-------------------variable to store size of matrix
    cout << "Enter size of square matrix (N): ";      //-------------------prompt user to enter size
    cin >> n;                                         //-------------------take input for size

    int** matrix = new int*[n];                       //-------------------dynamically allocate memory for rows
    for (int i = 0; i < n; i++) {                     //-------------------loop to allocate memory for each columns
        matrix[i] = new int[n];                       //-------------------each row points to an array of n integers
    }

    cout << "Enter elements of the matrix:" << endl;
    for (int i = 0; i < n; i++) {                     //-------------------loop through rows
        for (int j = 0; j < n; j++) {                 //-------------------loop through columns
            cin >> matrix[i][j];                      //-------------------take input for each element
        }
    }

    int mainDiagonalSum = 0;                          //-------------------variable to store sum of main diagonal
    int secondaryDiagonalSum = 0;                     //-------------------variable to store sum of secondary diagonal

    for (int i = 0; i < n; i++) {                     //-------------------loop through rows
        mainDiagonalSum += matrix[i][i];              //-------------------add element where row == column
        secondaryDiagonalSum += matrix[i][n - i - 1]; //-------------------add element where row + col == n - 1
    }

    cout << "\nMatrix:" << endl;                      //-------------------display the matrix
    for (int i = 0; i < n; i++) {                     //-------------------loop through rows
        for (int j = 0; j < n; j++) {                 //-------------------loop through columns
            cout << matrix[i][j] << " ";              //-------------------print each element with space
        }
        cout << endl;                                 //-------------------move to next line after each row
    }

    cout << "\nSum of main diagonal = " 
         << mainDiagonalSum << endl;                  //-------------------display main diagonal sum
    cout << "Sum of secondary diagonal = " 
         << secondaryDiagonalSum << endl;             //-------------------display secondary diagonal sum

    for (int i = 0; i < n; i++) {                     //-------------------loop to free memory for each row
        delete[] matrix[i];                           //-------------------deallocate memory for row
    }
    delete[] matrix;                                  //-------------------deallocate memory for row pointers

    return 0;
}
