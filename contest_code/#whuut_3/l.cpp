#include<iostream>
#include<cstdio>
#include<algorithm>
#include<deque>
#include<string>
#include<vector>

const int max_n=1e6+10;
int n,x,y;
int pre[max_n],a[max_n];
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
	pre[0] = 1e5+10;
    for(int i = 1; i <= n; i++){
        scanf(" %d",&tmp);
		if(tmp > x)
			a[i] = 1;
		else if(tmp < y)
			a[i] = -1;
		else
			a[i] = 0;
		pre[i] = a[i] + pre[i - 1];
    }

	int ans = 0;
	for(int i = 1; i <= n; i++){
		if(pre[i] >= pre[0]){
			ans += alo::query(pre[i]) + 1;
		}
		alo::add(pre[i], 1);
	}

	int emp = 0;
	for(int i = 1; i <= n; i++){
		if(a[i] == 0)
			emp++;
		else{
			if(emp > 0)
				ans -= (tmp + 1) * tmp / 2;
			emp = 0;
		}
	}
	printf("%d\n",ans);
    return 0;
}
