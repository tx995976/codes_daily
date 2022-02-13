#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>

int n,flag = 1;
double ans = INT32_MIN;
int len[10] = {0};

void get_ans(double a,double b,double c){
    double p = (a+b+c)/2;
    double S = sqrt(p*(p-a)*(p-b)*(p-c));
    ans = std::max(ans,S);
}

void dfs(int a,int b,int c,int i){
    if(a+b > c && a+c > b && b+c > a){
        get_ans(a,b,c);
    }
    if(i > n+1)
        return;
    dfs(a+len[i],b,c,i+1);
    dfs(a,b+len[i],c,i+1);
    dfs(a,b,c+len[i],i+1);
    dfs(a,b,c,i+1);
}

int main(){
    int temp;
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)
        scanf("%d",&len[i]);
    dfs(0,0,0,1);
    if(ans <= 0)
        printf("-1\n");
    else
        printf("%.1f\n",ans);
    return 0;
}