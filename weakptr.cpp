#include <iostream>
#include <memory>

using namespace std;

class Printer{
    weak_ptr<int> m_value{};

    public:
    void SetValue(weak_ptr<int> p){
        m_value = p;
    }
    void Disp(){
        if (m_value.expired()){
            cout <<"Resource not available" << endl;
            return;
        }

        // can use auto, but lock returns a shared pointer of that control block to perform operations and this pointer is later destroyed in its destructor
        // If the resource pointed by weak_ptr exists, 
        // this function returns a shared_ptr with ownership of that resource. 
        // If the resource does not exist, it returns default constructed shared_ptr.
        shared_ptr<int> sp = m_value.lock();
        cout << "Ref count of underlying pointer: " << sp.use_count() << endl;

        // we cannot simply access the underlying pointer of a weakpointer using the way as below
        // cout << *m_value << endl;
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