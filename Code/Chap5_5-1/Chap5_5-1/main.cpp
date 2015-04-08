//
//  main.cpp
//  Chap5_5-1
//
//  Created by colin on 15/4/9.
//  Copyright (c) 2015年 colin. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

string concat(const vector<string>& vec,const string& splitStr)
{
    string ret;
    for (vector<string>::const_iterator it=vec.begin(); it!=vec.end(); ++it) {
        ret+=*it+splitStr;
    }
    return ret;
}

vector<string> switchVec(const vector<string>& vec)
{
    vector<string> out;
    //置换单词
    vector<string>::size_type vec_size = vec.size();
    vector<string> vec2 = vec;
    for (vector<string>::size_type i=0; i<vec_size; ++i) {
        vector<string> vec_next;
        if (vec_size>=2) {
            for (vector<string>::const_iterator it=vec2.begin()+1; it!=vec2.end(); ++it) {
                vec_next.push_back(*it);
            }
        }
        vec_next.push_back(vec2[0]);
        
        out.push_back( concat(vec_next," "));
        vec2=vec_next;
    }
    //排序单词
    sort(out.begin(), out.end() );
    return out;
}

int main(int argc, const char * argv[]) {
    vector<string> vec;
    vector<string> out;
    string word;
    cout << "Input a line:";
    while (cin>>word) {
        vec.push_back(word);
    }
    out = switchVec(vec);
    
    //输出打印
    cout <<"----------------------"<<endl;
    for (vector<string>::const_iterator it=out.begin(); it!=out.end(); ++it) {
        cout << *it << endl;
    }
    return 0;
}
