#include <iostream>
using namespace std;

class Car {
    protected:
    string name = "RAndom";



    public:
    virtual void getName() = 0;
    virtual void getMFD() = 0;
};

class Maruti : public Car {
    public:
    Maruti(){
    name = "Maru";
    }
    
    void getName(){
        cout << "Car is" << name << endl;
    }
    void getMFD() {
        cout << "Date : 12/Jul" <<endl;
    }
};

class Honda : public Car {
    public:
    Honda(){
    name = "Honda";
    }
    void getName(){
        cout << "Car is" << name << endl;
    }
    void getMFD() {
        cout << "Date : 2/Aug" <<endl;
    }
};

void getDetails(Car* carptr){
    carptr->getMFD();
    carptr->getName();
}

int main(){
    Maruti mar;
    Honda hond;

    Car * carptr = &mar;
    carptr = &mar;

    int x = 5;
    int *ptr = &x;

    getDetails(&mar);
    getDetails(&hond);
}