#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>

using ll = long long;
const int max_n= 1e5+10;
int n,q,k;


std::vector<int> eg(max_n);
int min_eg = INT32_MAX,min_atom;
double per_eg = 1e10;

ll ans = 0ll;

int main(){
    scanf(" %d %d",&n,&q);
    for(int i=1;i<=n;i++){ 
	    scanf(" %d",&eg[i]);
        if(eg[i]< min_eg) 
            min_eg = eg[i];
        if((double)eg[i]/i < per_eg){
            per_eg = (double)eg[i]/i;
            min_atom = i;
        }
    }

    eg.resize((min_atom+1)*n);
    
    


    for(int i=1;i<=q;i++){
	    scanf(" %d",&k);
	    ans = 0ll;
        if(k <= n)
	        ans += eg[k];
	    else{
            
	    }
	    
	    printf("%lld\n",ans);
    }
    return 0;
}


