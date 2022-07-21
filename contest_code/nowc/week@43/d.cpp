#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>

const int max_N = 5e5+10;

int array[max_N],next_odd[max_N];
long long ans = 0;

int main(){
    int n;
    scanf(" %d",&n);
    for(int i = 1;i <= n;i++){
        scanf(" %d",&array[i]);
        array[i] = array[i] & 1;
    }
    int pos_odd = n+1;
    for(int i = n;i >= 1;i--){
        if(array[i])
            pos_odd = i;
        next_odd[i] = pos_odd;
    }
    for(int i = 1;i <= n;i++){
        if(array[i])
            ans += n-i+1;
        else 
            ans += n-next_odd[i]+1;
    }
    printf("%lld\n",ans);
    return 0;
}