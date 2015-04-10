//
//  main.cpp
//  Chap5_5-5
//
//  Created by colin on 15/4/10.
//  Copyright (c) 2015年 colin. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

vector<string> center(const vector<string>& vec)
{
    vector<string> ret;
    string::size_type max_len = 0;
    vector<string>::size_type size = vec.size();
    int padding = 1;
    for (vector<string>::const_iterator it=vec.begin(); it!=vec.end(); ++it) {
        max_len = max_len > it->length() ? max_len : it->length();
    }
    string line = string(max_len+padding*2+2,'*');
    ret.push_back(line);
    
    string blank_line = "*"+string(max_len+padding*2,' ')+"*";
    for (int i=0;i<1.0*padding/2 ; ++i) {
        ret.push_back(blank_line);
    }
    for (vector<string>::const_iterator it=vec.begin(); it!=vec.end(); ++it) {
        string::size_type offset = max_len - it->length();
        if (it->length()) {
            string mid;
            if (offset%2==0) {
                mid = "*"+string(padding+offset/2,' ')+(*it)+string(padding+offset/2,' ')+"*";
            }else{
                mid = "*"+string(padding+(offset-1)/2,' ')+(*it)+string(padding+(offset-1)/2+1,' ')+"*";
            }
            ret.push_back(mid);
        }
    }
    for (int i=0;i<1.0*padding/2 ; ++i) {
        ret.push_back(blank_line);
    }
    ret.push_back(line);
    return ret;
}

int main(int argc, const char * argv[]) {
    vector<string> vec;
    string line;
    cout << "input lines:" << endl;
    while (cin>>line) {
        vec.push_back(line);
    }
    vec = center(vec);
    
    for (vector<string>::const_iterator it=vec.begin(); it!=vec.end(); ++it) {
        cout << *it << endl;
    }
    return 0;
}
