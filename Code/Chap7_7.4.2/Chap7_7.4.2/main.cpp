//
//  main.cpp
//  Chap7_7.4.2
//
//  Created by colin on 15/4/20.
//  Copyright (c) 2015年 colin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;
typedef vector<string> Rule;
typedef vector<Rule> Rule_collection;
typedef map<string, Rule_collection> Grammar;

bool space(char c)
{
    return isspace(c);
}

bool not_space(char c)
{
    return !isspace(c);
}

vector<string> split(const string& str)
{
    typedef string::const_iterator iter;
    vector<string> ret;
    iter i = str.begin();
    while (i!=str.end()) {
        //忽略前段的空白
        i = find_if(i, str.end(), not_space);
        //查找下一个单词的结尾
        iter j = find_if(i, str.end(), space);
        //复制在［i，j）中的字符
        if (i!=str.end()) {
            ret.push_back(string(i,j));
        }
        i=j;
    }
    return ret;
}


Grammar read_grammer(istream& in)
{
    Grammar ret;
    string line;
    //读输入
    while (getline(in,line)) {
        //把输入分割成单词
        vector<string> entry = split(line);
        if (!entry.empty()) {
            ret[entry[0]].push_back(Rule(entry.begin()+1,entry.end()));
        }
    }
    return ret;
}


bool bracketed(const string& s)
{
    return s.size() >1 && s[0]=='<' && s[s.size()-1]=='>';
}

int nrand(int n)
{
    if (n<=0 || n > RAND_MAX) {
        throw domain_error("Argument to nrand is out of range");
    }
    const int bucket_size = RAND_MAX /n;
    int r;
    do r = rand() / bucket_size;
    while (r>=n) ;
    return r;
}



void gen_aux(const Grammar& g,const string& word,vector<string>& ret)
{
    if (!bracketed(word)) {
        ret.push_back(word);
    }else{
        Grammar::const_iterator it = g.find(word);
        if (it==g.end()) {
            throw logic_error("empty rule");
        }
        //获取可能的规则集合
        const Rule_collection& c = it->second;
        //从规则集合中随机选择一条规则
        const Rule& r = c[ nrand(c.size()) ];
        //递归展开所选定的规则
        for (Rule::const_iterator i=r.begin(); i!=r.end(); ++i) {
            gen_aux(g, *i, ret);
        }
        
    }
}


vector<string> gen_sentence(const Grammar& g)
{
    vector<string> ret;
    gen_aux(g,"<sentence>",ret);
    return ret;
}




int main(int argc, const char * argv[]) {
    Grammar grammar = read_grammer(cin);
    vector<string> sentence = gen_sentence(grammar);
    
    //输出第一个单词，如果存在的话
    vector<string>::const_iterator it = sentence.begin();
    if (!sentence.empty()) {
        cout << *it ;
        ++it;
    }
    
    //输出其余的单词，单词之间空一格
    while (it!=sentence.end()) {
        cout << " " << *it;
        ++it;
    }
    cout << endl;
    
    return 0;
}
