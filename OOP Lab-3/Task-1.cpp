//TASK01 by Meher ali 24K-0545
#include <iostream>
using namespace std;

class Student{
    public:
        string name;
        int rollnumber;

};

int main() {
    system("cls");

    Student s1;
    s1.name = "Meher ali";
    s1.rollnumber = 240545;
    cout << "Name: " << s1.name << endl;
    cout << "Roll Number: " << s1.rollnumber << endl;

    return 0;

}