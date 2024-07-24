#include <iostream>

using namespace std;

class A{
    public:
        virtual void display()
        {
            cout << "IN A" << endl;
        }
        virtual void dex()
        {
            cout << "IN A dex" << endl;
        }
};

class B: public A {
    public:
    void display() override {
        cout << "IN B" << endl;
    }
    void dex() override {
        cout << "IN B dex" <<endl;
    }
};

class C: public A {
    public:
    void display() override {
        cout << "IN C" << endl;
    }
    void dex() override {
        cout << "IN C dex" <<endl;
    }
};
class D:public A{
    public:
    void demo(){
        cout << "NA"<<endl;
    }
};

void dk(A* x){
    x->dex();
}

int main(){
B* b = new B();
C* c = new C();
D* d = new D();
dk(d);
// dk(b);

return 0;
}