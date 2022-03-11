#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>

int book[] = {10,20,50,100};
int n,m;
int dp[2010];

int main(){
    scanf(" %d",&n);
    dp[0] = 1;
    for(int i = 0;i <= 3;i++)
        for(int j = book[i];j <= n;j++)
            dp[j] += dp[j-book[i]];
    printf("%d\n",dp[n]);
    return 0;
}