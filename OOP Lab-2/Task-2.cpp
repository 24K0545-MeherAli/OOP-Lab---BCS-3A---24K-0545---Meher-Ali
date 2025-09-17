//TASK#2 by Meher Ali - 24K0545
#include <iostream> 
using namespace std;

void FirstAndLastIndex(const string& str, char ch, int* first,int* last){//--a function to check the first anddlast index of a char
    *first = -1; //----------------------------------------------------------initialize first index as 0 (means not found yet)
    *last = -1; //-----------------------------------------------------------initialize last index as 0 (means not found yet)

    const char* ptr = str.c_str(); //----------------------------------------creates a C-style pointer, points to the first character of the string
    int index = 0; //--------------------------------------------------------variable to track the current position in the string

    while (*ptr != '\0'){ //-------------------------------------------------loop runs until the null character '\0' (end of string) is reached
        if(*ptr == ch){ //---------------------------------------------------check if current character matches the target character
            if(*first == -1) { //--------------------------------------------if first occurrence not already recorded
                *first = index+1; //-----------------------------------------store current index+1 as first occurrence
            }
            *last = index+1; //----------------------------------------------update last occurrence with current index+1
        }
        ptr++; //------------------------------------------------------------move pointer to the next character
        index++; //----------------------------------------------------------move to the next index number
    }
}

int main() {
    system("cls"); //-------------------------------------------------------clears the terminal 
    string str; //----------------------------------------------------------initialization of variable to store input string
    char ch; //-------------------------------------------------------------initialization of variable to store the character to be searched
    int first; //-----------------------------------------------------------initialization of variable to store first occurrence index
    int last; //------------------------------------------------------------initialization of variable to store last occurrence index

    cout << "Enter any stirng: ";
    getline(cin, str); //---------------------------------------------------get input fron the user
    
    cout << "Enter the character you want to find: ";
    cin >> ch; //-----------------------------------------------------------get char input from the user

    FirstAndLastIndex(str, ch, &first, &last); //---------------------------call function and pass addresses of first and last

    if (first != -1 ) { //--------------------------------------------------if character was found (first occurrence is not -1)
        cout << "First: " << first << ", last: " << last << endl; //--------print first and last indices
    } else {
        cout << "character not found" << endl; //---------------------------if not found, display message
    }

    return 0; //------------------------------------------------------------end of program
}
