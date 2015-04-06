//
//  main.cpp
//  Chap2_2-9
//
//  Created by colin on 15/4/5.
//  Copyright (c) 2015年 colin. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Input two number:";
    int a,b;
    std::cin >> a >>b;
    if(a>b){
        std::cout << "big is "<<a<<std::endl;
    }else{
        std::cout << "big is "<<b<<std::endl;
    }
    return 0;
}
