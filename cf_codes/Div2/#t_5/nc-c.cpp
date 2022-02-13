#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>
#include<string>

std::string in;

int main(){
    int flag = 0;
    std::cin>>in;
    auto it = in.find("ab");
    while(it != std::string::npos){
        in.erase(it,2);
        it = in.find("ab");
    }
    if(in.size() != 0)
        flag = 1;
    printf("%s\n",flag == 1 ? "Bad" : "Good");
    return 0;
}