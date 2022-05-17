#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using ll = long long;
const int max_n= 1e5+10;
int n,q,k;

struct node{
   int atom;
   double cost;
   bool operator < (const node &a) const{
       return cost<a.cost;
   }
}
arr[max_n];
int eg[max_n];

ll ans = 0ll;

int main(){
    scanf(" %d %d",&n,&q);
    for(int i=1;i<=n;i++){ 
	scanf(" %d",&eg[i]);
	arr[i].atom = i;
	arr[i].cost = eg[i] / (double)i;
    }
    std::sort(arr+1,arr+n+1);
    for(int i=1;i<=q;i++){
	scanf(" %d",&k);
	ans = 0ll;
	while(k > 0){
            if(k <= n){
		ans += eg[k];
		k = 0;
	    }
	    else{
                int over = k - n;
		int add = over % arr[1].atom == 0 ? 0 : 1;
		ans += eg[arr[1].atom] * (over / arr[1].atom + add);
                k -= arr[1].atom * (over / arr[1].atom + add);
	    }
	}
	printf("%lld\n",ans);
    }
    return 0;
}


