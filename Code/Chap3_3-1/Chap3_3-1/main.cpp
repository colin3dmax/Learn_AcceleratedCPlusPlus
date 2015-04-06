//
//  main.cpp
//  Chap3_3-1
//
//  Created by colin on 15/4/6.
//  Copyright (c) 2015年 colin. All rights reserved.
//

#include <iostream>
#include <vector>
using std::vector;
using std::sort;
using std::cout;
using std::cin;
using std::endl;

typedef std::vector<int>::size_type sz_int;

void printlist(std::vector<int>list,sz_int from,sz_int end)
{
    for (sz_int i=from; i<end; i++) {
        cout << list[i] << endl;
    }
    cout << "==================" << endl;
}

int main(int argc, const char * argv[]) {
    std::vector<int> list;
    int number;
    while (cin>>number) {
        list.push_back(number);
    }
    sz_int size=list.size();
    if (size<4) {
        cout << "Please enter more then 4 numbers!" << endl;
        return 1;
    }
    sort(list.begin(),list.end());
    sz_int each_item_size = size/4;
    
    for (int i=0; i<4; i++) {
        if(i==3){
            printlist(list, i*each_item_size, size);
        }else{
            printlist(list, i*each_item_size, (i+1)*each_item_size);
        }
    }
    
    
    
    
    return 0;
}
