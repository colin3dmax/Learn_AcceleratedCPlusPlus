//
//  main.cpp
//  Chap4_4-3
//
//  Created by colin on 15/4/7.
//  Copyright (c) 2015年 colin. All rights reserved.
//


#include <iostream>
#include <iomanip>
using namespace std;

int pow(int num)
{
    return num*num;
}

int getNumberWidth(int number)
{
    int width=0;
    while ( number=(int)(number/10) ) {
        width++;
    }
    return width;
}


int main(int argc, const char * argv[]) {
    int from = 1;
    int end = 100;
    int blank = 1;
    int max_width = getNumberWidth(pow(end));
    for (int i=from; i<=end; ++i ) {
        cout << setw(4) << i <<  setw(max_width+blank) <<pow(i) << endl;
    }
    return 0;
}
