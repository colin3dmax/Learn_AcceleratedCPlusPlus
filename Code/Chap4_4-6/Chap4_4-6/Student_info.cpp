//
//  Student_info.cpp
//  Chap4_4.3
//
//  Created by colin on 15/4/7.
//  Copyright (c) 2015年 colin. All rights reserved.
//

#include "Student_info.h"
#include "grade.h"



std::istream& read_hw(std::istream& in,std::vector<double>& hw)
{
    
    //a variable into which to read
    if (in) {
        hw.clear();
        double x;
        while (in >> x) {
            hw.push_back(x);
        }
        //clear cin
        in.clear();
    }
    
    return in;
}



std::istream& read(std::istream& is,Student_info& s)
{
    //读取并存储学生的姓名以及期中，期末考试成绩
    is >> s.name;
    double mid = 0;
    is>>mid;
    double final = 0;
    is>>final;
    //读取并存储学生的所有家庭作业成绩
    std::vector<double> homework;
    read_hw(is, homework);
    s.score = grade(mid, final, homework);
    return is;
}


bool compare(const Student_info& x,const Student_info& y)
{
    return  x.name < y.name;
}

