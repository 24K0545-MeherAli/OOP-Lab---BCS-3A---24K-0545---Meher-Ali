#include<iostream>
using namespace std;

class PetrolPump{
    private:
        static double pricePerLiter;
        int pumpID;
        float litersfilled;
    public:
        PetrolPump(int pumpID, float litersfilled) : pumpID(pumpID), litersfilled(litersfilled) {}

        void printReciept(){
            cout << "Reciept: " << endl;
            cout << "Pump ID: " << pumpID << endl;
            cout << "Liters Filled: " << litersfilled << endl;
            cout << "Bill: Rs" << litersfilled*pricePerLiter << endl;
        }
}; 
double PetrolPump :: pricePerLiter = 270.5;

int main() {
    system("cls");

    PetrolPump p1(123, 1.3);
    p1.printReciept();

}