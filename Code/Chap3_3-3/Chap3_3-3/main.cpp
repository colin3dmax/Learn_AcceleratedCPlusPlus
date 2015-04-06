//
//  main.cpp
//  Chap3_3-3
//
//  Created by colin on 15/4/6.
//  Copyright (c) 2015年 colin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <string>

using std::cout;
using std::cin;
using std::vector;
using std::map;
using std::string;
using std::endl;

typedef std::map<string, int>::size_type size_map_int;

int main(int argc, const char * argv[]) {
    map<string,int> dict;
    string words;
    std::getline(cin,words);
    const size_map_int size = words.size();
    string tmp;
    bool foundWord = false;
    
    for (int i=0; i<size; i++) {
        //识别单词
        if (words[i]!=' ') {
            foundWord=true;
            tmp.append(words.substr(i,1));
        }
        if ( (words[i]==' '||(i==size-1) ) && foundWord) {
            dict[tmp]++;
            tmp.clear();
            foundWord=false;
        }
    }
    
    
//    输出单词数据统计结果
    for (map<string,int>::iterator i=dict.begin(); i!=dict.end(); i++) {
        cout << i->first << "--->" <<i->second << endl;
    }
    
    return 0;
}
