//
//  main.cpp
//  Chap4_4-9
//
//  Created by colin on 15/4/7.
//  Copyright (c) 2015年 colin. All rights reserved.
//

#include <iostream>
#include <string>
std::string setwstr(const std::string& str,int wide)
{
    int count = wide - str.length();
    if (count>0) {
        std::string spaces(count,' ');
        return spaces+str;
    }
    return str;
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << setwstr("hello",10) <<std::endl;
    std::cout << setwstr("abcddf",10) << std::endl;
    return 0;
}
