#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>

int nums[30],t,n;
int dp[1010];

int main(){
    scanf(" %d %d",&n,&t);
    for(int i = 1;i <= n;i++)
        scanf(" %d",&nums[i]);
    dp[0] = 1;
    for(int i = 1;i <= n;i++)
        for(int L = t;L >= nums[i];L--){
            dp[L] += dp[L-nums[i]];
        }
    printf("%d\n",dp[t]);
    return 0;
}