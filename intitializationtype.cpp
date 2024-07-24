#include <iostream>
#include <string>

using namespace std;

int main(){
    int a1; //unitialized
    int a2 = 0; // copy initialization initialized
    int a3(5); // Direct initialization
    string s1; // default constructor invoked in cases of non primitive datatypes
    string s2("Hello");

    char d1[8];
    char d2[8]={'\0'}; // initialized 
    char d3[8] = {'a','b','c','d'}; // aggreagate initialization
    char d4[8] = {"abcd"}; // copy initialization
    
    // Uniform initialization

    int b1{}; //valua initialization, initialization to default value
    //int b2(); // This is not initialization.  Most vexign parse, it calls a function that accepts void and returns int
    int b3{5}; // Direct initialization

    int b4 = 0; // this should be avoided, copy initialization in scenarios a copy of the value is created, therefore it is ineffecient

    char e1[8]{};
    char e2[8]{"Hello"};

    // uniform init allows initialization of heap based objects

    // if we do value initialization on a heap it stores a default value... for eg:

    int *p1 = new int{};
    char *p2 = new char[8]{};
    char *p3 = new char[8]{"Hello"};

    // for primitive we can stick to assignment operator but in cases of user defined datatypes it is important to use uniform initialization




}