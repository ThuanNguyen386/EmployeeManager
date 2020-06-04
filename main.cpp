#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <Employee.h>

using namespace std;

int main()
{
    vector<Employee*> list;
    ifstream ifs("C:\\Users\\khiem\\Desktop\\list.txt", ios::in);
    Employee *employee;
    int n;
    ifs >> n;
    cout <<n;

    char ss[5];
    ifs.getline(ss,3);// loai bo xuong dong
    for (int i=0 ; i < n ; i++){
        employee = new Employee();
        employee->doc(ifs);
        list.push_back(employee);
    }
    ifs.close();
    int choice;
    do {
        cout <<"===========================================" <<endl;
        cout <<"= 1-Nhap nhan vien                        =" << endl;
        cout <<"= 2-Xuat nhan vien                        =" << endl;
        cout <<"= Chon khac de thoat                        =" << endl;
        cout <<"===========================================" <<endl;
        cout << "Chon chuc nang (1-2 hoac khac):" << endl;
        cout << "Moi ban nhap lai lua chon = ";
        cin >> choice;
        if (choice==1) {
            string a="yes";
            while (a=="yes") {
                employee = new Employee();
                employee->enterEmployee();
                list.push_back(employee);
                n = n + 1;
                cout << "Ban muon nhap tiep khong ,an yes ; neu muon thoat an phim bat ky \n"<<endl;
                cin >> a;
            }
        }


        else if(choice==2 )
        {
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
    ofstream ofs("C:\\Users\\khiem\\Desktop\\list.txt",ios::out);
    ofs << n << endl;
    for( int i = 0; i< n; i++ )
        list[i]->ghi(ofs); // ghi thong tin cac sinh vien ra file OUTPUT.OUT

    ofs.close();
    ifs.close(); // dong file lai

    cout << "Xin tam biet ban <3" << endl;
    return 0;
}
