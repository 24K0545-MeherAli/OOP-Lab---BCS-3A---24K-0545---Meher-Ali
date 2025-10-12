#include <iostream>
using namespace std;

class PropertyDeed {
private:
    int* ownerID;

public:
    PropertyDeed(int id) {
        ownerID = new int;
        *ownerID = id;  
        cout << "Regular Constructor called: Owner ID = " << *ownerID;
    }

    explicit PropertyDeed(const PropertyDeed& source) {
        ownerID = source.ownerID;
        cout << "Shallow Copy Constructor called: Sharing memory with original";
    }

    PropertyDeed(const PropertyDeed& source, bool deepCopy) {
        if (deepCopy) {
            ownerID = new int;
            *ownerID = *(source.ownerID);
            cout << "Deep Copy Constructor called: Independent memory allocated";
        }
    }

    void setOwnerID(int newID) {
        *ownerID = newID;
    }

    void display(const string& objectName) const {
        cout << "\n--- " << objectName << " ---" << endl;
        cout << "Owner ID Value: " << *ownerID << endl;
        cout << "Memory Address: " << ownerID << endl;
        cout << "\n";
    }

    ~PropertyDeed() {
        cout << "Destructor called for Owner ID at address: " << ownerID << endl;
        delete ownerID;
    }
};

int main() {
    system("cls");

    PropertyDeed original(12345);
    original.display("Original Deed");

    PropertyDeed shallowCopy(original);
    shallowCopy.display("Shallow Copy");

    PropertyDeed deepCopy(original, true);
    deepCopy.display("Deep Copy");

    cout << "\n========== BEFORE MODIFICATION ==========\n";
    original.display("Original Deed");
    shallowCopy.display("Shallow Copy");
    deepCopy.display("Deep Copy");

    cout << "\n4. Modifying Original Deed's Owner ID to 99999..." << endl;
    original.setOwnerID(99999);

    cout << "\n========== AFTER MODIFICATION ==========\n";
    original.display("Original Deed");
    shallowCopy.display("Shallow Copy (AFFECTED!)");
    deepCopy.display("Deep Copy (INDEPENDENT!)");

    cout << "\n\n========== KEY OBSERVATIONS ==========\n" << endl;
    cout << "• Shallow Copy shares the SAME memory address as Original" << endl;
    cout << "• Deep Copy has a DIFFERENT memory address (independent)" << endl;
    cout << "• When Original is modified:" << endl;
    cout << "  - Shallow Copy is affected (same memory location)" << endl;
    cout << "  - Deep Copy remains unchanged (separate memory)" << endl;
    cout << "\n\n";
    return 0;
}