//
//  main.cpp
//  Chap2_2-8
//
//  Created by colin on 15/4/5.
//  Copyright (c) 2015年 colin. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    int min = 1;
    int max = 10;
    int result=-1;
    for (int i=min; i<max; i++) {
        if (i==min) {
            result=i;
        }else{
            result*=i;
        }
    }
    std::cout << "["<<min <<","<< max << ")=>"<<result<<std::endl;
    return 0;
}
