//
//  median.cpp
//  Chap4_4.3
//
//  Created by colin on 15/4/7.
//  Copyright (c) 2015年 colin. All rights reserved.
//

#include "median.h"

double median(std::vector<double> vec)
{
    typedef std::vector<double>::size_type vec_sz;
    vec_sz size = vec.size();
    if (size == 0) {
        throw std::domain_error("median of an empty vector");
    }
    
    std::sort(vec.begin(), vec.end());
    vec_sz mid = size/2;
    return size%2==0 ? (vec[mid]+vec[mid-1])/2 : vec[mid];
}
