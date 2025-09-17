//TASK#1 by Meher Ali - 24K0545
#include <iostream>
#include <string.h>
using namespace std;

int swapValues(int *a, int *b){//----------------------a function to swap values which takes address of two var
    *a = *a - *b;//------------------------------------it stores difference of two values first
    *b = *a + *b;//------------------------------------then stores the sum of the difference(*a) and the actual value(*b) in the next var
    *a = *b - *a;//------------------------------------then it subtracts the sum and difference of both vars
    return *a, *b;//-----------------------------------finally return the swapped addresses of the val

}

int main() {
    system("cls");//-----------------------------------to clean the terminal before running the program

    int a,b;//-----------------------------------------initialization of integers

    cout << "Enter a: ";
    cin >> a;//----------------------------------------taking 'a' input
    cout << "Enter b: ";
    cin >> b;//----------------------------------------taking 'b' input

    cout << "Before Swapping: " << endl;//-------------a prompt which prints both values before swapping
    cout << "a: " << a << endl;
    cout << "b: " << b << endl; 

    swapValues(&a, &b);//------------------------------the address of both variables is passed rather than the actual values, so that way the program can only access the address and manipulate the values

    cout << "After Swapping: " << endl;//--------------prompt to print both variables after swapping
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    
    return 0;//----------------------------------------return 0;

}