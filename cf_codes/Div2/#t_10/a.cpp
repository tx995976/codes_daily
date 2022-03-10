#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>

int dp[30][15][15];
int gra[15][15];
int x,y,temp,n;

int main(){
    scanf(" %d",&n);
    while(scanf(" %d %d %d",&x,&y,&temp) == 3){
        gra[x][y] = temp;
    }
    dp[0][1][1] = gra[1][1];
    for(int g = 1;g <= 2*(n-1);g++)
        for(int i = g > )

    return 0;
}
