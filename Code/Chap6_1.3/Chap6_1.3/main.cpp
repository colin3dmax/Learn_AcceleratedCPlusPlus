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
bool not_url_char(char c);


string::const_iterator url_end(string::const_iterator b,string::const_iterator e)
{
    return find_if(b , e , not_url_char);
}

bool not_url_char(char c)
{
    static const string url_ch = "~;/?:@=&$-_.+!*'`(),";
    
    return !(isalnum(c) || find(url_ch.begin(),url_ch.end(),c)!=url_ch.end());
}

string::const_iterator url_beg(string::const_iterator b, string::const_iterator e)
{
    static const string sep ="://";
    typedef string::const_iterator iter;
    
    //i标记了查找到的分隔符的位置
    iter i=b;
    while ((i=search(i,e,sep.begin(),sep.end()))!=e) {
        //确保分隔符不是本行中唯一的一个符号
        if (i!=b && i+sep.size() != e) {
            //beg 标记协议名称的开头
            iter beg = i;
            while (beg!=b && isalpha(beg[-1])) {
                --beg;
            }
            
            //在分隔符前面以及后面至少有一个字符吗？
            if (beg!=i && i+sep.size() != e  && !not_url_char(i[sep.size()])) {
                return beg;
            }
        }
        
        //我们找到的分隔符不是一个URL的一部分
        if (i!=e) {
            i+=sep.size();
        }
    }
    return e;
}



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
    vector<string> result = find_urls("http://www.baidu.com/aaa&sdf=32");
    for (vector<string>::const_iterator it=result.begin(); it!=result.end(); ++it) {
        cout << *it << endl;
    }
    
    
    
    return 0;
}
