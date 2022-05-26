#include <iostream>
#include <cstring>
#include <algorithm>
#include<stdio.h>
#define int long long
using namespace std;
int dp[20][1<<10];
int k,x,y;
int ai[20];
int dfs(int u,int sta,int limt,int lead)
{
    if(!u)
    {
        if(sta==((1<<(k+1))-1))return 1;
        else return 0;
    }
    if(!lead&&!limt&&dp[u][sta]!=-1)return dp[u][sta];
    int up=lead?ai[u]:9;
    int res=0;
    for(int i=0;i<=up;i++)
    {
        if(limt&&i==0)
        {
            res+=dfs(u-1,sta,limt&&!i,lead&&(i==up));
        }
        else
        {
            if(i<=k)
            {
                res+=dfs(u-1,sta|(1<<i),limt&&!i,lead&&(i==up));
            }
            else res+=dfs(u-1,sta,limt&&!i,lead&&(i==up));
        }
    }
    return lead?res:(limt?res:dp[u][sta]=res);
}
int cal(int x)
{
    memset(dp,-1,sizeof dp);
    int cnt=0;
    while(x)
    {
        ai[++cnt]=x%10;
        x/=10;
    }
    return dfs(cnt,0,1,1);
}
signed main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> k>>x>>y;
        cout << cal(y)-cal(x-1)<<endl;
    }
    return 0;
}