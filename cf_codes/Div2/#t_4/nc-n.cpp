#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>

std::string nums[30];

bool cmp(std::string &l,std::string &r){
    return l+r > r+l;
}

int main(){
    int n;
    scanf(" %d",&n);
    for(int i = 1;i <= n;i++)
        std::cin>>nums[i];
    std::sort(nums+1,nums+1+n,cmp);
    for(int i = 1;i <= n;i++)
        printf("%s",nums[i].c_str());
    printf("\n");
    return 0;
}