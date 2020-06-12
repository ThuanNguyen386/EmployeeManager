#include <StatusDate.h>
#include <Helpper.h>
#include <fstream>
#include <iostream>
void StatusDate ::read(vector<Employee*> list){
    cout<< "nhap id nhan vien muon diem danh" <<endl;
    string idNV;
    cin >> idNV;
    while (Helpper::checkId(list, idNV) == 1) {
        cout << "khong co nhan vien, xin nhap lai:  " << endl;
        cin >>idNV;

    }


    // mo file csv nhan viên điểm danh
    ifstream ifs("..\\EmployeeManager\\fileNV\\"+idNV+".csv", ios::in);

    cout<< "nhap ngay nhan vien muon diem danh" <<endl;
    string date;
    cin >> date;
    while (Helpper::checkDateOfBirth(date) == 0) {
        cout << "Ngay khong hop le, vui long nhap lai:" << endl;
        cin>> date;
    }


    cout<< "nhap trang thai nhan vien muon diem danh" <<endl;
    string status;
    cin >> status;
    while(Helpper::checkStatus(status) ==0){
        cout<<"dinh dang sai , xin nhap lai "<<endl;
        cin >> status;
    }



    // ghi vào
    fstream output("..\\EmployeeManager\\fileNV\\"+idNV+".csv", ios::app);
    output << date<<","<<status<<endl;

    // đóng đọc file
    output.close();
    ifs.close();


}
