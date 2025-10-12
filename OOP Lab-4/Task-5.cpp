#include <iostream>
using namespace std;

class CurrencyExchange{
    const double PKR_to_USD_Rate;
    string branchName;
    int totalTransaction;

    public:

        CurrencyExchange(double rate, string name, int total) : PKR_to_USD_Rate(rate), branchName(name), totalTransaction(total) {
            cout << "Values set for Rate, Branch Name and Total transactions" << endl;
        }

        double convertPKRtoUSD(const int amount) {
            return amount/PKR_to_USD_Rate;
        }
};
int main() {
    system("cls");

    CurrencyExchange c1(237.8, "North Karachi", 300);

    int amount;
    cout << "Enter amount in PKR to be converted in USD: "; cin >> amount;
    cout << "Rs" << amount << " in USD are $" << c1.convertPKRtoUSD(amount);

    return 0;

}