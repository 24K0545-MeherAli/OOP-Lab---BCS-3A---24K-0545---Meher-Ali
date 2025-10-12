#include <iostream>
#include <string>
using namespace std;

class SecureBankAccount {
private:
    int accountNumber;
    double balance;
    const string accountType;
    int* logHistory;

public:
    SecureBankAccount(int accNum, double initialBalance, string accType, int logSize) 
        : accountType(accType) {
        
        this->accountNumber = accNum;
        this->balance = initialBalance;
        
        logHistory = new int;
        *logHistory = logSize;
        
        if (initialBalance < 500.0) {
            cout << "ERROR: Initial balance must be at least 500.0 PKR!" << endl;
        }
    }

    SecureBankAccount(const SecureBankAccount& source) 
        : accountType(source.accountType) {
        
        this->accountNumber = source.accountNumber;
        this->balance = source.balance;
        
        logHistory = new int;
        *logHistory = *(source.logHistory);
    }

    void display() const {
        cout << "Account #" << accountNumber << " | Type: " << accountType 
             << " | Balance: " << balance << " PKR | Logs: " << *logHistory << endl;
    }

    ~SecureBankAccount() {
        cout << "Account #" << accountNumber << " is being closed and memory cleared" << endl;
        delete logHistory;
    }
};

int main() {
    system("cls");

    SecureBankAccount* acc1 = new SecureBankAccount(101, 1000.0, "Current", 0);
    acc1->display();

    SecureBankAccount* acc2 = new SecureBankAccount(102, 300.0, "Savings", 5);
    acc2->display();

    cout << "\nExplicitly deleting accounts:" << endl;
    delete acc1;
    delete acc2;

    return 0;
}