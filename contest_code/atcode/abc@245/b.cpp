#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>

const int max_N = 2e3+10;
int N,temp;
bool A[max_N];

int main(){
    scanf(" %d",&N);
    while(N--){
        scanf(" %d",&temp);
        A[temp] = 1;
    }
    for(int i = 0;i <= max_N;i++){
        if(!A[i]){
            temp = i;
            break;
        }
    }
    printf("%d\n",temp);
    return 0;
}