//
//  Student_info.h
//  Chap4_4.3
//
//  Created by colin on 15/4/7.
//  Copyright (c) 2015年 colin. All rights reserved.
//

#ifndef __Chap4_4_3__Student_info__
#define __Chap4_4_3__Student_info__
#include <string>
#include <vector>
#include <iostream>

struct Student_info{
    std::string name;
    double midterm,final;
    std::vector<double> homework;
};

std::istream& read_hw(std::istream& in,std::vector<double>& hw);
std::istream& read(std::istream& is,Student_info& s);
bool compare(const Student_info& x,const Student_info& y);

#endif /* defined(__Chap4_4_3__Student_info__) */
