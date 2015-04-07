//
//  main.cpp
//  Chap4_4-7
//
//  Created by colin on 15/4/7.
//  Copyright (c) 2015年 colin. All rights reserved.
//

#include <iostream>
#include <vector>


int main(int argc, const char * argv[]) {
    std::vector<double> vec;
    vec.push_back(30);
    vec.push_back(12);
    vec.push_back(122);
    vec.push_back(132);
    double sum=0;
    for(std::vector<double>::iterator it=vec.begin();it!=vec.end();++it)
    {
        sum+= *it;
    }
    std::cout << "avg=" << sum/vec.size() << std::endl;
    return 0;
}
