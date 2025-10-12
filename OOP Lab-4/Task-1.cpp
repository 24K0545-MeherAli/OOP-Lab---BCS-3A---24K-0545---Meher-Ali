#include <iostream>
using namespace std;

class MobileAccount {
    private:
     double balance;
     string phoneNumber;
    public:
     MobileAccount(){
        balance = 50.0;
        phoneNumber = " ";
     }

     MobileAccount(double b, string pn) : balance (b), phoneNumber(pn) {}

     void display() {
        cout << "Current Balance: " << balance << endl;
        cout << "Phone Number: " << phoneNumber << endl;
     }
};

int main() {
    system("cls");

    MobileAccount m1;
    MobileAccount m2 (700.0, "1234567910");

    m1.display();
    m2.display();

    return 0;

}