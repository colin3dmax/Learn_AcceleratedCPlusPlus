//
//  main.cpp
//  Chap01_2
//
//  Created by colin on 15/4/5.
//  Copyright (c) 2015年 colin. All rights reserved.
//

#include <iostream>
#include <string>

int main(int argc, const char * argv[]) {
    std::cout << "Please enter your first name:";
    std::string name;
    std::cin >> name;
    
    //构造我们将要输出的信息
    const std::string greeting = "Hello, "+ name + "!";
    //构建输出的第二和第四行
    const std::string spaces(greeting.size(),' ');
    const std::string second = "* " + spaces + " *";
    
    //构建输出的第一和第五行
    const std::string first(second.size(), '*');
    
    //输出所有的内容
    std::cout << std::endl;
    std::cout << first << std::endl;
    std::cout << second << std::endl;
    std::cout << "* " << greeting << " *" << std::endl;
    std::cout << second << std::endl;
    std::cout << first << std::endl;
    
    return 0;
}
