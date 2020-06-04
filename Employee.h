#ifndef STAFF_H
#define STAFF_H
#include <iostream>
#include <vector>

using namespace  std;
class Employee{

private:
    std::string _id;
    std::string _name;
    std::string _dateOfBirth;
    std::string _address;
    std::string _department;
    // construster
private:
    Employee(const std::string &id,
             const std::string &name,
             const std::string &dateOfBirth,
             const std::string &address,
             const std::string &department);


    // set
public:
    void setId(const std::string &id);
    void setName(const std::string &name);
    void setDateOfBirth(const std::string &dateOfBirth);
    void setAddress(const std::string &address);
    void setDepartment(const std::string &department);
    //get
public:
    const std::string &getId() const;
    const std::string &getName() const;
    const std::string &getDateOfBirth() const;
    const std::string &getAddress() const;
    const std::string &getDepartment() const;

    Employee(){};
    ~Employee(){};
    // ham khac
public:
    int checkId(vector<Employee*> list , string id);
    int checkDateOfBirth(string dateOfBirth);
    virtual void enterEmployee(vector<Employee*> list);
    virtual void printEmployee();
    static void searchEmployee(string idSearch ,vector<Employee*> list);
    void read( ifstream & );
    void write( ofstream & );
    void test();

};

#endif // STAFF_H
