#include<iostream>
#include<cstdio>
#include<algorithm>
#include<deque>
#include<string>
#include<vector>

using ll = long long;

int N,X,Y;
ll r_num[12],b_num[12];

int main(){
    scanf("%d %d %d",&N,&X,&Y);
    r_num[N] = 1;

    for(int i = N; i > 1; i--){
        if(r_num[i]){
            r_num[i-1] += r_num[i];
            b_num[i] += r_num[i] * X;
        }
        if(b_num[i]){
            r_num[i-1] += b_num[i];
            b_num[i-1] += b_num[i] * Y;
        }
    }  
    printf("%lld\n",b_num[1]);
    return 0;
}