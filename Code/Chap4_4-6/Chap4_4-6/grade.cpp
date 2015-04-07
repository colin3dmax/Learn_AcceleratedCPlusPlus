//
//  grade.cpp
//  Chap4_4.3
//
//  Created by colin on 15/4/7.
//  Copyright (c) 2015年 colin. All rights reserved.
//
#include <stdexcept>
#include "median.h"
#include "grade.h"

double grade(double midterm,double final,double homework)
{
    return 0.2*midterm + 0.4*final + 0.4 *homework;
}


double grade(double midterm,double final,const std::vector<double>& hw)
{
    if(hw.size()==0){
        throw std::domain_error("student has done no homework");
    }
    return grade(midterm, final, median(hw) );
}

