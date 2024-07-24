#include <iostream>
#include <memory>
#include <D:\Prg data\C&C++\Revise C++\Integer.h>
using namespace std;

Integer*  getPtr(int val){
    Integer* ptr =  new Integer {val};
    return ptr;
}

void Display(Integer* ptr){
    cout << ptr->GetValue() << endl;
}
void operate(int val) {
    Integer* ptr = getPtr(val);
   if (!ptr){
        ptr = new Integer{val};
    }

    Display(ptr);
    delete ptr;
    ptr = nullptr;

    ptr = new Integer{};
    *ptr = __LINE__;

    Display(ptr);
    delete ptr;
    ptr = nullptr;
}

void Store(unique_ptr<Integer> p){
    cout << "Storing Value" << endl;
    cout << p->GetValue()<<endl;
}
void Store1(unique_ptr<Integer> &p){
    cout << "Storing Value" << endl;
    cout << p->GetValue()<<endl;
}

void operate2(int val){
    // uniquer pointer is an object and not a pointer
    unique_ptr<Integer> ptr(getPtr(val));
    
    // explicit instatination available and all copy operations, eg assignment and construction is not allowed.

    if (!ptr){
        ptr.reset(new Integer{val});
    }

    cout << ptr->GetValue() << endl;
    ptr->SetValue(100);
    cout << ptr->GetValue() << endl;

    // calls the underlying pointer which is of type Integer so that the function parameter is compatibl,e adn the funciton can be called
    Display(ptr.get());


    ptr.reset(new Integer{});
    *ptr = __LINE__;
    ptr->SetValue(3456346);

    Store(std::move(ptr));
    // ptr is empty now
    Store1(ptr);
    // Store(ptr) will not work, because copy assignment and copy constructor is deleted since it is a unique pointer, therefore .reset must be used to transfer the ownership;
    unique_ptr<Integer> ptr1(std::move(ptr));
    unique_ptr<Integer> &ptr2 = ptr1;
    unique_ptr<Integer> ptr3(std::move(ptr2));
}

int main(){
    operate(100);
    operate2(673);
    return 0;
}

// g++ -std=c++14 -g -o uniqueptrimpl.exe uniqueptrimpl.cpp Integer.cpp