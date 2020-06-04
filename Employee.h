#ifndef STAFF_H
#define STAFF_H
#include <iostream>
using namespace  std;
class Employee{
    //E:\luuTruSouceCode\codeCC++\EmployeeManager
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
    virtual void enterEmployee();

    virtual void printEmployee();
    virtual void inputFile();
    void doc( ifstream & );
    void ghi( ofstream & );

};

#endif // STAFF_H
