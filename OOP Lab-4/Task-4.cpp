#include <iostream>
using namespace std;

class ServerSession{
    int sessionID;
    public:
        ServerSession(int id) : sessionID(id) {
            cout << "session " << sessionID << " started" << endl;
        }

        ~ServerSession() {
            cout << "session " << sessionID << " ended" << endl;
        }
};
int main() {
    system("cls");
    
    {
        int id;
        cout << "Enter session ID: " ;
        cin >> id;
    
        ServerSession s1(id);
    }

    cout << "destructor called before return 0;" << endl;
    return 0;
}