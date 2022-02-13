#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>

std::string input;

int main(){
    int p1,p2,p3;
    scanf(" %d %d %d",&p1,&p2,&p3);
    std::cin>>input;
    for(int i = 1;i < input.size()-1;i++){
        char s2 = input[i];
        if(s2 != '-')
            continue;
        char s1 = input[i-1];
        char s3 = input[i+1];
        if(s1 == '-' || s3 == '-')
            continue;
        if(s1 >= s3 || (std::isalpha(s1) && std::isdigit(s3)) ||(std::isalpha(s3) && std::isdigit(s1)))
            continue;
        std::string str_ins;
        char ins = s1+1;
        if(p1 == 2 && std::isalpha(ins))
            ins = (ins-'a'+'A');
        if(p1 == 3)
            ins = '*';
        for(int i = (int)s1+1;i < (int)s3;i++){
            str_ins.insert(str_ins.end(),p2,ins);
            if(p1 != 3)
                ins += 1;
        }
        if(p3 == 2)
            std::reverse(str_ins.begin(),str_ins.end());
        
        input.erase(i,1);
        input.insert(i,str_ins);
        i += str_ins.size();
    }
    printf("%s\n",input.c_str());
    return 0;
}