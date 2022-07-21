#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>
#include<vector>
#include<ext/rope>

const int max_n = 1e5 + 5;
int N,Q;

namespace alo{
    std::vector<int> arr;
    std::vector<std::pair<int,int>> tree;

    void build(int l, int r ,int p = 1){
        if(l == r){
            tree[p].first = arr[l];
            tree[p].second = arr[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(l, mid, p << 1);
        build(mid + 1, r,(p << 1) | 1);
        tree[p].first = std::max(tree[p << 1].first,tree[p << 1 | 1].first);
        tree[p].second = std::min(tree[p << 1].second,tree[p << 1 | 1].second);
        return;
    }

    int query_max(int l, int r, int p = 1, int tl = 1, int tr = N){
        if(l > tr || r < tl) 
            return 0;
        if(l <= tl && r >= tr) 
            return tree[p].first;
        int mid = (tl + tr) >> 1;
        return std::max(query_max(l, r, p << 1, tl, mid),query_max(l, r, p << 1 | 1, mid + 1, tr));
    }

    int query_min(int l, int r, int p = 1, int tl = 1, int tr = N){
        if(l > tr || r < tl) 
            return INT32_MAX;
        if(l <= tl && r >= tr) 
            return tree[p].second;
        int mid = (tl + tr) >> 1;
        return std::min(query_min(l, r, p << 1, tl, mid),query_min(l, r, p << 1 | 1, mid + 1, tr));
    }
}

int main(){   
    scanf("%d %d",&N,&Q);
    alo::arr.resize(N+1);
    alo::tree.resize(N<<2);
    for(int i = 1; i <= N; i++)
        scanf("%d",&alo::arr[i]);
    alo::build(1,N);
    int ql,qr;
    while(Q--){
        scanf(" %d %d",&ql,&qr);
        printf("%d\n",alo::query_max(ql,qr) - alo::query_min(ql,qr));
    }
    return 0;
}
