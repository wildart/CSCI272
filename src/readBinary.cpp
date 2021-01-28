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
    ifstream inCredit{"credit.dat", ios::in | ios::binary};
    if ( !inCredit ) {
        cout << "File could not be opened." << endl;
    }

    Credit client; // create record

    try{
        // read first record from file
        inCredit.read(reinterpret_cast<char*>(&client), sizeof(Credit));
    } catch (const exception &e){
        cout << e.what() << endl;
    }

    cout << client.accountNumber << ", " << client.lastName << ", " << client.balance << endl;
}
