#include <iostream>
#include <iomanip>   // for setw and setfill stream manipulators
#include <string>
using namespace std;

class ClassWithStreamOp {
    friend std::ostream& operator<<(std::ostream&, const ClassWithStreamOp&);
    friend std::istream& operator>>(std::istream&, ClassWithStreamOp&);
public:
    int x;
    ClassWithStreamOp(int v): x{v}{}
};

// overloaded stream insertion operator; cannot be a member function
// if we would like to invoke it with cout << ClassWithStreamOp;
ostream& operator<<(ostream& output, const ClassWithStreamOp& obj) {
    output << "Object field 'x': " << obj.x;
    return output;
}

// overloaded stream insertion operator; cannot be a member function
// if we would like to invoke it with cout << ClassWithStreamOp;
istream& operator>>(istream& input, ClassWithStreamOp& obj) {
    input.ignore();
    input >> setw(2) >> obj.x;
    return input;
}

int main() {

    ClassWithStreamOp x{10};
    cout << x << endl;
    cin >> x;
    cout << x << endl;
}
