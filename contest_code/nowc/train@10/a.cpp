#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>

using ll = int64_t;

ll dp[30][15][15];
ll gra[15][15];
int x,y,temp,n;

ll max_4(ll a,ll b,ll c,ll d){
    return std::max(std::max(a,b),std::max(c,d));
}

int main(){
    scanf(" %d",&n);
    while(scanf(" %d %d %d",&x,&y,&temp) == 3){
        gra[x][y] = temp;
    }
    //dp[0][1][1] = gra[1][1];
    for(int g = 1;g <= 2*n-1;g++){
        int l = g > n ? g-n+1 : 1;
        int r = g > n ? n : g;
        for(int i = l;i <= r;i++)
            for(int j = l;j <= r;j++){
                if(i != j)
                    dp[g][i][j] = gra[i][g-i+1]+gra[j][g-j+1];
                else
                    dp[g][i][j] = gra[i][g-i+1];
                 dp[g][i][j] += max_4(dp[g-1][i][j],dp[g-1][i-1][j],dp[g-1][i][j-1],dp[g-1][i-1][j-1]);
            }
    }
    printf("%lld\n",dp[2*n-1][n][n]);
    return 0;
}


