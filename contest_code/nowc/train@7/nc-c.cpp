#include<iostream>
#include<cstdio>
#include<algorithm>
#include<deque>
#include<string>
#include<vector>

const int max_n = 2e5+10;
int n,q,in,pre_ans = 0,a_len = 0;
char tem;

namespace alo{
     std::vector<int> tree(max_n<<2);

    void add(int len, int in,int l = 1,int r = n,int p = 1){
        if(l == r){
            tree[p] = (in + pre_ans) % q;
            return;
        }
        int mid = (l + r) >> 1;
        if(len <= mid)
            add(len,in,l,mid,p << 1);
        else
            add(len,in,mid + 1,r,p << 1 | 1);    
        tree[p] = std::max(tree[p << 1],tree[p << 1 | 1]);
        return;
    }

    int query(int l, int r, int p = 1, int tl = 1, int tr = n){
        if(l <= tl && r >= tr)
            return tree[p];
        int mid = (tl + tr) >> 1,res = 0;
        if(l <= mid)
            res = std::max(res,query(l, r, p << 1, tl, mid));
        if(r > mid)
            res = std::max(res,query(l, r, p << 1 | 1, mid + 1, tr));
        return res;
    }
}

int main(){
    scanf("%d %d",&n,&q);
    for(int i = 1;i <= n;i++){
        scanf(" %c %d",&tem,&in);
        if(tem == 'A'){
            alo::add(++a_len,in);
        }
        else{
            pre_ans = alo::query(a_len-in+1,a_len);
            printf("%d\n",pre_ans);
        }
    }
    return 0;
}