#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>

const int max_n = 2e2+10;
int N,M;
int a[max_n],c[max_n],b[max_n];

int main(){
    scanf(" %d %d",&N,&M);
    for(int i = 0;i <= N;i++)
        scanf(" %d",&a[i]);
    for(int i = 0;i <= N+M;i++)
        scanf(" %d",&c[i]);
    
    for(int i = M;i >= 0;i--){
        b[i] = c[i+N] / a[N];
        for(int j = 0;j <= N;j++)
            c[i+j] -= b[i] * a[j];
    }
    for(int i = 0;i <= M;i++)
        printf("%d%c",b[i],i == M ? '\n' : ' ');
    return 0;
}