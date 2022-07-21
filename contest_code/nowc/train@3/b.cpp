#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>

const int max_N = 8e5+10;
int h_cow[max_N];
unsigned long ans;
std::deque<int> num_cow;

int main(){
    int num;
    scanf("%d",&num);
    for(int i = 1;i <= num;i++)
        scanf(" %d",&h_cow[i]);
    
    for(int i = 1;i <= num;i++){
        while(!num_cow.empty() && h_cow[i] >= h_cow[num_cow.back()]){
            ans += i - num_cow.back() - 1;
            num_cow.pop_back();
        }
        num_cow.push_back(i);
    }
    while(!num_cow.empty()){
        ans += num - num_cow.back();
        num_cow.pop_back();
    }

    printf("%u\n",ans);    
    return 0;
}