//
//  main.cpp
//  Chap01_1
//
//  Created by colin on 15/4/5.
//  Copyright (c) 2015年 colin. All rights reserved.
//

#include <iostream>
#include <string>

int main()
{
//    输入姓名
    std::cout << "Please enter your first name:";
//    读姓名
    std::string name;   //定义变量name
    std::cin >> name;   //把姓名读进name
//    输出对这个人的问候语
    std::cout << "Hello, " << name << "!" << std::endl;
    return 0;
}