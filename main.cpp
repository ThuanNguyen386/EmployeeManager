#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <Employee.h>
#include <Helpper.h>

using namespace std;


int main()
{
    vector<Employee*> list;


    Employee *employee;

    // phần này chỉ lấy ra số dòng trong file csv và xuống khỏi dòng đầu tiên
    ifstream ifs("..\\EmployeeManager\\ImportData.csv", ios::in);
    int n;
    string abc;
    n=Helpper ::numberLine(); // lấy ra số dòng
    n=n-1;
    cout<<n<<endl;
    ifs >> abc;
    char ss[5];
    ifs.getline(ss, 3);// loai bo xuong dong


// dùng vì cần checkid // đọc ra tất cả
    for (int i=0 ; i < n ; i++){
        employee = new Employee();
        employee->read(ifs);
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
                employee->enterEmployee(list,"..\\EmployeeManager\\ImportData.csv");


                cout << "Ban muon nhap tiep khong, an yes; neu muon thoat an phim bat ky \n" << endl;
                cin >> a;
            }
        }

        else if(choice == 2){

            cout <<"===========================================" << endl;
            cout <<"= 1-search By Name                      =" << endl;
            cout <<"= 2-search By Id                =" << endl;
            cout <<"= 3-search By Address               =" << endl;
            cout <<"= 3-search By Department               =" << endl;
            cout <<"= 4-search By DateOfBirth               =" << endl;



            cout <<"= Chon khac de thoat                      =" << endl;
            cout <<"===========================================" << endl;

            cout << "Moi ban nhap lai lua chon = ";
            cin >> choiceSearch; // chọn các lựa chọn trong tìm kiếm
            if (choiceSearch ==1 ) {
                string idSearch;
                cout << "Nhap id nhan vien = ";
                cin >> idSearch;
                Employee::searchEmployeeById(idSearch,list);
            }
            else if (choiceSearch == 2) {

            }
            else if (choiceSearch == 3) {

            } else if (choiceSearch == 4) {

            }




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
        else{
            break;
        }

    }

    while (true);

    //    ofstream ofs("C:\\Users\\BTC\\Desktop\\ImportData.csv", ios::out);

    //    for( int i = 0; i< n; i++ )
    //        list[i]->write(ofs); // ghi thong tin cac nhan vien ra file OUTPUT.OUT

    //  ofs.close();





    ifs.close(); // đóng đọc file
    return 0;
}
