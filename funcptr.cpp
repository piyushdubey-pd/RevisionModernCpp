// this is not a functor
#include <bits/stdc++.h>
using namespace std;

int Add(int x, int y){
    return x + y;
}

int main(){
    int x,y;
    cin >> x >> y;
    int (*fptr) (int,int) = &Add; // & optional
    cout << fptr(x,y) << endl;
}