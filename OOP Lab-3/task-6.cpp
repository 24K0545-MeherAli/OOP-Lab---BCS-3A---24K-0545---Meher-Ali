//TASK06 by Meher ali 24K0545
#include <iostream>
using namespace std;

class Vehicle{
    public:
        string make;
        string model;

        void displayinfo(){
            cout << "Make: " << make << endl;
            cout << "Model: " << model << endl;
        }

};

class Car : public Vehicle
{
    public:
    string engineType;

    void displayinfo(){
        Vehicle::displayinfo();
        cout << "Engine Type: " << engineType << endl;
    }
};

int main() {
    system("cls");

    Vehicle car;
    Car c1;

    c1.make = "Toyota";
    c1.model = "Civic";
    c1.engineType = "V8";

    c1.displayinfo();

    return 0;

}