#include <iostream>

using namespace std;

int main(){
    int x = 5;
    int *y = &x;

    int &a = *y;
    int &b = x;
    // ptr to refs and refs to identifier
    *y = 10;

    cout << a <<" " <<b<<" ";

}