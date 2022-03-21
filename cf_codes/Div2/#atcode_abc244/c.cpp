#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>

bool num[2020];
int n,temp;


int main(){
    scanf(" %d",&n);
    std::cout<<1<<"\n"<<std::flush;
    num[1] = 1;
    while(scanf(" %d",&temp) && temp != 0){
        num[temp] = 1;
        for(int i = 2;i <= n*2+1;i++)
            if(!num[i]){
                std::cout<<i<<"\n"<<std::flush;
                num[i] = 1;
                break;
            }
    }
    return 0;
}