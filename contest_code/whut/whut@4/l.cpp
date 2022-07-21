#include<iostream>
#include<cstdio>
#include<algorithm>
#include<deque>
#include<string>
#include<vector>

using ll = long long;
const int max_n = 1e6+10;
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
    ll query(int x){
        ll res = 0;
        while(x > 0){
            res += tree[x];
            x -= lowbit(x);
        }
        return res;
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

	ll ans = 0;
	for(int i = 1; i <= n; i++){
		if(pre[i] >= pre[0])
			ans += 1;
		ans += alo::query(pre[i]);
		alo::add(pre[i], 1);
	}

	int emp = 0;
	for(int i = 1; i <= n; i++){
		if(a[i] == 0)
			emp++;
		else{
			ans -= 1ll * (emp + 1) * emp / 2;
			emp = 0;
		}
	}
    ans -= 1ll * (emp+1) * emp / 2;

	printf("%lld\n",ans);
    return 0;
}
