#include <iostream>

using namespace std;

//Prototyppe declaration
int Add(int&,int&);

int main(){
    int x, y;
    cin >> x >> y;
    cout << "We will be adding these number" << endl;
    // Function call or invoked
    cout << "Sum of these numbers are: "<<Add(x,y)<<endl;
    return 0;
}


// definition
int Add(int &a, int &b) {
    return a+b;
}