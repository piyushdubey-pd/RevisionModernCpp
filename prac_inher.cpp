#include <iostream>

using namespace std;

class A{
    public:
    void disp(){
        cout << "Inside A" << endl;
    }
};

class B : A{
    public:
    void disp(){
        cout << "Inside B" << endl;
    }
};

int main(){
    A* a;
    B* b = new B();
    b->disp();
    a->disp();
}