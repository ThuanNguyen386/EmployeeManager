#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <Employee.h>

using namespace std;

int main()
{
    vector<Employee*> list;
    ifstream ifs("C:\\Users\\BTC\\Desktop\\list.txt", ios::in);
    Employee *employee;
    int n;
    ifs >> n;

    char ss[5];
    ifs.getline(ss, 3);// loai bo xuong dong
    for (int i=0 ; i < n ; i++){
        employee = new Employee();
        employee->read(ifs);
        list.push_back(employee);
    }
    ifs.close();
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
                employee->enterEmployee(list);
                list.push_back(employee);
                n = n + 1;
                cout << "Ban muon nhap tiep khong, an yes; neu muon thoat an phim bat ky \n" << endl;
                cin >> a;
            }
        }

        else if(choice == 2){
            string idSearch;
            cout << "Nhap id nhan vien = ";
            cin >> idSearch;
            Employee::searchEmployee(idSearch,list);


        }
        else{
            break;
        }

    }

    while (true);
    ofstream ofs("C:\\Users\\BTC\\Desktop\\list.txt", ios::out);
    for( int i = 0; i< n; i++ )
        list[i]->write(ofs); // ghi thong tin cac nhan vien ra file OUTPUT.OUT

    ofs.close();
    ifs.close(); // dong file lai

    return 0;
}
