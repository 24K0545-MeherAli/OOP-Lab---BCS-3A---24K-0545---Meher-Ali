#include <iostream>
#include <algorithm>
using namespace std;

class CallRecord {
    private:
        int callerID;
        int durationMinutes;
        static int countCall;
    public:
        CallRecord(int callerID, int durationMinutes) : callerID(callerID), durationMinutes(durationMinutes) {
            cout << "Call recorded for " << durationMinutes << " minutes." << endl;
            countCall++;
        }

        static int getTotalCalls() {
            return countCall;
        }
};

int CallRecord::countCall = 0;

int main() {
    system("cls");

    CallRecord* calls[20];
    int i = 0;
    while (i < 20) {
        string ans;
        cout << "Do you wish to start a call? (yes/no): ";
        getline(cin, ans);
        transform(ans.begin(), ans.end(), ans.begin(), ::tolower);
        if (ans == "yes") {
            int id, minutes;
            cout << "Enter caller ID: ";
            cin >> id;
            cout << "Enter duration: ";
            cin >> minutes;
            cin.ignore();
            calls[i] = new CallRecord(id, minutes);
            i++;
        } else {
            break;
        }
    }

    cout << "\nTotal calls logged: " << CallRecord::getTotalCalls() << endl;

    for (int j = 0; j < i; ++j) {
        delete calls[j];
    }

    return 0;
}