//TASK03 by Meher ali 24K-0545
#include <iostream>
using namespace std;

class Calculator{
    private:
        int num1;
        int num2;
    public:
        void setNumbers(int num1, int num2) {
            this->num1 = num1;
            this->num2 = num2;
        }
        int add(){
            int add = num1 + num2;
            return add;
        }
};

int main() {
    system("cls");

    Calculator add;

    add.setNumbers(2,3);
    int addition = add.add();
    cout << "Addition of two nums: " << addition;

    return 0;

}