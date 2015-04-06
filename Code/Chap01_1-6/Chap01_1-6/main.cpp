//
//  main.cpp
//  Chap01_1-6
//
//  Created by colin on 15/4/5.
//  Copyright (c) 2015年 colin. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    std::cout << "What is your name? ";
    std::string name;
    std::cin >> name;
    std::cout << "Hello, " << name
              << std::endl << "And what is yours? ";
    std::cin >> name;
    std::cout << "Hello, " << name
              << ";nice to meet you too!" << std::endl;
    return 0;
}
