//
//  main.cpp
//  Chap6_6-3
//
//  Created by colin on 15/4/19.
//  Copyright (c) 2015年 colin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int my_cpy(int num)
{
    return num;
}


int main(int argc, const char * argv[]) {
    vector<int> u(10,100);
    vector<int> v;
//    copy(u.begin(), u.end(), back_inserter(v));
//    transform(u.begin(), u.end(), back_inserter(v),my_cpy);
    for (vector<int>::const_iterator it=u.begin(); it!=u.end(); ++it) {
        v.push_back(*it);
    }
    return 0;
}
