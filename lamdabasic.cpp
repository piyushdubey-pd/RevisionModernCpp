#include <iostream>
#include <typeinfo>
using namespace std;

int main(){
    // []() {
    //     cout << "Hello ji Hello" << endl;
    // }();

    auto x = []() {
        cout << "Hello ji Hello" << endl;
    };

    
    x();
    cout << typeid(x).name() << endl;
    return 0;
}