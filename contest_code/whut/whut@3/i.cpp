#include<iostream>
#include<cstdio>
#include<algorithm>
#include<deque>
#include<string>
#include<vector>
#include<cstring>

using ll = long long;

ll dp[30][20];
int dig[20];

ll dfs(int pos,int pre,bool lim){
    if(pos == -1) 
        return 1;
    if(!lim && dp[pos][pre] != -1)
        return dp[pos][pre];
    ll h = lim ? dig[pos] : 9;
    ll ret = 0ll;

    if(pre == 0){
        for(int i = 0;i <= h;i++){
            ret += dfs(pos-1,i, lim && i == dig[pos]);
        }
    }
    else{
        ret += dfs(pos-1,0,lim && 0 == dig[pos]);
        for(int i = 1;i <= h;i++){
            if(i % pre == 0 || pre % i == 0)
                ret += dfs(pos - 1,i,lim && i == dig[pos]);
        }
    }
    
    if(!lim && dp[pos][pre] == -1)
        dp[pos][pre] = ret;
    return ret;
}

ll pre_(ll ran){
    int pos = 0;
    while(ran){
        dig[pos++] = ran % 10;
        ran /= 10;
    }
    return dfs(pos - 1,0,1);
}

int main(){
    int t,l,r;
    scanf(" %d",&t);
    while(t--){
        memset(dp,-1,sizeof(dp));
        scanf(" %d %d",&l,&r);
        printf("%lld\n",pre_(r) - pre_(l - 1));
    }
    return 0;
}