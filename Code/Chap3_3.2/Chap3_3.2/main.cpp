//
//  main.cpp
//  Chap3_3.2
//
//  Created by colin on 15/4/5.
//  Copyright (c) 2015年 colin. All rights reserved.
//

#include <iostream>
#include <ios>
#include <iomanip>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::string;
using std::streamsize;
using std::vector;
using std::sort;


typedef vector<double>::size_type vec_sz;


int main(int argc, const char * argv[]) {
    cout << "Please enter your first name:";
    string name;
    cin >> name;
    cout << "Hello," << name << "!" << endl;
    
    cout << "Please enter your midterm and final exam grades:";
    double midterm,final;
    cin >> midterm >> final;
    //ask for the homework grades
    cout << "Enter all your homewor grades,"
    "followed by en-of-file:";

    //a variable into which to read
    double x;
    vector<double> homework;
    while (cin >> x) {
        homework.push_back(x);
    }
    
    vec_sz size = homework.size();
    
    if (size==0) {
        cout << endl << "You must enter your grades."
                        "Please try again." <<endl;
        return 1;
    }
    
    sort(homework.begin(),homework.end());
    vec_sz mid = size/2;
    double median;
    median = size%2 == 0 ? (homework[mid]+homework[mid-1])/2
                         : homework[mid];
    //write the result
    streamsize prec = cout.precision();
    cout << "Your final grade is "<< setprecision(3)
         << 0.2*midterm+0.4*final+ 0.4*median
         << setprecision((int)prec) << endl;
    
    return 0;
}
