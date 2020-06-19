#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include<map>
#include <Helpper.h>
#include <iostream>
#include <cstring>
#include <Employee.h>
#include <StatusDate.h>
#include<RollCallHistory.h>


using namespace std;


int main()
{
    cout<<""<<endl;
    // l?y data t? file g?c
    vector<Employee*> list;
    Employee *employee;
    int n;
    n=Helpper ::numberLine("C:\\Users\\TCC\\Desktop\\Data.csv"); // l?y ra s? d?ng
    ifstream ifs("C:\\Users\\TCC\\Desktop\\Data.csv", ios::in);
    for (int i=0 ; i < n ; i++){
        employee = new Employee();
        employee->readData(ifs,list);
        list.push_back(employee);
    }


    int choice;
    do {
        cout <<"===========================================" << endl;
        cout <<"= 1-Nhap nhan vien " << endl;
        cout <<"= 2-Tim nhan vien " << endl;
        cout <<"= 3-In ra tat ca " << endl;
        cout <<"= 4-Import nhan vien" << endl;
        cout <<"= 5-Diem danh nhan vien" << endl;
        cout <<"= 6-Xem lich su diem danh nhan vien" << endl;






        cout <<"= Chon khac de thoat                      =" << endl;
        cout <<"===========================================" << endl;
        cout << "Chon chuc nang (1-2-3-4-5 hoac khac):" << endl;
        cout << "Moi ban nhap lai lua chon = ";
        cin >> choice;

        if (choice == 1) {
            string a = "yes";
            while (a == "yes") {
                employee = new Employee();
                employee->enterEmployee(list,"C:\\Users\\TCC\\Desktop\\ImportData.csv");
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

        else if (choice ==4) { // t?o t?t c? c�c file nh�n vi�n ch? l?n �?u mu?n
            cout << "Nhap vao dia chi file can import" <<endl;
            string path;
            cin>> path ;
            path="C:\\Users\\TCC\\Desktop\\"+path;

            // ph?n n�y ch? l?y ra s? d?ng trong file csv v� xu?ng kh?i d?ng �?u ti�n
            ifstream ifs(path, ios::in);

            string abc;
            ifs >> abc;
            char ss[5];
            ifs.getline(ss, 3);// loai bo xuong dong

            //�?m s? d?ng trong file
            int n;
            n=Helpper ::numberLine(path); // l?y ra s? d?ng
            cout <<n <<endl;

            n=n-1;
            cout <<n <<endl;



            // d�ng �? l?y �c d?ng n�o b? sai
            int line=1 ;
            int *linePtr=&line;

            // th�m c�c nh�n vi�n v�o list �? d? thao t�c




            Employee *employee;
            for (int i=0 ; i < n ; i++){
                employee = new Employee();
                employee->readImport(ifs ,list ,linePtr);
               // cout<<employee->getId()<<endl;
                list.push_back(employee);
            }

            ifs.close();


        }
        else if(choice ==5){ // l�u th�ng tin �i?m danh
            // nh?p v�o id , nh?p v�o ng�y mu?n �i?m danh ,nh?p v�o tr?ng th�i mu?n �i?m danh
            StatusDate::addOrUpdateStatus(list);

        }
        else if(choice == 6){
            map<string ,string> map1;
            map1 =RollCallHistory::filterByMonth(list);
            for (map<string ,string> :: iterator it =map1.begin(); it !=map1.end(); it++) {
                cout<<it->first <<", " << it->second<<endl;
            }
        }
        else{
            break;
        }

    }

    while (true);

    ifs.close(); // ��ng �?c file
    return 0;
}
