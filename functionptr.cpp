#include <iostream> 
using namespace std;
using Comparator = bool (*) (int, int);

int checker(int x, int y, Comparator comp) {
    return comp(x,y);
}

bool comp1(int x, int y){
    return x>y;
}


bool comp2(int x, int y){
    return x<y;
}

int main(){
    Comparator c1 = comp1;
    Comparator c2 = comp2;

    int (*fnptr) (int, int, Comparator) = checker;
    cout << fnptr(5,10,c1) << endl;
    cout << fnptr(5,10,c2) << endl;
    (*fnptr)(5,10,c1);
}