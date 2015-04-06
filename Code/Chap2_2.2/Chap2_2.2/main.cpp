//
//  main.cpp
//  Chap2_2.2
//
//  Created by colin on 15/4/5.
//  Copyright (c) 2015年 colin. All rights reserved.
//

#include <iostream>
#include <string>


int main(int argc, const char * argv[]) {
    //请输入用户的姓名
    std::cout << "Please enter your first name:";
    //读入姓名
    std::string name;
    std::cin >> name;
    
    //构造我们奥输出的信息
    const std::string greeting = "Hello, "+name+"!";
    //围住问候语的空白行数
    const int pad = 1;
    //所有要输出的行数
    const int rows = pad*2+3;
    //输入和输出分开
    std::cout << std::endl;
    //输出rows行
    int r = 0;
    //不变式：到目前为止，我们已经输出了r行
    while (r!=rows) {
        //输出一行
        const std::string::size_type cols = greeting.size() + pad*2+2;
        std::string::size_type c = 0;
        while (c!=cols) {
            if (r==0 || r==rows-1 || c ==0 || c==cols -1) {
                std::cout << "*";
                ++c;
            }else{
                if (r==pad+1 && c==pad+1) {
                    std::cout << greeting;
                    c+= greeting.size();
                }else{
                    if(r == 0 || r==rows -1 || c == 0 || c== cols -1 )
                        std::cout << "*";
                    else
                        std::cout << " ";
                    ++c;
                }
            }
        }
        std::cout << std::endl;
        ++r;
    }
    
    return 0;
}
