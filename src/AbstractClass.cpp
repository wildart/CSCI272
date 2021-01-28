#include <iostream>
using namespace std;

// abstract class
class CommunityMember {
public:
    CommunityMember() { cout << "Create a community member"  << endl; }
    ~CommunityMember(){ cout << "Destroy a community member" << endl; }

    virtual void act() = 0; // pure virtual function
};

// concrete class
class Employee : public CommunityMember {
public:
    Employee() : CommunityMember() { cout << "Create an employee" << endl; }
    ~Employee(){ cout << "Destroy an employee" << endl; }

    void act() { cout << "I'm an employee" << endl; }
};

int main() {

    Employee* e = new Employee();
    delete e;
    return 0;
}