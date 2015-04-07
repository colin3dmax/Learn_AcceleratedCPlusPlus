//
//  grade.h
//  Chap4_4.3
//
//  Created by colin on 15/4/7.
//  Copyright (c) 2015年 colin. All rights reserved.
//

#ifndef __Chap4_4_3__grade__
#define __Chap4_4_3__grade__
#include <vector>
#include "Student_info.h"


double grade(double midterm,double final,double homework);

double grade(double midterm,double final,const std::vector<double>& hw);

double grade(const Student_info& s);


#endif /* defined(__Chap4_4_3__grade__) */
