//
//  main.cpp
//  Chap3_3.1
//
//  Created by colin on 15/4/5.
//  Copyright (c) 2015年 colin. All rights reserved.
//

#include <iostream>
#include <ios>
#include <iomanip>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::string;
using std::streamsize;

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
    int count = 0;
    double sum = 0;
    //a variable into which to read
    double x;
    //invariant:
    //we have read count grades so far, and
    //sum is the sum of the first count grades
    while (cin >> x) {
        ++count;
        sum += x;
    }
    //write the result
    streamsize prec = cout.precision();
    cout << "Your final grade is "<< setprecision(3)
         << 0.2*midterm+0.4*final+ 0.4*sum/count
         << setprecision((int)prec) << endl;
    
    return 0;
}
