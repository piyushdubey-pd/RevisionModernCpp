#include <bits/stdc++.h>

using namespace std;

class Person {

    public:
    int hehe;
    Person(int x) : hehe(x) {
        cout << "Const called" << endl;
    }
    Person (const Person &p) : hehe(p.hehe) {
        cout << "Copy Constructor Called" <<endl;
    }

    ~Person(){
        cout << "Khatam" <<endl;
    }
};

int main(){

    Person p(5);
    Person p1 = p;
    
    cout << p.hehe << " " << p1.hehe << endl;

    return 0;
}