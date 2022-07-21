#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>
#include<string>

std::string in;

int main(){
    int a,b;
    std::cin>>in;
    scanf(" %d %d",&a,&b);
    std::swap(in[a-1],in[b-1]);
    printf("%s\n",in.c_str());
    return 0;
}