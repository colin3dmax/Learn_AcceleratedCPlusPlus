//
//  main.cpp
//  Chap2_2-5
//
//  Created by colin on 15/4/5.
//  Copyright (c) 2015年 colin. All rights reserved.
//

#include <iostream>
#include <string>
#include <stdlib.h>
#include <unistd.h>

void drawRect(int width,int height)
{
    for(int j=0;j<height;j++){
        for (int i=0; i<width; i++) {
            std::cout<<"*";
        }
        std::cout<<std::endl;
    }
}

void drawTrangle(int width)
{
    int height = width;
    for(int j=0;j<height;j++){
        for (int i=0; i<width-j; i++) {
            std::cout<<"*";
        }
        std::cout<<std::endl;
    }
}

void cls()
{
    system("clear");
}

int main(int argc, const char * argv[]) {
    std::cout << "Enter rectangle width:";
    int width=0;
    std::cin >> width;
    int height = width;
    std::cout <<"Draw a Rect"<<std::endl;
    drawRect(width,height);
    std::cout <<"Draw a Trangle"<<std::endl;
    drawTrangle(width);
    
//    while (true) {
//        if (width>40) {
//            width=1;
//            height++;
//        }
//        if (height>20) {
//            height=1;
//        }
//        drawRect(width++,height);
//        usleep(30000);
//        cls();
//    }
    
    return 0;
}
