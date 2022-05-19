#include<iostream>
#include<cstdio>
#include<algorithm>
#include<deque>
#include<string>
#include<vector>

std::vector<std::string> num;
std::string in;
std::string str;

int main(){
    in.resize(4);
    std::cin>>str;    
    while(sscanf(str.data(),"%3[A-F0-9]",in.data()))
        printf("%s\n",in.c_str());

    return 0;
}