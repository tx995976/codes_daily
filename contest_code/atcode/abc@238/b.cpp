#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>

const int max_n = 400;
int pos[max_n];

int main(){
    int n,temp,plus = 0,ans = 0;
    pos[0] = 0;
    scanf(" %d",&n);
    for(int i = 1;i <= n;i++){
        scanf(" %d",&temp);
        plus =(plus + temp)%360;
        pos[i] = plus;
    }
    std::sort(pos,pos+n+1);
    for(int i = 1;i <= n;i++)
        ans = std::max(ans,pos[i] - pos[i-1]);
    ans = std::max(ans,360-pos[n]);
    printf("%d\n",ans);
    return 0;
}