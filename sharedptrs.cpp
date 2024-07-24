#include <iostream>
#include <memory>

using namespace std;

class Project {
    string m_Name;

public:
    void SetName(const string &name){
        m_Name = name;
    }
    void Disp() const {
        cout << "[Project Name]::" << m_Name << endl;
    }
};

class Employee {
    // Project *m_project{};
    shared_ptr<Project> m_project{};
public:
    void SetProject(shared_ptr<Project> prj){
        m_project = prj;
    }
    const shared_ptr<Project> GetProject() const{
        return m_project;
    }
};

void ShowInfo(const unique_ptr<Employee> &emp){
    cout << "Employee project details: ";
    emp->GetProject()->Disp();
}

int main(){
    shared_ptr<Project> prj {new Project{}} ;
    prj->SetName("Test Encoder");
    unique_ptr<Employee> e1 {new Employee{}};
    e1->SetProject(prj);
    unique_ptr<Employee> e2 {new Employee{}};
    e2->SetProject(prj);    
    unique_ptr<Employee> e3 {new Employee{}};
    e3->SetProject(prj);


    cout << "Prj ref count = " << prj.use_count() << endl;
    ShowInfo(e1);
    ShowInfo(e2);
    ShowInfo(e3);
    prj->Disp();
    return 0;
}