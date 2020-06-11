#include "Helpper.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

int Helpper :: numberLine(){ // hàm đếm số dòng trong file
    ifstream f1;
    char c;
    int numchars, numlines;

    f1.open("C:\\Users\\BTC\\Desktop\\ImportData.csv");

    numchars = 0;
    numlines = 0;
    f1.get(c);
    while (f1) {
        while (f1 && c != '\n') {
            numchars = numchars + 1;
            f1.get(c);
        }
        numlines = numlines + 1;
        f1.get(c);
    }
    //      cout << "The file has " << numlines << " lines and "
    //        << numchars << " characters" << endl;
    return(numlines);
}
vector<string> Helpper ::split(const string &s, char delim){
    vector<string> result;
    stringstream ss (s);
    string item;

    while (getline (ss, item, delim)) {
        result.push_back (item);
    }

    return result;
}



