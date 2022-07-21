//tx995976
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>

const int max_n = 1e2+10;

int n,ans;
int h[max_n];
int max_queue_up[max_n],max_queue_down[max_n];

int main(){
    scanf(" %d",&n);
    for(int i = 1;i <= n;i++)
        scanf(" %d",&h[i]);
    for(int i = 1;i <= n;i++){
        int cnt = 0;
        for(int j = 1;j < i;j++)
            if(h[j] < h[i])
                cnt = std::max(max_queue_up[j],cnt);
        max_queue_up[i] = cnt + 1;
    }
    for(int i = n;i >= 1;i--){
        int cnt = 0;
        for(int j = n;j > i;j--)
            if(h[j] < h[i])
                cnt = std::max(cnt,max_queue_down[j]);
        max_queue_down[i] = cnt + 1;
        ans = std::max(ans,(max_queue_up[i]+max_queue_down[i]));
    }
    printf("%d\n",n-ans+1);
    return 0;
}