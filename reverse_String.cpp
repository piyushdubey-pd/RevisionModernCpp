#include <bits/stdc++.h>
using namespace std;

int main(){
    char temp[] = "hello";
    // cin >> temp;
    int nChar = sizeof(temp) - 1;

    char* beg = temp;
    char* end = temp + nChar - 1;

    while (beg < end){
        char t = *beg;
        *beg = *end;
        *end = t;

        beg++;
        end--;
    }

    cout << temp << endl;


    return 0;
}