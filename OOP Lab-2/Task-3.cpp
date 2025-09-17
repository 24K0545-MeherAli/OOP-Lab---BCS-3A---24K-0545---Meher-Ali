//TASK#3 by Meher Ali - 24K0545
#include <iostream>
using namespace std;

int sumArray(int* arr, int size) {                //-------------------function to calculate sum of array using pointer arithmetic
    int sum = 0;                                  //-------------------variable to store sum
    for (int i = 0; i < size; i++) {              //-------------------loop to traverse all array elements
        sum += *(arr + i);                        //-------------------add element at position i using pointer arithmetic
    }
    return sum;                                   //-------------------return the total sum
}

int main() {
    system("cls");                                //-------------------to clear terminal before running the program
    int size;                                     //-------------------variable to store array size
    cout << "Enter size of array: ";              //-------------------prompt user to enter size
    cin >> size;                                  //-------------------take input for size

    int* arr = new int[size];                     //-------------------dynamically allocate array of given size
    cout << "Enter " << size << " elements: ";    //-------------------prompt to enter array elements
    for (int i = 0; i < size; i++) {              //-------------------loop to take array input
        cin >> *(arr + i);                        //-------------------store input in array using pointer arithmetic
    }

    cout << "Sum of array elements = " 
         << sumArray(arr, size) << endl;          //-------------------call sumArray function and display sum

    delete[] arr;                                 //-------------------free dynamically allocated memory
    return 0;                                     //-------------------end of program
}
