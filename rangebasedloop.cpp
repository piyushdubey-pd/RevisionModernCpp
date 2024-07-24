#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {1,2,3,4,5};

    // const int &X if you do not want any changes to be made to the element, if & not used a copy is made
    for (int &X : arr){ //lvalue used as a range
        cout << X++ << endl;
    }

    for (auto &x : {1,2,3,4,5}){ // lvalue used as a range
        cout << x << endl;
    }

    auto &&fw = arr; // forwarding reference, this iterator becomes the type of the iterator the value is (arr) or the list,
    auto beg = std::begin(arr); // arr
    auto beg1 = std::begin(fw);
    auto end = std::end(arr); // arr + sizeof(arr)/sizeof(arr[0])
    auto end1 = stdd::end(fw);

    // using beg1 and end1 will make it compile and usable as usual
    
    while (beg!=end){
        cout << *beg << endl;
        beg++;
    }

    beg = std::begin(arr);

    for (;beg!=end;beg++){
        cout << *beg <<endl;
    }
}