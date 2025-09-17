//TASK07 by Meher ali 24K06545
#include <iostream>
using namespace std;

class Student{
    private:
        string name;
        int rollNo;
        double marks;
        char grade;
    public:
        Student(string n, int r, double m):name(n), rollNo(r), marks(m) {}

        char CalculateGrade(){
            if (marks>=90)
                this->grade = 'A';
            else if (marks>=80)
                this->grade = 'B';
            else if (marks>=70)
                this->grade = 'C';
            else 
                this->grade = 'F';
            }

        void displayStudentInfo(){
            cout << "\nStudent Details: " << endl;
            cout << "Name of Student        : " << name << endl;
            cout << "Roll number of Student : " << rollNo << endl;
            cout << "Marks of the Student   : " << marks << endl;
            cout << "Grade of Student       : " << grade << endl;
        }
};

int main() {
    system("cls");
    Student Meher("Meher", 240545, 80);
    Student Zaid("Zaid", 240686, 90);

    Meher.CalculateGrade();
    Zaid.CalculateGrade();

    Meher.displayStudentInfo();
    Zaid.displayStudentInfo();

    return 0;

}