#include<iostream>
#include<cstdio>
#include<algorithm>
#include<deque>
#include<string>
#include<vector>

const int max_n = 2e5+10;
int N,tmp;
std::vector<long long> cnt(max_n,0ll);
long long ans = 0ll;
int lim;

int main(){
    scanf(" %d",&N);
    for(int i = 1;i <= N;i++){
        scanf(" %d",&tmp);
        cnt[tmp] += 1;
    }
    for(int i = 1;i <= max_n;i++){
        if(cnt[i])
            for(int j = 1;j <= max_n/i;j++){
                ans += cnt[i]*cnt[j]*cnt[i*j];
            }
    }
    printf("%lld\n",ans);
    return 0;
}