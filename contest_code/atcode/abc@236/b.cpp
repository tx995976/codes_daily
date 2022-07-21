#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>

const int max_n = 1e5+10;

int card[max_n];

int main(){
    int n,temp,ans;
    scanf(" %d",&n);
    int range = 4*n-1;
    for(int i = 1;i <= range;i++){
        scanf(" %d",&temp);
        card[temp] += 1;
    }
    for(int i = 1;i <= range;i++){
        if(card[i] != 4){
            ans = i;
            break;
        }
    }
    printf("%d\n",ans);
    return 0;
}