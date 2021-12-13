#include<iostream>
#include<algorithm>
#include<cstdio>

using ll = long long;

const int max_n = 5e5+10;
ll array[max_n] = {0};

void solve(){
    int i,head,length;
    scanf("%d",&i);
    while(i--){
        scanf("%d %d",&head,&length);
        printf("%lld\n",array[head+length-1]-array[head-1]);
    }
    return;
}

int main(){
    int i;
    scanf("%d",&i);
    for(int j = 1; j <= i;j++){
        scanf("%lld",&array[j]);
        array[j] += array[j-1];
    }
    solve();
    return 0;
}