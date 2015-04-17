//
//  main.cpp
//  Chap6_1.2
//
//  Created by colin on 15/4/17.
//  Copyright (c) 2015年 colin. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool is_palindrome(const string& s)
{
    return equal(s.begin(), s.end(), s.rbegin());
}
void printBool(bool b)
{
    cout << (b? "true" :"false");
}

int main(int argc, const char * argv[]) {
    string word = "abcba";
    printBool( is_palindrome(word));
    return 0;
}
