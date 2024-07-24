#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a=*b;
    *b=temp;
    cout << "In ptr fun" <<endl;
}


void swap(int &a, int &b){
    int temp = a;
    a=b;
    a=temp;
    cout << "In ref fun" <<endl;
}

int main(){
    int x =5, y =10;
    cout << x << " and "<< y << endl;
    swap(x,y);
    cout << x << " and "<< y << endl;
    // // int *a = &x;
    // // int *b = &y;
    swap(&x,&y);
    cout << x << " and "<< y << endl;
}

// int &x =y;
// alias pointing to indentifier (ref)
// int *x = &y;
// pointer saves reference