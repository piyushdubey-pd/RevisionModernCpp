#include <iostream>

using namespace std;

int main(){
    int x = 10;
    const int* ptr = &x;
    int* const ptr1 = &x;
    const int* const ptr2 = &x;

    int y=5;

    ptr = &y;
    ptr1 = &y;
    ptr2 = &y;

    *ptr = y;
    *ptr1 = y;
    *ptr2 =  y;

    return 0;
}