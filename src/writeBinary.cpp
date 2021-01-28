#include <iostream>
#include <fstream>
using namespace std;

struct Credit {
    int accountNumber;
    std::string lastName;
    double balance;
};

int main()
{
    ofstream outCredit{"credit.dat", ios::out | ios::binary};
    if ( !outCredit ) {
        cout << "File could not be opened." << endl;
    }

    Credit client{255, "Dow", 1000.10};
    outCredit.write(reinterpret_cast<const char*>(&client), sizeof(Credit));

    cout << "Size of the Credit type: " << sizeof(Credit);
}
