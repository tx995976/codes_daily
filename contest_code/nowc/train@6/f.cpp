#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>

const int max_n = 1e5+10;
char ans[max_n];
int n;

int d_a[max_n],d_b[max_n];
int vis[max_n],reach[max_n],flag = 0;

bool dfs(int p,int round){
    if(p>n-1||p<0)
        return 0;
    if(p == n-1){
        ans[round] = '\0';
        return 1;
    }
    if(vis[p]){
        reach[p] = 1;
        return 0;
    }
    vis[p] = 1;
    if(dfs(p+d_a[p],round+1)){
        ans[round] = 'a';
        if(reach[p])
            flag = 1;
        return 1;
    }
    if(dfs(p+d_b[p],round+1)){
        ans[round] = 'b';
        if(reach[p])
            flag = 1;
        return 1;
    }
    return 0;
}

int main(){
    scanf(" %d",&n);
    for(int i = 0;i < n;i++)
        scanf(" %d",&d_a[i]);
    for(int i = 0;i < n;i++)
        scanf(" %d",&d_b[i]);
    if(dfs(0,0)){
        if(flag)
            printf("Infinity!\n");
        else
            printf("%s\n",ans);
    }
    else
        printf("No solution!\n");
    return 0;
}