#include <iostream>

// below mentioned header files are not required for this code
#include <climits>
#include <cfloat>

using namespace std;

int main(){
    char x[10];
    cout << "Hello enter a value " << 2 << 3.134f <<endl;

    // cin reads only till space
    cin >> x;
    cout << x <<endl;

    fflush(stdin);
    cout << "enter a string with space, this time also won't work" << endl;
    string str;
    cin>> str;
    cout << str << endl;

    fflush(stdin);
    // use get Line for space separated strings, used for buffer and not strings
    cout << "Impl 1: " <<endl;
    cin.getline(x, 64,'\n');
    cout << x << endl;


    fflush(stdin);
    cout << "Impl 2: " << endl;
    getline(cin,str);
    cout << str << endl;

    return 0;
}