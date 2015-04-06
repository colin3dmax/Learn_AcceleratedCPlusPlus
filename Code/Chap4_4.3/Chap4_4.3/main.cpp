//
//  main.cpp
//  Chap4_4.3
//
//  Created by colin on 15/4/7.
//  Copyright (c) 2015年 colin. All rights reserved.
//


#include <iostream>
#include <vector>
#include <iomanip>
#include "median.h"
#include "Student_info.h"

using namespace std;



typedef vector<double>::size_type vec_sz;



double grade(double midterm,double final,double homework)
{
    return 0.2*midterm + 0.4*final + 0.4 *homework;
}


double grade(double midterm,double final,const vector<double>& hw)
{
    if(hw.size()==0){
        throw domain_error("student has done no homework");
    }
    return grade(midterm, final, median(hw) );
}


double grade(const Student_info& s)
{
    return grade(s.midterm, s.final, s.homework);
}



int main(int argc, const char * argv[]) {
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;
    
    //读取并存储所有的记录，然后找到最长的姓名长度
    while(read(cin, record)){
        maxlen = max(maxlen,record.name.size());
        students.push_back(record);
    }
    //按字母顺序排列记录
    sort(students.begin(), students.end(), compare);
    
    for (vector<Student_info>::size_type i=0; i!=students.size(); ++i) {
        //输出姓名，填充姓名到maxlen+1长度
        cout << setw((int)maxlen+1) << students[i].name;
        //计算学生成绩
        try{
            streamsize prec = cout.precision();
            double score = grade(students[i]);
            cout <<setw(3) << setprecision(3) << score
            << setprecision((int)prec);
        }catch(domain_error e){
            cout << e.what();
        }
        cout << endl;
    }
    
    return 0;
}