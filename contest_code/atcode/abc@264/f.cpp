//#动态规划
//@
#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
#include<cstring>

const int max_n = 2e3+10;
using ll = long long;

int h,w;
char gh[max_n][max_n];
ll r[max_n],c[max_n];
ll dp[max_n][max_n][2][2]; // x,y,dirc,
int dh[] = {1,0},dw[] = {0,1};



int main(){
    scanf("%d %d",&h,&w);
    for(int i = 1;i <= h;i++)
        scanf("%lld",&r[i]);

    for(int i = 1;i <= w;i++)
        scanf("%lld",&c[i]);

    for(int i = 1;i <= h;i++)
        for(int j = 1;j <= w;j++){
            scanf(" %c",&gh[i][j]);
            gh[i][j] -= '0';
        }

    auto f = [&](){
        memset(dp,0x5f,sizeof(dp));

        for(int i = 0;i <= 1;i++){
            int j = (gh[1][1] ^ i);
            dp[1][1][0][j] = i*r[1] + j*c[1];
            dp[1][1][1][i] = i*r[1] + j*c[1];
        }

        for(int i = 1;i <= h;i++)
            for(int j = 1;j <= w;j++)
                for(int d = 0;d <= 1;d++)
                    for(int l = 0;l <= 1;l++){
                        int ti = i + dh[d],tj = j + dw[d];
                        if(ti > h || tj > w)
                            continue;
                        int bfilp = gh[ti][tj] ^ l, val = 0;
                        if(d == 0) 
                            val = r[ti]*bfilp;
                        else
                            val = c[tj]*bfilp;

                        for(int td = 0;td <= 1;td++){
                            int tl = l;
                            if(d != td)
                                tl = bfilp;
                            //printf("be :%lld %lld\n", dp[ti][tj][td][tl],dp[i][j][d][l] + val);
                            dp[ti][tj][td][tl] = std::min(dp[ti][tj][td][tl],dp[i][j][d][l] + val);
                            //printf("af: %lld \n", dp[ti][tj][td][tl]);
                        }
                    }
        ll res = INT64_MAX-1;
        for(int i = 0;i <= 1;i++)
            for(int j = 0;j <= 1;j++)
                res = std::min(res,dp[h][w][i][j]);
        return res;
    };
    
    ll ans = f();
    for(int i = 1;i <= h;i++)
        for(int j = 1;j <= w;j++)
            gh[i][j] ^= 1;

    ans = std::min(ans,f());
    printf("%lld\n",ans);
    return 0;
}