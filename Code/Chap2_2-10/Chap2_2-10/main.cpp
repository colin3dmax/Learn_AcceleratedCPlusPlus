//
//  main.cpp
//  Chap2_2-10
//
//  Created by colin on 15/4/5.
//  Copyright (c) 2015年 colin. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    int k=0;
    int n=5;
    while (k!=n) {
        using std::cout;
        cout << "*";
        ++k;
    }
    std::cout << std::endl;
    return 0;
}
