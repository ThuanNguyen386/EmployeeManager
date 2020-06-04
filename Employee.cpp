#include "Employee.h"
#include <string>
#include <sstream>
#include <fstream>
Employee::Employee(const std::string &id,
                   const std::string &name,
                   const std::string &dateOfBirth,
                   const std::string &address,
                   const std::string &department)
    : _id(id)
    , _name(name),_dateOfBirth(dateOfBirth),_address(address),_department(department)
{

}
//get
const std::string &Employee:: getId() const{
    return this->_id;
}
const std::string &Employee:: getName() const{
    return this->_name;
}
const std::string &Employee:: getAddress() const{
    return this->_address;
}
const std::string &Employee:: getDateOfBirth() const{
    return this->_dateOfBirth;
}
const std::string &Employee:: getDepartment() const{
    return this->_department;
}
//set
void Employee::setId(const std::string &id){
    this->_id=id;
}
void Employee::setName(const std::string &name){
    this->_name=name;
}
void Employee::setDateOfBirth(const std::string &dateOfBirth){
    this->_dateOfBirth=dateOfBirth;
}
void Employee::setAddress(const std::string &address){
    this->_address=address;
}
void Employee::setDepartment(const std::string &department){
    this->_department=department;
}

void Employee::enterEmployee(){
    cout <<"" <<endl;
    cin.ignore();
    cout << "ID : ";
    getline(cin,_id);
    cout << "Ten Nhan Vien: ";
    getline(cin,_name);
    cout << "Ngay Sinh Nhan Vien: "<<endl ;
    getline(cin,_dateOfBirth);

    cout << "Dia chi Nhan vien:  "<<endl;
    getline(cin,_address);

    while ( _address == ""){
        cout << "Khong duoc de trong muc nay vui long nhap lai !  "<< endl;

        getline(cin,_address);
    }


    cout << "phong ban Nhan vien: ";
    getline(cin,_department);
    while ( _department == ""){
        cout << "Khong duoc de trong muc nay vui long nhap lai !  \n"<< endl;
        getline(cin,_department);
    }

    fflush(stdin);
}

void Employee::printEmployee(){
    cout <<"" <<endl;
    cout << "Id Nhan Vien: " << _id << endl;
    cout << "Ten Nhan Vien: " << _name << endl;
    cout << "Ngay Sinh Nhan Vien: " << _dateOfBirth << endl;
    cout << "Dia Chi Nhan Vien: " << _address << endl;
    cout << "Phong Ban Nhan Vien: " << _department << endl;
    cout <<"" <<endl;

}
void Employee::inputFile(){
}
void Employee::doc( ifstream &in ){
    char id[10], na[40], birth[20] ,ad[20],de[20];
    fflush(stdin);
    in.getline(id, 40);
    in.getline(na, 40);
    in.getline(birth, 20);
    in.getline(ad, 20);
    in.getline(de, 20);


    this->setId(id);
    this->setName(na);
    this->setDateOfBirth(birth);
    this->setAddress(ad);
    this->setDepartment(de);

}
void Employee::ghi( ofstream &ofs ){
    ofs	<< this->getId() << endl
        << this->getName()<< endl
        <<  this->getDateOfBirth()<< endl
        <<  this->getAddress()<<endl
        <<  this->getDepartment()<< endl;

}



