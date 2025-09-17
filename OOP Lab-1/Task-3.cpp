//TASK#03 by Meher Ali - 24K0545
#include <iostream>
#include <math.h>
#include <cstdlib>
using namespace std;

bool checkIfPrime(int num) {//-----------------------------------this function checks if the number is prime or not
    if (num <= 1)//----------------------------------------------if the number is 1 or negative, its neglected;
        return false;                                            
    for (int i = 2; i <= sqrt(num); i++) {//---------------------checking the factors of the number
        if (num % i == 0)//--------------------------------------if the ramainder of the number and its factor is 0 then its not prime
            return false;
    }
    return true;//-----------------------------------------------if neither of the conditions are false, then the number is prime
}

void FindPrimeInRange(int start,int end) {//---------------------function to check the primes in a range of two numbers
    cout << "The Prime Numbers between "//-----------------------a prompt
         << start << " and " << end << "are: " << endl;
    for (int i = start; i <= end; i++) {//-----------------------a loop which puts every number in the checkIfPrime() function to check if its prime or not
        if (checkIfPrime(i) == true) {//-------------------------if a number is prime, its printed through the prompt inside the if-block
            cout << i << " ";
        }
    }
}
int main(){
    system("cls");//---------------------------------------------system("cls") to clear terminal
    int start, end;//--------------------------------------------initialization of two integers
    cout << "Enter the start of Range: "; cin >> start;//--------input from user
    cout << "Enter the end of the range: "; cin >> end;//--------input from user
    FindPrimeInRange(start, end);//------------------------------vlue passed through the function to check the prime numbers between 'start' and 'end'
    return 0;
}