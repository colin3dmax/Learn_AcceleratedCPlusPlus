//
//  main.cpp
//  Chap7_7.3
//
//  Created by colin on 15/4/19.
//  Copyright (c) 2015年 colin. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

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

map<string, vector<int>> xref(istream& in,vector<string> find_words(const string&)=split)
{
    string line;
    int line_number=0;
    map<string, vector<int> >ret;
    //读下一行
    while (getline(in,line)) {
        ++line_number;
        //把输入行分隔成单词
        vector<string> words = find_words(line);
        
        //记住出现在当前行的每一个单词
        for (vector<string>::const_iterator it=words.begin(); it!=words.end(); ++it) {
            ret[*it].push_back(line_number);
        }
    }
    return ret;
}


int main(int argc, const char * argv[]) {
    map<string,vector<int> > ret =  xref(cin);
    for (map<string, vector<int> >::const_iterator it=ret.begin(); it!=ret.end(); ++it) {
        //输出单词
        cout << it->first << " occurs on line(s):" ;
        //一个或多个行的编号
        vector<int>::const_iterator line_it = it->second.begin();
        cout << *line_it;
        
        ++line_it;
        while (line_it!=it->second.end()) {
            cout << ", " << *line_it;
            ++line_it;
        }
        cout << endl;
    }
    return 0;
}
