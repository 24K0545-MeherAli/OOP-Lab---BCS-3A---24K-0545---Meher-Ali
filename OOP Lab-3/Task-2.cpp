//TASK02 by Meher ali 24K-0545
#include <iostream>
using namespace std;

class Student{
    private:    
        int rollnumber;
    public:
        string name;

    int setRollnumber(int r){
        rollnumber = r;
    }
    int getRollnumber(){
        return rollnumber;
    }
};

int main() {
    system("cls");

    Student s1;
    s1.name = "Meher ali";
    s1.setRollnumber(240545);
    cout << "Name: " << s1.name << endl;
    cout << "Roll number: " << s1.getRollnumber() << endl;

    return 0;

}