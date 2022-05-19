#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>

using ll = long long;
const int max_n= 1e5+10;
const int M = 5e5+10;
int n,q,k;
int min_atom;
double per_eg = 1e9+1;

ll eg[110];
std::vector<ll> min_eg(M,INT64_MAX);

int main(){
    scanf(" %d %d",&n,&q);
    for(int i=1;i<=n;i++){ 
	    scanf(" %lld",&eg[i]);
		min_eg[i] = eg[i];
        double per = 1.0 * eg[i] / i;
        if(per < per_eg){
            per_eg = per;
            min_atom = i;
        }
    }
    int lim = 5e5;
	for(int i=n+1;i<= lim;i++)
        for(int j = 1;j <= n;j++)
           min_eg[i] = std::min(min_eg[i],min_eg[i-j]+eg[j]);
	
    for(int i=1;i<=q;i++){
	    scanf(" %d",&k);
	    ll ans = 0ll;
        if(k <= lim)
	        ans += min_eg[k];
	    else{
            int over = k - lim;
			int num_m = (over + min_atom - 1)/min_atom;
			ans += 1ll * num_m * eg[min_atom];
			ans += min_eg[k-(min_atom*num_m)];
	    }
	    printf("%lld\n",ans);
    }
    return 0;
}


