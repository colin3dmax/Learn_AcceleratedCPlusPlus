//
//  main.cpp
//  Chap6_1.1
//
//  Created by colin on 15/4/16.
//  Copyright (c) 2015年 colin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
string testCopy(const string& word)
{
    string ret;
    copy(word.begin(), word.end(),back_inserter(ret));
    return ret;
}

bool space(char c)
{
    return isspace(c);
}

bool not_space(char c)
{
    return !isspace(c);
}

vector<string> split(const string& str)
{
    typedef string::const_iterator iter;
    vector<string> ret;
    iter i = str.begin();
    while (i!=str.end()) {
        //忽略前段的空白
        i = find_if(i, str.end(), not_space);
        //查找下一个单词的结尾
        iter j = find_if(i, str.end(), space);
        //复制在［i，j）中的字符
        if (i!=str.end()) {
            ret.push_back(string(i,j));
        }
        i=j;
    }
    return ret;
}



int main(int argc, const char * argv[]) {
    
    string word="abc hello efg";
    std::cout << testCopy(word) << endl;
    
    vector<string> list = split(word);
    for (vector<string>::const_iterator it=list.begin(); it!=list.end(); ++it) {
        cout << *it << endl;
    }
    
    
    return 0;
}
