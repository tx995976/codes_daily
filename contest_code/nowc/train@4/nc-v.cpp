#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>

const int max_n = 1e9;
const int max_r = sqrt(max_n);

int main(){
    int n,l,r,cnt;
    scanf(" %d",&n);
    for(int i = 1;i <= n;i++){
        scanf(" %d %d",&l,&r);
        int num_l = sqrt(l),num_r = sqrt(r);
        cnt = num_r - num_l;
        if(num_l*num_l == l)
            cnt++;
        printf("%d\n",cnt);
    }    
    return 0;
}