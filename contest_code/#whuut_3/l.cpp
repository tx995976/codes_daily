#include<iostream>
#include<cstdio>
#include<algorithm>
#include<deque>
#include<string>
#include<vector>

const int max_n=1e6+10;
int n,x,y;
int pre[max_n];
namespace alo{
    const int max_tree = max_n;
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
    scanf(" %d %d %d",&n,&x,&y);
    int tmp;
    for(int i = 1; i <= n; i++){
        scanf(" %d",&tmp);

    }

    return 0;
}