#include <iostream>
using namespace std;

class MobileDevice {
    private:
        string modelName;
        const string IMEINumber;
    public:
        MobileDevice(string modelName, const string IMEINumber) : modelName(modelName), IMEINumber(IMEINumber) {
            cout << "Mobile Issued" << endl;
        }

        void verifyDevice() {
            cout << "Mobile Model Name: " << modelName << endl;
            cout << "Mobile IMEI Number: " << IMEINumber << endl;
            cout << "It will not modify the stored IMEI NUMBER..." << endl;
        }
};
int main() {
    system("cls");

    MobileDevice m1("RMX27834", "1234567890");
    m1.verifyDevice();

    return 0;
}