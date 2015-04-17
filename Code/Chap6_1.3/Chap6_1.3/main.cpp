//
//  main.cpp
//  Chap6_1.3
//
//  Created by colin on 15/4/17.
//  Copyright (c) 2015年 colin. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

vector<string> find_urls(const string& s)
{
    vector<string> ret;
    typedef string::const_iterator iter;
    iter b = s.begin(), e = s.end();
    //检查整个输入
    while (b!=e) {
        //查找一个或者多个／／的字母
        b = url_beg(b,e);
        //如果查找成功
        if (b!=e) {
            //获取此URL的其余部分
            iter after = url_end(b,e);
            //记住这个URL
            ret.push_back(string(b,after));
            
            //将b向前推进比查找位于本行的其他URL
            b = after;
        }
    }
    return ret;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
