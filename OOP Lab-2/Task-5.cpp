//TASK#5 by Meher Ali - 24K0545
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    system("cls");
    int size1, size2;                                   //-------------------variables to store lengths of input strings

    cout << "Enter length of first string: ";
    cin >> size1;                                       //-------------------take size input
    cout << "Enter length of second string: ";
    cin >> size2;                                       //-------------------take size input
    cin.ignore();                                       //-------------------clear input buffer before getline

    char* str1 = new char[size1 + 1];                   //-------------------dynamically allocate memory for first string (+1 for null terminator)
    char* str2 = new char[size2 + 1];                   //-------------------dynamically allocate memory for second string
    char* result = new char[size1 + size2 + 2];         //-------------------allocate memory for concatenated string

    cout << "Enter first string: ";
    cin.getline(str1, size1 + 1);                       //-------------------take input for first string
    cout << "Enter second string: ";
    cin.getline(str2, size2 + 1);                       //-------------------take input for second string

    strcpy(result, str1);                               //-------------------copy first string into result
    strcat(result, " ");                                //-------------------isnert a space after the first str
    strcat(result, str2);                               //-------------------concatenate second string to result

    cout << "\nFirst String: " << str1 << endl;         //-------------------display first string
    cout << "Second String: " << str2 << endl;          //-------------------display second string
    cout << "Concatenated String: " << result << endl;  //-------------------display concatenated string

    delete[] str1;                                      //-------------------deallocate memory of first string
    delete[] str2;                                      //-------------------deallocate memory of second string
    delete[] result;                                    //-------------------deallocate memory of concatenated string

    return 0;                                           //-------------------end of program
}
