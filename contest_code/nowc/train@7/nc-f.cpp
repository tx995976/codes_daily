#include<iostream>
#include<cstdio>
#include<algorithm>
#include<deque>
#include<string>
#include<vector>

const int max_n = 1e6+10;
using ll = long long;
int N,Q;

namespace alo{
    std::vector<ll> tree;
    std::vector<ll> arr,mark;

    void push_down(int p,int tl,int tr){
        mark [p << 1] += mark[p];
        mark [p << 1 | 1] += mark[p];
        ll mid = (tl + tr) >> 1;
        //ll
        tree[p << 1] +=  1ll * mark[p] * (mid - tl + 1);
        //ll
        tree[p << 1 | 1] += 1ll * mark[p] * (tr - mid);
        mark[p] = 0;
        return; 
    }

    void build(int l, int r ,int p){
        if(l == r){
            tree[p] = arr[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(l, mid, p << 1);
        build(mid + 1, r,(p << 1) | 1);
        tree[p] = tree[p << 1] + tree[(p << 1) | 1];
        return;
    }

    void update(int l, int r, int d, int p = 1, int tl = 1,int tr = N){
        if(l > tr || r < tl) 
            return;
        if(tl >= l && tr <= r){
            //ll
            tree[p] += 1ll * d * (tr - tl + 1);
            mark[p] += d;   
            return;
        }
        if(mark[p])
            push_down(p,tl,tr);
        int mid = (tl + tr) >> 1;
        if(mid >= l)
            update(l, r, d, p << 1, tl, mid);
        if(mid < r)
            update(l, r, d, (p << 1) | 1, mid + 1, tr);
        tree[p] = tree[p << 1] + tree[(p << 1) | 1];
        return;
    }

    ll query(int l, int r, int p = 1, int tl = 1, int tr = N){
        if(l > tr || r < tl)
            return 0;
        if(tl >= l && tr <= r)
            return tree[p];
        if(mark[p])
            push_down(p,tl,tr);
        int mid = (tl + tr) >> 1;
        ll ret = 0;
        if(mid >= l)
            ret += query(l, r, p << 1, tl, mid);
        if(mid < r)
            ret += query(l, r, (p << 1) | 1, mid + 1, tr);
        return ret;
    }
}


int main(){
    scanf(" %d %d", &N, &Q);
    alo::arr.resize(N+1);
    alo::mark.resize(N<<2);
    alo::tree.resize(N<<2);

    for(int i = 1;i <= N;i++)
        scanf(" %lld", &alo::arr[i]);

    alo::build(1, N, 1);
    int prc;
    int arg1,arg2,arg3;
    while(Q--){
        scanf("%d", &prc);
        if(prc == 2){
            scanf("%d%d",&arg1,&arg2);
            printf("%lld\n", alo::query(arg1, arg2));
        }
        else{
            scanf(" %d %d %d",&arg1,&arg2,&arg3);
            alo::update(arg1, arg2, arg3);
        }
    }
    return 0;
}