#include "Employee.h"
#include "Helpper.h"

#include <string>
#include <sstream>
#include <fstream>
#include <map>
Employee::Employee(const std::string &id,
                   const std::string &name,
                   const std::string &dateOfBirth,
                   const std::string &address,
                   const std::string &department)
    : _id(id),
      _name(name),
      _dateOfBirth(dateOfBirth),
      _address(address),
      _department(department)
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
    this->_id = id;
}
void Employee::setName(const std::string &name){
    this->_name = name;
}
void Employee::setDateOfBirth(const std::string &dateOfBirth){
    this->_dateOfBirth = dateOfBirth;
}
void Employee::setAddress(const std::string &address){
    this->_address = address;
}
void Employee::setDepartment(const std::string &department){
    this->_department = department;
}

void Employee::enterEmployee(vector<Employee*> list ,string url){
    fstream output(url, ios::app);;
    cout << "" << endl;
    cin.ignore();
    cout << "ID : ";
    getline(cin,_id);
    while (checkId(list, _id) == 0) {
        cout << "trung id, xin nhap lai:  " << endl;
        getline(cin, _id);


    }
    cout << "Ten Nhan Vien: ";
    getline(cin, _name);
    cout << "Ngay Sinh Nhan Vien: ";
    getline(cin, _dateOfBirth);
    while (checkDateOfBirth(_dateOfBirth) == 0) {
        cout << "Ngay thang nam sinh khong hop le, vui long nhap lai:" << endl;
        getline(cin, _dateOfBirth);
    }
    cout << "Dia chi Nhan vien:  ";
    getline(cin, _address);

    while (_address == ""){
        cout << "Khong duoc de trong muc nay vui long nhap lai !  "<< endl;

        getline(cin, _address);
    }


    cout << "Phong ban Nhan vien: ";
    getline(cin,_department);
    while (_department == ""){
        cout << "Khong duoc de trong muc nay vui long nhap lai !  \n"<< endl;
        getline(cin, _department);
    }

    output <<_id <<","<<_name<<","<<_dateOfBirth<<","<<_address<<","<<_department<<endl;

    output.close();
    fflush(stdin);
}

void Employee::printEmployee(){
    cout << "" << endl;
    cout << "Id Nhan Vien: " << _id << endl;
    cout << "Ten Nhan Vien: " << _name << endl;
    cout << "Ngay Sinh Nhan Vien: " << _dateOfBirth << endl;
    cout << "Dia Chi Nhan Vien: " << _address << endl;
    cout << "Phong Ban Nhan Vien: " << _department << endl;
    cout << "" <<endl;

}
void Employee::searchEmployeeById(string idSearch ,vector<Employee*> list){
    for (int i = 0; i < list.size(); i++ ){
        if (list[i]->getId() == idSearch){
            list[i]->printEmployee();
            return;
        }
    }
    cout << "Khong co nhan vien co id = "<< idSearch << endl;

}


void Employee::read(ifstream &in){
    char lines[500];
    //    char id[10], na[40], birth[20], ad[20], de[20];
    fflush(stdin);
    in.getline(lines,500);

    //    in.getline(id, 40);
    //    in.getline(na, 40);
    //    in.getline(birth, 20);
    //    in.getline(ad, 20);
    //    in.getline(de, 20);
    string str = lines;
    vector<string> v = Helpper::split (str, ',');


    this->setId(v.at(0));
    this->setName(v.at(1));
    this->setDateOfBirth(v.at(2));
    this->setAddress(v.at(3));
    this->setDepartment(v.at(4));

}
void Employee::write(ofstream &ofs){
    ofs	<< this->getId() << endl
        << this->getName() << endl
        <<  this->getDateOfBirth() << endl
         <<  this->getAddress() << endl
          <<  this->getDepartment() << endl;

}
int Employee:: checkId(vector<Employee*> list, string id)
{;
    for (int i = 0; i < list.size(); i++ ){
        if (list[i]->getId()==id){
            return 0;
        }
    }
    return 1;
}

int Employee:: checkDateOfBirth(string dateOfBirth){
    for (int i = 0; i < dateOfBirth.length(); i++) {
        if ((dateOfBirth[i] < 47) || (dateOfBirth[i] > 57)) {
            return 0;
        }
    }
    vector<string> birth;
    while(!dateOfBirth.empty()){
        birth.push_back(dateOfBirth.substr(0, dateOfBirth.find("/")));
        if (dateOfBirth.find("/") > dateOfBirth.size()) {
            break;
        }
        dateOfBirth.erase(0, dateOfBirth.find("/") + 1);
    }
    if (birth.size() != 3) {
        return 0;
    } else {
        if ((stoi(birth[0], 0, 10) > 31) || (stoi(birth[1], 0, 10) > 12)) {
            return 0;
        } else {
            switch (stoi(birth[1], 0, 10))
            {
            case 2:
                if (stoi(birth[0], 0, 10) > 29) {
                    return 0;
                }
                if (stoi(birth[0], 0, 10) == 29){
                    if((stoi(birth[2], 0, 10) % 400 == 0) || ((stoi(birth[2], 0, 10) % 4 == 0) && (stoi(birth[2], 0, 10) % 100 != 0))) {
                        return 1;
                    }
                    return 0;
                }
                return 1;
                break;

            case 4: case 6: case 9: case 11:
                if (stoi(birth[0], 0, 10) > 30) {
                    return 0;
                }
                return 1;
                break;
            }
        }
    }
    return 1;
}
