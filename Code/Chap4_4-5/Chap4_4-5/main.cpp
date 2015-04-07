//
//  main.cpp
//  Chap4_4-5
//
//  Created by colin on 15/4/7.
//  Copyright (c) 2015年 colin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>


std::istream& read(std::istream& is, std::vector<std::string>& list,
                   std::map<std::string,int>& word_map)
{
    std::string word;
    while (is>>word) {
        list.push_back(word);
        word_map[word]++;
    }
    return  is;
}


//统计单词个数和单词频率
int main(int argc, const char * argv[]) {
    std::cout << "Enter words:";
    std::vector<std::string> list;
    std::map<std::string,int> word_map;
    read(std::cin, list,word_map);
    
//    for (std::vector<std::string>::iterator it=list.begin();
//         it!=list.end(); ++it) {
//        std::cout << it->data() << "word count:"
//                  << word_map[it->data()] << std::endl;
//    }
    
    for (std::map<std::string, int>::iterator it=word_map.begin(); it != word_map.end(); ++it) {
        std::cout << it->first << " cout:" << it->second << std::endl;
    }
    
    std::cout << "words count:" << list.size() << std::endl;
    return 0;
}
