//
//  main.cpp
//  Chap5-5-6
//
//  Created by colin on 15/4/10.
//  Copyright (c) 2015年 colin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;
//运行过程中，会出错，怀疑和内存重新分配有关
//如何一边插入，还能保证后续的迭代能够正常进行
void extract_fails(vector<double>& scores)
{
    vector<double>::size_type size = scores.size();
    vector<double>::size_type pass_size =0;
    int index=0;
    for (vector<double>::iterator it=scores.begin(); it!=scores.end();++it ) {
        ++index;
        if (*it>60) {
            ++pass_size;
            cout << "pass is "<< *it << endl;
            it = scores.insert(scores.begin(), *it);
            it+=index+pass_size;
            cout << "next is "<< *it << endl;
        }
        
    }
    scores.resize(pass_size);
}

int main(int argc, const char * argv[]) {
    vector<double> scores;
    srand((unsigned)time(nullptr));
    for (int i=0; i<100; ++i) {
        int score = rand()%100;
//        cout << score << endl;
        scores.push_back(score);
    }
    
    extract_fails(scores);
    cout << "scores pass count:"<< scores.size() << endl;
    return 0;
}
