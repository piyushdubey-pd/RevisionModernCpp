#include <iostream> 
using namespace std;
// using Comparator = bool (*) (int, int);

template<typename Comparator>
int checker(int x, int y, Comparator comp) {
    return comp(x,y);
}

struct ComparatorGT{
bool operator()(int x, int y){
    return x>y;
}
};

struct ComparatorLT{
bool operator()(int x, int y){
    return x<y;
}
};

int main(){
    // Comparator c1 = comp1;
    // Comparator c2 = comp2;

    ComparatorGT comp1;
    ComparatorLT comp2;

    cout << checker(5,10,comp1) <<endl;
    cout << checker(5,10,comp2) << endl;
}