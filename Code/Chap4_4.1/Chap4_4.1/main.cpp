//
//  main.cpp
//  Chap4_4.1
//
//  Created by colin on 15/4/6.
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



int main(int argc, const char * argv[]) {
    cout << "Please enter your first name:";
    string name;
    cin >> name;
    cout << "Hello," << name << "!" << endl;
    
    cout << "Please enter your midterm and final exam grades:";
    double midterm,final;
    cin >> midterm >> final;
    //ask for the homework grades
    cout << "Enter all your homewor grades,"
    "followed by en-of-file:";
    vector<double> homework;
    //读取家庭作业
    read_hw(cin,homework);
    
    //计算学生成绩
    try{
        streamsize prec = cout.precision();
        double score = grade(midterm, final, homework);
        cout << "Your final grade is "<< setprecision(3) << score
             << setprecision((int)prec) << endl;
    }catch(domain_error){
        cout << endl << "You must enter your grades."
        "Please try again." <<endl;
        return 1;
    }
    
    return 0;
}