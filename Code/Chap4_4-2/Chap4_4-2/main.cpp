//
//  main.cpp
//  Chap4_4-2
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
int main(int argc, const char * argv[]) {
    int from = 1;
    int end = 100;
    for (int i=from; i<=end; ++i ) {
        cout << setw(4) << i <<  setw(10) <<pow(i) << endl;
    }
    return 0;
}
