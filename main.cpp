#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <Employee.h>
#include <Helpper.h>
#include <iostream>
#include <cstring>


#include <StatusDate.h>


using namespace std;


int main()
{
    vector<Employee*> list;


    Employee *employee;

    // phần này chỉ lấy ra số dòng trong file csv và xuống khỏi dòng đầu tiên
    ifstream ifs("C:\\Users\\khiem\\Desktop\\ImportData.csv", ios::in);
    int n;
    string abc;
    n=Helpper ::numberLine(); // lấy ra số dòng
    n=n-1;
    ifs >> abc;
    char ss[5];
    ifs.getline(ss, 3);// loai bo xuong dong


// dùng vì cần checkid // đọc ra tất cả
    int line=1 ;
    int *linePtr=&line;


    for (int i=0 ; i < n ; i++){
        employee = new Employee();
        employee->read(ifs ,list ,linePtr);
        list.push_back(employee);
    }


    int choiceSearch;
    int choice;
    do {
        cout <<"===========================================" << endl;
        cout <<"= 1-Nhap nhan vien                        =" << endl;
        cout <<"= 2-Tim nhan vien theo ma                 =" << endl;
        cout <<"= Chon khac de thoat                      =" << endl;
        cout <<"===========================================" << endl;
        cout << "Chon chuc nang (1-2 hoac khac):" << endl;
        cout << "Moi ban nhap lai lua chon = ";
        cin >> choice;

        if (choice == 1) {
            string a = "yes";
            while (a == "yes") {
                employee = new Employee();
                employee->enterEmployee(list,"C:\\Users\\khiem\\Desktop\\ImportData.csv");
                list.push_back(employee);


                cout << "Ban muon nhap tiep khong, an yes; neu muon thoat an phim bat ky \n" << endl;
                cin >> a;
            }
        }

        else if(choice == 2){


        employee->searchEmployee(list);

        }
        else if (choice ==3){

            if(list.size() == 0 ){
                cout << "Danh sach khong co nhan vien nao";
            }else{
                for (int i = 0; i < list.size(); i++ ){
                    list[i]->printEmployee();


                }
            }
        }

        else if (choice ==4) { // tạo tất cả các file nhân viên chỉ lần đầu muốn
            for (int i=0 ; i < list.size(); i++) {
                std::ofstream o( "C:\\Users\\khiem\\Desktop\\fileNV\\"+list.at(i)->getId()+".csv");
            }

        }
        else if(choice ==5){ // lưu thông tin điểm danh
            // nhập vào id , nhập vào ngày muốn điểm danh ,nhập vào trạng thái muốn điểm danh
            StatusDate::read(list);

        }
        else{
            break;
        }

    }

    while (true);

    ifs.close(); // đóng đọc file
    return 0;
}
