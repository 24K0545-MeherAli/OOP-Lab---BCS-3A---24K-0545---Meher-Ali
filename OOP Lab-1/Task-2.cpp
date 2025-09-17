//TASK#02 by Meher Ali - 24K-0545
#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    system("cls");//-----------------------------------------------to clear terminal
    int rows;//----------------------------------------------------initializes rows variable and takes input from the user
    cout << "Enter the Number of Rows: ";
    cin >> rows;

    char alphabets[26];//------------------------------------------creates an array of alphabets and generates every letter and stores it in the array
    for (int i = 0; i < 26; i++) {
        alphabets[i] = 'A' + i;
    }

    for (int i = 1; i <= rows; i++) {//----------------------------loop to print top half (including middle row)           
        for (int space = 1; space <= rows - i; space++) {//--------print spaces
            cout << " ";
        }
        for (int j = 0; j < 2 * i - 1; j++) {//--------------------print alphabets until 2*i - 1
            cout << alphabets[j];
        }
        cout << "\n";//--------------------------------------------new line
    }

    for (int i = rows - 1; i >= 1; i--) {//------------------------loop to print bottom half (excluding middle row)
        for (int space = 1; space <= rows - i; space++) {//--------print spaces
            cout << " ";
        }
        for (int j = 0; j < 2 * i - 1; j++) {//--------------------print alphabets until 2*i - 1
            cout << alphabets[j];
        }
        cout << "\n";//--------------------------------------------znew line
    }

    return 0;
}
