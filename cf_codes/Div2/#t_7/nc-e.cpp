#include<iostream>
#include<cstdio>
#include<algorithm>
#include<deque>
#include<string>
#include<vector>

using ll = long long;
int N,Q;

namespace alo{
     std::vector<int> tree,arr,mark;

    void push_down(int p,int len){
        mark [p << 1] += mark[p];
        mark [p << 1 | 1] += mark[p];
        tree[p << 1] += mark[p] * (len - (len >> 1));
        tree[p << 1 | 1] += mark[p] * (len >> 1);
        mark[p] = 0;
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
        if(tl >= l && tr <= r){
            tree[p] += d * (tr - tl + 1);
            mark[p] += d;
            return;
        }
        //
        push_down(p,tr - tl + 1);
        int mid = (tl + tr) >> 1;
        if(mid >= l)
            update(l, r, d, p << 1, tl, mid);
        if(mid < r)
            update(l, r, d, (p << 1) | 1, mid + 1, tr);
        tree[p] = tree[p << 1] + tree[(p << 1) | 1];
        return;
    }

    int query(int l, int r, int p = 1, int tl = 1, int tr = N){
        if(tl >= l && tr <= r)
            return tree[p];
        push_down(p,tr - tl + 1);
        int mid = (tl + tr) >> 1;
        int ret = 0;
        if(mid >= l)
            ret += query(l, r, p << 1, tl, mid);
        if(mid < r)
            ret += query(l, r, (p << 1) | 1, mid + 1, tr);
        return ret;
    }
}


int main(){
    scanf(" %d %d", &N, &Q);
    alo::arr.resize(N + 1);
    alo::mark.resize(N<<2);
    alo::tree.resize(N<<2);

    for(int i = 1;i <= N;i++)
        scanf(" %d", &alo::arr[i]);
    alo::build(1, N, 1);

    int prc;
    int arg1,arg2,arg3;
    while(Q--){
        scanf(" %d", &prc);
        if(prc == 2){
            scanf(" %d %d",&arg1,&arg2);
            printf("%d\n", alo::query(arg1, arg2));
        }
        else{
            scanf(" %d %d %d",&arg1,&arg2,&arg3);
            alo::update(arg1, arg2, arg3);
        }
    }
    return 0;
}