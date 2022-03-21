#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>
#include<vector>

using ll = long long;
const int max_n = 2e3+10;
const int mod_ = 998244353;

std::vector<int>edge[max_n];
int N,M,K,S,T,X;
int d1,d2;
ll ans = 0;



int main(){
    scanf(" %d %d %d %d %d %d",&N,&M,&K,&S,&T,&X);
    for(int i = 1;i <= M;i++){
        scanf(" %d %d",&d1,&d2);
        edge[d1].push_back(d2);
        edge[d2].push_back(d1);
    }
    
    return 0;
}