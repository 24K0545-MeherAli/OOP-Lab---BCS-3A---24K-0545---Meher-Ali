//TASK#01 by Meher Ali - 24K-0545
#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    system("cls");//----------------------------------------------------------to clear terminal
    int amount;
    cout << "Enter amount: ";//-----------------------------------------------takes input from the user
    cin >> amount;

    int denominations[] = {5000, 1000, 500, 100, 20, 10, 5, 2, 1};//----------initializes an array of denominations given 
    int size = sizeof(denominations) / sizeof(denominations[0]);//------------calculates the size of the array

    cout << "Minimum notes required for Rs. " << amount << " are:" << endl;

    for (int i = 0; i < size; i++) {//----------------------------------------this loop runs for the size of the array
        if (amount >= denominations[i]) {//-----------------------------------checks if the amount is greater than or equal to the denomination
            int count = amount / denominations[i];//--------------------------calculates the number of notes required for that denomination
            amount %= denominations[i];//-------------------------------------updates the amount to the remainder after using that denomination
            cout << denominations[i] << " x " << count << endl;//-------------prints the denomination and the number of notes required
        }
    }

    return 0;
}
