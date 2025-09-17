//TASK05 by Meher ali 24K0545
#include <iostream>
using namespace std;

class ConcreteClass{
    private:
        string message;
    public:
        ConcreteClass(string message){
            this->message = message;
        }

        string displayMessage(){
            cout << message;
        }

};

int main() {
    system("cls");

    ConcreteClass message("A concrete class provides an implementation for all of its methods.");
    cout << "Message: \n" << message.displayMessage();

    return 0;

}