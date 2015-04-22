//
//  main.cpp
//  Chap5_5-11
//
//  Created by colin on 15/4/15.
//  Copyright (c) 2015年 colin. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

bool hasUpLineAlpha(const string& word)
{
    bool has=false;
    for (string::const_iterator it=word.begin(); it!=word.end(); ++it) {
        string list="bdfhkl";
        for (string::const_iterator it2=list.begin(); it2!=list.end(); ++it2) {
            if (*it==*it2) {
                has=true;
                break;
            }
        }
    }
    return has;
}

bool hasLowerLineAlpha(const string& word)
{
    bool has=false;
    for (string::const_iterator it=word.begin(); it!=word.end(); ++it) {
        string list="gjpqy";
        for (string::const_iterator it2=list.begin(); it2!=list.end(); ++it2) {
            if (*it==*it2) {
                has=true;
                break;
            }
        }
    }
    return has;
}

bool hasNoUpAndLowerLineAlpha(const string& word)
{
    return !hasUpLineAlpha(word) && !hasLowerLineAlpha(word);
}

int main(int argc, const char * argv[]) {
    string word = "gjp";
    cout << word << ":" << (hasUpLineAlpha(word)?"True":"False") << endl;
    cout << word << "->hasNoUpAndLowerLineAlpha:"<< (hasLowerLineAlpha(word)?"True":"False") << endl;
    return 0;
}
