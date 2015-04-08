//
//  main.cpp
//  Chap5_5.5
//
//  Created by colin on 15/4/7.
//  Copyright (c) 2015年 colin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> split(const string& s,char splitChar)
{
    vector<string> ret;
    typedef string::size_type string_size;
    string_size i =0;
    
    while (i!=s.size()) {
        //忽略字符串前面的空格
        while (i!=s.size() && (s[i]==splitChar) ) {
            ++i;
        }
        //找出下一个单词的终结点
        string_size j = i;
        while (j!=s.size() && (s[j]!=splitChar) ){
            ++j;
        }
        //如果找到了一连串的非空白字符
        if (i!=j) {
            //保存i-j的字符
            ret.push_back(s.substr(i,j-i));
            i=j;
        }
    }
    return ret;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    string test = "hello boy; ab;;c   123";
    vector<string> strArray = split(test,' ');
    for (vector<string>::iterator it = strArray.begin(); it != strArray.end(); ++it) {
        cout << *it << endl;
    }
    std::cout << "Hello, World!\n";
    return 0;
}
