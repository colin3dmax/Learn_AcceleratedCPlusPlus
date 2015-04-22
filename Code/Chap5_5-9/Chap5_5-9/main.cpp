//
//  main.cpp
//  Chap5_5-9
//
//  Created by colin on 15/4/12.
//  Copyright (c) 2015年 colin. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
using std::vector;
using std::cout;
using std::cin;
using std::endl;




int main(int argc, const char * argv[]) {
    vector<string> vec;
    cout << "Enter a line: " << endl;
    string word;
    while (cin >> word) {
        vec.push_back(word);
    }
    for (vector<string>::iterator it = vec.begin(); it!=vec.end(); ++it) {
        string word = *it;
        string upperWord;
        string lowerWord;
        std::transform(word.begin(), word.end(),std::back_inserter(upperWord),::toupper);
        
        std::transform(word.begin(), word.end(),std::back_inserter(lowerWord),::tolower);
        
        cout << word << endl;
        cout << "UPPER:" << upperWord << endl;
        cout << "LOWER:" << lowerWord << endl;
    }
    return 0;
}
