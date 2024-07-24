#include <bits/stdc++.h>
using namespace std;

inline int Sqr(const int& y){
    return y*y;
}

#define Sq(x) (x*x)
int main(){
    int x;
    cin >> x;
    cout << Sq(x+1) << endl;
    cout << Sqr(x+1) << endl;
}