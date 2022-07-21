#include<iostream>
#include<cstdio>
#include<algorithm>
#include<deque>
#include<string>
#include<vector>
#include<cmath>

int W;
int n;

int main(){
    scanf(" %d",&W);
    printf("300\n");
    for(int i = 1; i <= 100;i++)
        printf("%d ",i);
    for(int i = 1; i <= 100;i++)
        printf("%d ",i*100);
    for(int i = 1; i <= 100;i++)
        printf("%d ",i*10000);
    printf("\n");
    return 0;
}