#include <iostream>
#include <algorithm>
using namespace std;

class Kitchen {
    private:
        int numberOfAppliances;
        string kitchenType;
    public:
        Kitchen(int appliances, string type) : numberOfAppliances(appliances), kitchenType(type) {
            cout << "Kitchen created with " << numberOfAppliances << " appliances (" << kitchenType << " type)." << endl;
        }
        
        ~Kitchen() {
            cout << "Kitchen destroyed." << endl;
        }
        
        void displayKitchenInfo() {
            cout << "Kitchen Type: " << kitchenType << ", Appliances: " << numberOfAppliances << endl;
        }
};

class Apartment {
    private:
        const int apartmentID;
        string ownerName;
        Kitchen kitchen;
    public:
        Apartment(int id, string owner, int appliances, string kitchenType) 
            : apartmentID(id), ownerName(owner), kitchen(appliances, kitchenType) {
            cout << "Apartment " << apartmentID << " registered for " << ownerName << "." << endl;
        }
        
        ~Apartment() {
            cout << "Apartment " << apartmentID << " unregistered." << endl;
        }
        
        void displayApartmentInfo() {
            cout << "\nApartment ID: " << apartmentID << endl;
            cout << "Owner: " << ownerName << endl;
            kitchen.displayKitchenInfo();
        }
};

int main() {
    system("cls");
    
    Apartment* apartments[20];
    int i = 0;
    
    while (i < 20) {
        string ans;
        cout << "\nDo you wish to register an apartment? (yes/no): ";
        getline(cin, ans);
        transform(ans.begin(), ans.end(), ans.begin(), ::tolower);
        
        if (ans == "yes") {
            int id, appliances;
            string owner, kitchenType;
            
            cout << "Enter apartment ID: ";
            cin >> id;
            cin.ignore();
            
            cout << "Enter owner name: ";
            getline(cin, owner);
            
            cout << "Enter number of kitchen appliances: ";
            cin >> appliances;
            cin.ignore();
            
            cout << "Enter kitchen type (Modern/Traditional): ";
            getline(cin, kitchenType);
            
            apartments[i] = new Apartment(id, owner, appliances, kitchenType);
            i++;
        } else {
            break;
        }
    }
    
    cout << "\n--- Displaying All Apartments ---" << endl;
    for (int j = 0; j < i; ++j) {
        apartments[j]->displayApartmentInfo();
    }
    
    cout << "\n--- Cleaning up apartments ---" << endl;
    for (int j = 0; j < i; ++j) {
        delete apartments[j];
    }
    
    return 0;
}