#include <iostream>
#include <memory>

using namespace std;

class Printer{
    shared_ptr<int> m_value{};

    public:
    void SetValue(shared_ptr<int> p){
        m_value = p;
    }
    void Disp(){
        cout << "Ref count of underlying pointer: " << m_value.use_count() << endl;
        cout << *m_value << endl;
    }
};

int main(){
    Printer prn;
    int num{};
    cin >> num;
    shared_ptr<int> p {new int{num}};
    cout << "Ref count of ext pointer: " << p.use_count() << endl;
    prn.SetValue(p);
    if (*p > 10){
        p = nullptr;
    }
    cout << "Ref count of ext pointer: " << p.use_count() << endl;

    prn.Disp();

}

// double deletion crashes the program, 
//if the ptr is made to point to null pointer then 
//deleltion at null does nothing