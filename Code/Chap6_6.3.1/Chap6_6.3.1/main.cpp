//
//  main.cpp
//  Chap6_6.3.1
//
//  Created by colin on 15/4/18.
//  Copyright (c) 2015年 colin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printMsg(string msg)
{
    cout << msg << endl;
}

bool comp(const string& str)
{
    return str=="test";
}

int main(int argc, const char * argv[]) {
    vector<string> list;
    list.push_back("abc");
    list.push_back("dsf");
    list.push_back("23");
    list.push_back("ccc");
    list.push_back("test");
    
    vector<string> new_list;
    
    remove_if(list.begin(), list.end(), comp);
    remove_copy_if(list.begin(), list.end(), back_inserter(new_list), comp);
    cout << "===================================="<< endl;
    for_each(new_list.begin(), new_list.end(), printMsg);
    
    
    
    return 0;
}
