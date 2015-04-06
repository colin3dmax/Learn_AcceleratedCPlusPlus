//
//  main.cpp
//  Chap4_4.2.2
//
//  Created by colin on 15/4/7.
//  Copyright (c) 2015年 colin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;


struct Student_info{
    string name;
    double midterm,final;
    vector<double> homework;
};


typedef vector<double>::size_type vec_sz;

double median(vector<double> vec)
{
    typedef vector<double>::size_type vec_sz;
    vec_sz size = vec.size();
    if (size == 0) {
        throw domain_error("median of an empty vector");
    }
    
    sort(vec.begin(), vec.end());
    vec_sz mid = size/2;
    return size%2==0 ? (vec[mid]+vec[mid-1])/2 : vec[mid];
}


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


istream& read_hw(istream& in,vector<double>& hw)
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


double grade(const Student_info& s)
{
    return grade(s.midterm, s.final, s.homework);
}


istream& read(istream& is,Student_info& s)
{
    //读取并存储学生的姓名以及期中，期末考试成绩
    is >> s.name >> s.midterm >> s.final;
    //读取并存储学生的所有家庭作业成绩
    read_hw(is, s.homework);
    return is;
}


bool compare(const Student_info& x,const Student_info& y)
{
    return  x.name < y.name;
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