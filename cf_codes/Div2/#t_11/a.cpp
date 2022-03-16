//区间dp    
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>

const int max_n = 210;
int n,num[max_n*2],sum[max_n*2];
int DP_max[max_n*2][max_n*2];

int ans_max = 0,ans_min = INT32_MAX;

int main(){
    scanf(" %d",&n);
    for(int i = 1;i <= n;i++){
        scanf(" %d",&num[i]);
        num[i+n] = num[i];
    }
    int plus = 0;
    for(int i = 1;i <= 2*n;i++){
        plus += num[i];
        sum[i] = plus;
    }

    for(int len = 2;len <= n;len++)
        for(int l = 1;l <= 2*n-1;l++){
            int r = l + len - 1;
            for(int k = l;k < r && k < 2*n;k++){
                DP_max[l][r] = std::max(DP_max[l][r],DP_max[l][k] + DP_max[k+1][r] + sum[r] - sum[l-1]);
            }
        }
    for(int i = 1;i <= n;i++)
        ans_max = std::max(DP_max[i][i+n-1],ans_max);

    for(int len = 2;len <= n;len++)
        for(int l = 1;l <= 2*n-1;l++){
            int r = l + len - 1;
            for(int k = l;k < r && k < 2*n;k++){
                DP_max[l][r] = std::min(DP_max[l][r],DP_max[l][k] + DP_max[k+1][r] + sum[r] - sum[l-1]);
            }
        }
    for(int i = 1;i <= n;i++)
        ans_min = std::min(DP_max[i][i+n-1],ans_min);
    
    printf("%d\n%d\n",ans_min,ans_max);
    return 0;
}