//
//  main.cpp
//  Chap5_5-3
//
//  Created by colin on 15/4/10.
//  Copyright (c) 2015年 colin. All rights reserved.
//

#include <iostream>
#include <time.h>
#include <sstream>
#include <string>
#include <vector>
#include <list>



using namespace std;
struct Student{
    string name;
    double score;
};

typedef vector<Student> vec_student;


string tostring(const double num)
{
    stringstream ss;
    ss << num;
    return ss.str();
}

string tostring(const int num)
{
    stringstream ss;
    ss << num;
    return ss.str();
}

vec_student findFail(const vec_student& students)
{
    vector<Student> ret;
    //排序查找出不及格的学生
    for (vec_student::const_iterator it=students.begin(); it!=students.end(); ++it) {
        if (it->score<60) {
            //            cout << it->name << "--->"<< it->score << endl;
            ret.push_back(*it);
        }
    }
    return ret;
}

list<Student> findFail(const list<Student>& students)
{
    list<Student> ret;
    //排序查找出不及格的学生
    for (list<Student>::const_iterator it=students.begin(); it!=students.end(); ++it) {
        if (it->score<60) {
            //            cout << it->name << "--->"<< it->score << endl;
            ret.push_back(*it);
        }
    }
    return ret;
}
void test(int sample_count)
{
    srand((unsigned)time(NULL));
    Student student;
    vec_student vec_students;
    list<Student> list_students;
    for (int i=0; i<sample_count; ++i) {
        student.name="Tom"+tostring(i);
        student.score = rand()%100;
        vec_students.push_back(student);
        list_students.push_back(student);
    }
    clock_t begin= clock();
    findFail(vec_students);
    cout << sample_count<< " vec cost " << (clock()-begin) <<" clock" <<endl;
    begin= clock();
    findFail(list_students);
    cout <<sample_count <<" list cost " << (clock()-begin) <<" clock"<<endl;
    cout << "------------------------------" << endl;
}
int main(int argc, const char * argv[]) {
    
    /*
     
     无push_back操作时
     
     10 vec cost 16 clock
     10 list cost 2 clock
     ------------------------------
     100 vec cost 6 clock
     100 list cost 3 clock
     ------------------------------
     1000 vec cost 32 clock
     1000 list cost 28 clock
     ------------------------------
     10000 vec cost 122 clock
     10000 list cost 165 clock
     ------------------------------
     100000 vec cost 1217 clock
     100000 list cost 1812 clock
     ------------------------------
     1000000 vec cost 13434 clock
     1000000 list cost 16476 clock
     ------------------------------
     10000000 vec cost 122159 clock
     10000000 list cost 174801 clock
     ------------------------------
     
     
     push_back操作时
     10 vec cost 16 clock
     10 list cost 3 clock
     ------------------------------
     100 vec cost 8 clock
     100 list cost 13 clock
     ------------------------------
     1000 vec cost 81 clock
     1000 list cost 112 clock
     ------------------------------
     10000 vec cost 528 clock
     10000 list cost 1072 clock
     ------------------------------
     100000 vec cost 4929 clock
     100000 list cost 12118 clock
     ------------------------------
     1000000 vec cost 70567 clock
     1000000 list cost 116765 clock
     ------------------------------
     10000000 vec cost 719280 clock
     10000000 list cost 1202816 clock
     ------------------------------
     
     
     */
    
    test(10);
    
    return 0;
}
