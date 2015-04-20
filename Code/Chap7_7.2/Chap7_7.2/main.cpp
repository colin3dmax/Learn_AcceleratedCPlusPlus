//
//  main.cpp
//  Chap7_7.2
//
//  Created by colin on 15/4/19.
//  Copyright (c) 2015年 colin. All rights reserved.
//

#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    string s;
    map<string, int>counters;
    while (cin >> s) {
        ++counters[s];
    }
    
    //输出单词以及相关的数目
    for (map<string, int>::const_iterator it=counters.begin(); it!=counters.end(); ++it ) {
        cout << it->first << "\t" << it->second << endl;
    }
    return 0;
}
