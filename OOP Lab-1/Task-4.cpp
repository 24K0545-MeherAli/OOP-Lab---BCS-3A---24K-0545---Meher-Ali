//TASK#4 by Meher Ali 24K-0545
#include <iostream>
#include <cstdlib>
using namespace std;

void swapArray(int arr[], int arr2[], int size) {//----------------a function to swap two arrays by using a temporary array
    for (int i = 0; i < size; i++) {//-----------------------------a loop to check and transfer every value from one arr to another
        int temp = arr[i];//---------------------------------------arr[i]-->temp which makes arr[i] = 0
        arr[i] = arr2[i];//----------------------------------------arr2[i]-->arr[i] which makes arr2[0] and the value at index i of arr2 is now in i'th index of arr[i]
        arr2[i] = temp;//------------------------------------------temp--->arr2[i] which empties the temp[] and transfers the value of arr[i] into arr[2]
    }
}


int checkforLargest(int arr[], int size){//------------------------a function to check for Largest element in an array
    int largest = arr[0];//----------------------------------------a variable 'Largest' is initialized with the first value of the array
    for (int i = 0; i < size ; i++) {//----------------------------this loop runs = number of elements in the array
        if (arr[i] > largest){//-----------------------------------condition checks whether an element on i'th index is greater than largest or not
            largest = arr[i];//------------------------------------if yes, then its value is transferred into largest...making it the largest
        }
    }
    return largest;//----------------------------------------------finally it returns, the largest value
}

int checkForSecondLargest(int arr[], int size){//------------------a function to check for the second largest element in an array
    int largest = checkforLargest(arr,size);//---------------------to get the largest value, we ran the previous checkforLargest() function
    int secondLargest = arr[0];//----------------------------------initializing secondLargest variable with the first index of the array
    for (int i = 0 ; i < size ; i++) {//---------------------------this loop runs for the number of elements in the array i.e. size
        if (arr[i] > secondLargest){//-----------------------------checs if the i'th element of the array is greater than second largest
            secondLargest = arr[i];//------------------------------if true, then it gets transferred in the variable,
            if(secondLargest < largest){//-------------------------then it gets compared to the Largest variable from checkforLargest()
                return secondLargest;//----------------------------if its less...its returned as the second largest
            }
        }
    }
    
}

int findUnique(int arr[], int size) {//----------------------------this function checks whether an array has a unique number or not
    for (int i = 0; i < size; i++) {//-----------------------------checks every value in arr[] 
        bool isUnique = true;//------------------------------------bool isUnique is toggled to "true" initially
        for (int j = 0; j < size; j++) {//-------------------------checks if the values of arr[] are same or not
            if (i != j && arr[i] == arr[j]) {//--------------------a condition which checks if numbers in an array are same or not
                isUnique = false;//--------------------------------if they are same, then isUnique is false
                break;//-------------------------------------------and then the nested loop is broken, just to be started again with respective increments or decrements
            }
        }
        if (isUnique) {//------------------------------------------a condition to check if the isUnique is true or not
            return arr[i];///--------------------------------------if its true, then the unique value will be returned
        }
    }
    return arr[0];//-----------------------------------------------or else the first value will be returned
}

int main(){
    system("cls");//-----------------------------------------------system("cls") to clean the terminal before executing the rest of the program
    int size;
    cout << "Enter size of Array: ";//-----------------------------prompt to take in the value of the size of both of the arrays
    cin >> size;

    int arr[size], arr2[size];//-----------------------------------both arrays are initialized with their sizes

    cout << "1)Values in the first Array: ";//---------------------taking values input for first array using loop
    for(int i = 0 ; i < size ; i++) {
        cin >> arr[i];
    }
    cout << "  Values in the second Array: ";//--------------------taking value intput for second array using loop
    for(int i = 0 ; i < size ; i++) {
        cin >> arr2[i];
    }
    cout << "2)Arrays before swapping: " << endl;//----------------prints both the array before swapping using a loop
    cout << "  Array-1: [";//------------------------------------- prints first array in [n,n,n,n] format
    for ( int i = 0 ; i < size ; i++) {
        cout << arr[i];
        if(i != size-1) {
            cout << ",";
        }
    }
    cout << "]";
    cout << "\n  Array-2: [";//------------------------------------prints second array in [n,n,n,n] format
        for ( int i = 0 ; i < size ; i++) {
            cout << arr2[i];
            if(i != size-1) {
                cout << ",";
            }
        }
        cout << "]" << endl;

    swapArray(arr , arr2 , size);//--------------------------------function to swap elemennts in both arrays

    cout << "  After Swapping: " << endl;//------------------------prompt to start printing both arrays after swapping
    cout << "  Array-1: [";//--------------------------------------prompt before printing first array
    for ( int i = 0 ; i < size ; i++) {//--------------------------prints array in [n,n,n,n] format
        cout << arr[i];
        if(i != size-1) {
            cout << ",";
        }
    }
    cout << "]";
    cout << "\n  Array-2: [";//------------------------------------prompt before printing second array
    for ( int i = 0 ; i < size ; i++) {//--------------------------loop prints array in [n,n,n,n] format
        cout << arr2[i];
        if(i != size-1) {
            cout << ",";
        }
    }
    cout << "]";

    int largest = checkforLargest(arr,size);//---------------------initializes variable with the largest variable from checkForLargest() function
    cout << "\n3)The largest value in [";//------------------------prompt before printing first array
    for ( int i = 0 ; i < size ; i++) {//--------------------------loop prints first array in [n,n,n,n] format
        cout << arr[i];
        if(i != size-1) {
            cout << ",";
        }
    }
    cout << "] is " << largest << endl;

    int secondLargest = checkForSecondLargest(arr2,size);//--------initializes variable with second largest value returned from checkforsecondlargest() function
    cout << "4)The Second largest value in [";//-------------------prompt before printing second array
    for ( int i = 0 ; i < size ; i++) {//--------------------------loop prints second array in [n,n,n,n] format
        cout << arr2[i];
        if(i != size-1) {
            cout << ",";
        }
    }
    cout << "] is " << secondLargest << endl;

    int unique = findUnique(arr,size);//---------------------------initializes variable with a unique value returned from findUnique() function
    cout << "5)The Unique number in the first array is " //--------prompt to show the unique value in firsta rray after swapping
         << unique << endl;
    return 0;
}