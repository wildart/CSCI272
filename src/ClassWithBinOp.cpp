#include <iostream>
using namespace std;

class ClassWithBinOp {
    int x;
public:
    ClassWithBinOp(int v): x{v}{}
    int getX() const {
        return x;
    }
    bool operator<(const ClassWithBinOp& v) const {
        return this->x < v.x;
    }
};

bool operator>(const ClassWithBinOp& v, const ClassWithBinOp& w){
    return v.getX() > w.getX();
}

int main()
{
    ClassWithBinOp a{2};
    ClassWithBinOp b{1};
    cout << boolalpha << (a<b) << endl;
    cout << boolalpha << (a>b) << endl;
}
