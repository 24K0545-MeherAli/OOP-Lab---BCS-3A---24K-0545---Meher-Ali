//TASK # 05 by Meher Ali 24K-0545
#include <iostream>
#include <cstdlib>
using namespace std;

void multiplyMatrices(int* A, int* B, int* C, int m, int n, int p) {//a function to multiply two matrices
    for(int i = 0; i < m; i++) { //-----------------------------------loop for rows of first matrix
        for(int j = 0; j < p; j++) { //-------------------------------loop for columns of second matrix
            *(C + i*p + j) = 0; //------------------------------------initialize result cell with 0
            for(int k = 0; k < n; k++) { //---------------------------loop to perform multiplication & summation
                *(C + i*p + j) += (*(A + i*n + k)) * (*(B + k*p + j));// (row element of A * column element of B) added into C[i][j]
            }
        }
    }
}

int main() {
    system("cls");//--------------------------------------------------to clear terminal before running the program
    int m, n, n2, p; //-----------------------------------------------variables for dimensions of matrices

    cout << "Enter rows and columns of the first matrix: ";
    cin >> m >> n; //-------------------------------------------------taking rows & cols input for first matrix

    cout << "Enter rows and columns of the second matrix: ";
    cin >> n2 >> p; //------------------------------------------------taking rows & cols input for second matrix

    if(n != n2) { //--------------------------------------------------validation: columns of first == rows of second
        cout << "Matrix multiplication not possible. Columns of first must equal rows of second.";
        return 0; //--------------------------------------------------exit program if rule not satisfied
    }

    int* A = new int[m*n]; //-----------------------------------------dynamic allocation for first matrix
    int* B = new int[n2*p]; //----------------------------------------dynamic allocation for second matrix
    int* C = new int[m*p]; //-----------------------------------------dynamic allocation for result matrix

    cout << "Enter elements of the first matrix:\n";
    for(int i = 0; i < m; i++) { //-----------------------------------loop for filling first matrix
        for(int j = 0; j < n; j++) {
            cin >> *(A + i*n + j);
        }
    }

    cout << "Enter elements of the second matrix:\n";
    for(int i = 0; i < n2; i++) { //----------------------------------loop for filling second matrix
        for(int j = 0; j < p; j++) {
            cin >> *(B + i*p + j);
        }
    }

    multiplyMatrices(A, B, C, m, n, p); //----------------------------function call to multiply matrices

    cout << "Resultant Matrix after Multiplication:\n";
    for(int i = 0; i < m; i++) { //-----------------------------------loop for printing result matrix
        for(int j = 0; j < p; j++) {
            cout << *(C + i*p + j) << " "; //-------------------------prints each element in matrix format
        }
        cout << endl;
    }

    delete[] A; //----------------------------------------------------free memory for first matrix
    delete[] B; //----------------------------------------------------free memory for second matrix
    delete[] C; //----------------------------------------------------free memory for result matrix

    return 0;
}
