#ifndef HELPPER_H
#define HELPPER_H
#include <vector>
#include <sstream>
using namespace std;
class Helpper{
public:
     static int numberLine(); // lấy ra số dòng trong file csv
     static vector<string> split (const string &s, char delim) ; // tách theo chuỗi theo dấu

};
#endif // HELPPER_H
