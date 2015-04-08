//
//  main.cpp
//  Chap5_5.8
//
//  Created by colin on 15/4/9.
//  Copyright (c) 2015年 colin. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;
//文字宽度计算
string::size_type width(const vector<string>& v )
{
    string::size_type maxlen = 0;
    for (vector<string>::size_type i =0; i!=v.size(); ++i) {
        maxlen = max(maxlen,v[i].size());
    }
    return maxlen;
}
//图案生成
vector<string> frame(const vector<string>& v)
{
    vector<string> ret;
    string::size_type maxlen = width(v);
    string border(maxlen+4,'*');
    //输出顶部的边框
    ret.push_back(border);
    //输出内部的行，每一行都用一个星号和一个空格来框起
    for (vector<string>::size_type i=0; i!=v.size(); ++i) {
        ret.push_back("*"+v[i] + string(maxlen-v[i].size(),' ')+"*");
    }
    //输出底部的边框
    ret.push_back(border);
    return ret;
}
//图案纵向连接
vector<string> vcat(const vector<string>& top,const vector<string>& bottom)
{
    //复制顶部图案
    vector<string> ret = top;
    //复制底部的图案
//    for(vector<string>::const_iterator it = bottom.begin();
//        it!=bottom.end();++it)
//    {
//        ret.push_back(*it);
//    }
    //上述循环的替代方案
    ret.insert(ret.end(), bottom.begin(),bottom.end());
    return ret;
}

vector<string> hcat(const vector<string>& left,const vector<string>& right)
{
    //复制左侧图案
    vector<string> ret = left;
    vector<string>::size_type left_size = left.size();
    vector<string>::size_type right_size = right.size();
    int i=0;
    //右侧图案拼接到左侧
    for(vector<string>::const_iterator it=right.begin(); it!=right.end(); ++it)
    {
        if( i<left_size )
        {
            ret[i]+=*it;
        }
        else
        {
            ret.push_back(*it);
        }
        ++i;
    }
    return ret;
}




int main(int argc, const char * argv[]) {
    vector<string> vet1;
    vector<string> vet2;
    string line;
    cout << "Input a frame1:"<<endl;
    int max =5;
    int index=0;
    while(cin>>line)
    {
        if(index<max)
        {
            vet1.push_back(line);
        }else{
            vet2.push_back(line);
        }
        ++index;
    }
    cout << "Input a frame2:"<<endl;
    while(cin>>line)
    {
        
    }
    //生成图案1
    vet1 = frame(vet1);
    vet2 = frame(vet2);
    //输出两个frame
    for(vector<string>::const_iterator it=vet1.begin();it!=vet1.end();++it)
    {
        cout << *it << endl;
    }
    for(vector<string>::const_iterator it=vet2.begin();it!=vet2.end();++it)
    {
        cout << *it << endl;
    }
    
    vector<string>join1;
    vector<string>join2;
    cout << "-------------------------------------1" << endl;
    join1 = vcat(vet1, vet2);
    for(vector<string>::const_iterator it=join1.begin();it!=join1.end();++it)
    {
        cout << *it << endl;
    }
    cout << "-------------------------------------2" << endl;
    join2 = hcat(vet1, vet2);
    for(vector<string>::const_iterator it=join2.begin();it!=join2.end();++it)
    {
        cout << *it << endl;
    }
    
    return 0;
}
