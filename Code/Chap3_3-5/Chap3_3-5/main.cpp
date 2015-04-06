//
//  main.cpp
//  Chap3_3-5
//
//  Created by colin on 15/4/6.
//  Copyright (c) 2015年 colin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;



int main(int argc, const char * argv[]) {
    int score_count = 3;
    vector<string> name_list;
    vector<double> score_list;
    while (true) {
        cout << "Please enter name:";
        string name;
        cin >> name;
        name_list.push_back(name);
        
        double score_sum =0;
        for (int i=0; i< score_count; i++) {
            cout << "Please enter score " << i+1  << ":";
            double score;
            cin >> score;
            score_sum+=score;
        }
        score_list.push_back(score_sum);
        
        cout << "Quit(y/n):";
        string quit;
        cin >> quit;
        if (quit == "y" || quit == "yes") {
            break;
        }
        
    }
    
    for (int i=0; i<name_list.size(); i++) {
        cout << name_list[i] << " score avg is :" << score_list[i]/score_count
            << endl;
    }
    return 0;
}
