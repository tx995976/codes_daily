#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>

const int max_n = 1e5 + 5;

namespace alo{
    const int max_tree = 1e5 + 5;
    int tree[max_tree];

    int lowbit(int x){
        return x & (-x);
    }
    void add(int x, int val){
        while(x <= max_tree){
            tree[x] += val;
            x += lowbit(x);
        }
    }
    int query(int x){
        int res = 0;
        while(x > 0){
            res += tree[x];
            x -= lowbit(x);
        }
        return res;
    }
    int query_range(int l, int r){
        return query(r) - query(l - 1);
    }
}

int main(){   



    return 0;
}
