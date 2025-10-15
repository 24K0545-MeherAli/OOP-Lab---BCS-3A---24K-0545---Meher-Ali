#include <iostream>
using namespace std;

class Doctor {
private:
    string name;
    string specialization;
public:
    Doctor(string name, string specialization) : name(name), specialization(specialization) {
        cout << "Doctor created: " << this->name << ", " << this->specialization << endl;
    }

    string getName() { 
        return name; 
    }
    
    string getSpecialization()  {
         return specialization; 
    }
};

class Hospital {
private:
    string name;
    Doctor* doctors[10];
    int doctorCount;
public:
    Hospital(string name) : name(name), doctorCount(0) {
        cout << "Hospital created: " << this->name << endl;
        for (int i = 0; i < 10; ++i) doctors[i] = nullptr;
    }

    void addDoctor(Doctor* doc) {
        if (doctorCount < 10) {
            doctors[doctorCount++] = doc;
            cout << doc->getName() << " added to " << name << endl;
        } else {
            cout << "Cannot add more doctors to " << name << endl;
        }
    }
    
    void listDoctors() {
        cout << "Doctors at " << name << ":" << endl;
        for (int i = 0; i < doctorCount; ++i) {
            cout << "- " << doctors[i]->getName() << " (" << doctors[i]->getSpecialization() << ")" << endl;
        }
    }
};

int main() {
    system("cls");

    Doctor* d1 = new Doctor("Dr. Ali", "Cardiology");
    Doctor* d2 = new Doctor("Dr. Sara", "Neurology");

    Hospital h1("Lahore General Hospital");
    Hospital h2("Shaukat Khanum Hospital");

    h1.addDoctor(d1);
    h1.addDoctor(d2);

    h2.addDoctor(d2);

    cout << endl;
    h1.listDoctors();
    cout << endl;
    h2.listDoctors();

    delete d1;
    delete d2;

    return 0;
}