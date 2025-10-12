#include <iostream>
using namespace std;

class NUCES_Student {
    private:
        int id;
        string name;
    public:
        NUCES_Student(){
            id = 0;
            name = " not registered";
        }  
        NUCES_Student(int id) : id(id) {
            name = "name pending";
        }
        NUCES_Student(int id, string name) {
            this->id = id;
            this->name = name;
        }
        void display(){
            cout << "ID: " << id << endl;
            cout << "Name: " << name << endl;
            cout << endl;
        }
};
int main() {
    system("cls");

    NUCES_Student s1;
    NUCES_Student s2(123);
    NUCES_Student s3(456, "abc");

    s1.display();
    s2.display();
    s3.display();

    return 0;

    return 0;

}