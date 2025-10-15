#include <iostream>
#include <algorithm>
using namespace std;

class ClassSchedule {
    private:
        string day;
        string timeSlot;
        string roomNumber;
    public:
        ClassSchedule(string d, string time, string room) : day(d), timeSlot(time), roomNumber(room) {
            cout << "Schedule created: " << day << " at " << timeSlot << " in Room " << roomNumber << endl;
        }
        
        ~ClassSchedule() {
            cout << "Schedule destroyed." << endl;
        }
        
        void displaySchedule() {
            cout << "Schedule: " << day << ", " << timeSlot << ", Room " << roomNumber << endl;
        }
};

class Student {
    private:
        const int enrollmentID;
        string studentName;
    public:
        Student(int id, string name) : enrollmentID(id), studentName(name) {
            cout << "Student " << studentName << " (Enrollment ID: " << enrollmentID << ") registered." << endl;
        }
        
        ~Student() {
            cout << "Student " << studentName << " record removed." << endl;
        }
        
        void displayStudentInfo() {
            cout << "  - " << studentName << " (ID: " << enrollmentID << ")" << endl;
        }
        
        string getName() {
            return studentName;
        }
};

class CourseSection {
    private:
        string sectionName;
        ClassSchedule schedule;
        Student** enrolledStudents;
        int studentCount;
        int maxStudents;
        static int totalSections;
    public:
        CourseSection(string name, string day, string time, string room, int maxSize) 
            : sectionName(name), schedule(day, time, room), maxStudents(maxSize), studentCount(0) {
            enrolledStudents = new Student*[maxStudents];
            totalSections++;
            cout << "Course Section '" << sectionName << "' created." << endl;
        }
        
        ~CourseSection() {
            totalSections--;
            cout << "\nCourse Section '" << sectionName << "' closed." << endl;
            delete[] enrolledStudents;
        }
        
        void enrollStudent(Student* student) {
            if (studentCount < maxStudents) {
                enrolledStudents[studentCount] = student;
                cout << "Student " << student->getName() << " enrolled in " << sectionName << "." << endl;
                studentCount++;
            } else {
                cout << "Section " << sectionName << " is full. Cannot enroll more students." << endl;
            }
        }
        
        void displaySectionInfo() {
            cout << "\n--- Course Section: " << sectionName << " ---" << endl;
            schedule.displaySchedule();
            cout << "Enrolled Students (" << studentCount << "/" << maxStudents << "):" << endl;
            for (int i = 0; i < studentCount; i++) {
                enrolledStudents[i]->displayStudentInfo();
            }
        }
        
        static int getTotalSections() {
            return totalSections;
        }
};

int CourseSection::totalSections = 0;

int main() {
    system("cls");
    
    cout << "=== University Course Registration System ===" << endl;
    cout << "\nTotal sections offered this semester (before creating any): " << CourseSection::getTotalSections() << endl;
    
    Student* students[20];
    int studentIndex = 0;
    
    cout << "\n--- Student Registration ---" << endl;
    while (studentIndex < 20) {
        string ans;
        cout << "\nDo you wish to register a student? (yes/no): ";
        getline(cin, ans);
        transform(ans.begin(), ans.end(), ans.begin(), ::tolower);
        
        if (ans == "yes") {
            int id;
            string name;
            
            cout << "Enter enrollment ID: ";
            cin >> id;
            cin.ignore();
            
            cout << "Enter student name: ";
            getline(cin, name);
            
            students[studentIndex] = new Student(id, name);
            studentIndex++;
        } else {
            break;
        }
    }
    
    CourseSection* sections[10];
    int sectionIndex = 0;
    
    cout << "\n--- Course Section Creation ---" << endl;
    while (sectionIndex < 10) {
        string ans;
        cout << "\nDo you wish to create a course section? (yes/no): ";
        getline(cin, ans);
        transform(ans.begin(), ans.end(), ans.begin(), ::tolower);
        
        if (ans == "yes") {
            string sectionName, day, time, room;
            int maxSize;
            
            cout << "Enter section name (e.g., BCS-A): ";
            getline(cin, sectionName);
            
            cout << "Enter day (e.g., Monday): ";
            getline(cin, day);
            
            cout << "Enter time slot (e.g., 9:00-11:00): ";
            getline(cin, time);
            
            cout << "Enter room number: ";
            getline(cin, room);
            
            cout << "Enter maximum students: ";
            cin >> maxSize;
            cin.ignore();
            
            sections[sectionIndex] = new CourseSection(sectionName, day, time, room, maxSize);
            sectionIndex++;
            
            cout << "\nTotal sections offered this semester: " << CourseSection::getTotalSections() << endl;
        } else {
            break;
        }
    }
    
    if (sectionIndex > 0 && studentIndex > 0) {
        cout << "\n--- Student Enrollment ---" << endl;
        for (int i = 0; i < sectionIndex; i++) {
            cout << "\nEnrolling students in Section " << i + 1 << "..." << endl;
            
            int numToEnroll;
            cout << "How many students to enroll in this section? ";
            cin >> numToEnroll;
            cin.ignore();
            
            for (int j = 0; j < numToEnroll && j < studentIndex; j++) {
                sections[i]->enrollStudent(students[j]);
            }
        }
    }
    
    cout << "\n=== All Course Sections ===" << endl;
    for (int i = 0; i < sectionIndex; i++) {
        sections[i]->displaySectionInfo();
    }
    
    cout << "\n\nTotal sections offered this semester: " << CourseSection::getTotalSections() << endl;
    
    cout << "\n--- Closing Course Sections ---" << endl;
    for (int i = 0; i < sectionIndex; i++) {
        delete sections[i];
    }
    
    cout << "\nTotal sections after closure: " << CourseSection::getTotalSections() << endl;
    
    cout << "\n--- Removing Student Records ---" << endl;
    for (int i = 0; i < studentIndex; i++) {
        delete students[i];
    }
    
    return 0;
}