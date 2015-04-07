//
//  main.cpp
//  Chap4_4-4
//
//  Created by colin on 15/4/7.
//  Copyright (c) 2015年 colin. All rights reserved.
//
#include <iostream>
#include <iomanip>
using namespace std;

double pow(double num)
{
    return num*num;
}

int getNumberWidth(double number)
{
    int width=1;
    int num = (int)number;
    while ( num=(int)(num/10) ) {
        width++;
    }
    return width;
}


int main(int argc, const char * argv[]) {
    double from = 1;
    double end = 100;
    int blank = 1;
    int max_width = getNumberWidth(pow(end));
    for (double i=from; i<=end; ++i ) {
        cout << setw(4) << i
            << setprecision(6)
            <<  setw(max_width+blank) <<pow(i) << endl;
    }
    return 0;
}
