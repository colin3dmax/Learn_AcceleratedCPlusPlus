//
//  main.cpp
//  Chap3_3-4
//
//  Created by colin on 15/4/6.
//  Copyright (c) 2015年 colin. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

//字符串分割API
std::vector<std::string> splitString(std::string words,char splitChar)
{
    std::vector<std::string> list;
    std::string tmp;
    bool foundWord = false;
    const std::vector<std::string>::size_type size = words.size();
    
    for (int i=0; i<size; i++) {
        //识别单词
        if (words[i]!=splitChar) {
            foundWord=true;
            tmp.append(words.substr(i,1));
        }
        if ( (words[i]==splitChar||(i==size-1) ) && foundWord) {
            list.push_back(tmp);
            tmp.clear();
            foundWord=false;
        }
    }
    return list;
}

int main(int argc, const char * argv[]) {
    std::string words;
    std::getline(std::cin,words);
    
    //统计最长与最短的字符串
    std::vector<std::string> list =splitString(words,' ');
    
    std::vector<std::string>::size_type min=0;
    std::vector<std::string>::size_type max=0;
    for (int i=0; i<list.size(); i++) {
        const std::vector<std::string>::size_type len = list[i].size();
        if (i==0) {
            min = len;
            max = len;
        }
        else
        {
            min = min > len ? len : min;
            max = max < len ? len: max;
    
        }
        std::cout << list[i] << std::endl;
    }
    
    
    std::cout << "min:" << min << " max:" << max << std::endl;
    return 0;
}
