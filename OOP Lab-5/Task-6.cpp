#include <iostream>
#include <algorithm>
using namespace std;

class Employee {
    private:
        int employeeID;
        string employeeName;
        static int totalEmployees;
    public:
        Employee(int id, string name) : employeeID(id), employeeName(name) {
            totalEmployees++;
            cout << "Employee " << employeeName << " (ID: " << employeeID << ") hired." << endl;
        }
        
        ~Employee() {
            totalEmployees--;
            cout << "Employee " << employeeName << " left the company." << endl;
        }
        
        void displayEmployeeInfo() {
            cout << "Employee ID: " << employeeID << ", Name: " << employeeName << endl;
        }
        
        static int getTotalEmployees() {
            return totalEmployees;
        }
        
        string getName() {
            return employeeName;
        }
};

int Employee::totalEmployees = 0;

class ClientProject {
    private:
        string projectName;
        Employee** teamMembers;
        int teamSize;
    public:
        ClientProject(string name, int size) : projectName(name), teamSize(size) {
            teamMembers = new Employee*[teamSize];
            cout << "\nProject '" << projectName << "' created with team size " << teamSize << "." << endl;
        }
        
        ~ClientProject() {
            cout << "\nProject '" << projectName << "' completed." << endl;
            delete[] teamMembers;
        }
        
        void assignEmployee(int index, Employee* emp) {
            if (index >= 0 && index < teamSize) {
                teamMembers[index] = emp;
                cout << "Assigned " << emp->getName() << " to project '" << projectName << "'." << endl;
            }
        }
        
        void displayProjectInfo() {
            cout << "\n--- Project: " << projectName << " ---" << endl;
            cout << "Team Members:" << endl;
            for (int i = 0; i < teamSize; i++) {
                teamMembers[i]->displayEmployeeInfo();
            }
        }
};

int main() {
    system("cls");
    
    Employee* employees[20];
    int empCount = 0;
    
    while (empCount < 20) {
        string ans;
        cout << "\nDo you wish to hire an employee? (yes/no): ";
        getline(cin, ans);
        transform(ans.begin(), ans.end(), ans.begin(), ::tolower);
        
        if (ans == "yes") {
            int id;
            string name;
            
            cout << "Enter employee ID: ";
            cin >> id;
            cin.ignore();
            
            cout << "Enter employee name: ";
            getline(cin, name);
            
            employees[empCount] = new Employee(id, name);
            empCount++;
        } else {
            break;
        }
    }
    
    cout << "\nTotal company strength: " << Employee::getTotalEmployees() << " employees" << endl;
    
    if (empCount >= 3) {
        ClientProject* project = new ClientProject("E-Commerce Platform", 3);
        
        cout << "\nAssigning first 3 employees to the project..." << endl;
        for (int i = 0; i < 3; i++) {
            project->assignEmployee(i, employees[i]);
        }
        
        project->displayProjectInfo();
        
        cout << "\nTotal company strength: " << Employee::getTotalEmployees() << " employees" << endl;
        
        delete project;
    } else {
        cout << "\nNot enough employees to create a project (need at least 3)." << endl;
    }
    
    cout << "\n--- Company Shutdown ---" << endl;
    for (int i = 0; i < empCount; i++) {
        delete employees[i];
    }
    
    cout << "\nFinal company strength: " << Employee::getTotalEmployees() << " employees" << endl;
    
    return 0;
}