#include <iostream>
using namespace std;

class OrdeDetails{
    int orderID;
    string itemName;
    const double deliveryFees;
    
    public:

        OrdeDetails(int orderID, string itemName, const double deliveryFees) : deliveryFees(deliveryFees) {
            this->orderID = orderID;
            this->itemName = itemName;
        } 

        ~OrdeDetails() {
            cout << orderID << " is being archived and memory cleared" << endl;
        }
};

int main() {
    system("cls");

    OrdeDetails o1(123, "Phone", 345.9);

    return 0;

}