#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
#include<unordered_map>

using ll = long long;
const int max_n = 2e5+10;
const int mod_1 = 998244353;
const int mod_2 = 1e9 + 7;

std::unordered_map <int,int> mp;

int N,Q,xi,yi;
ll ai,bi;
ll hash_a1[max_n],hash_b1[max_n];
ll hash_a2[max_n],hash_b2[max_n];


int main(){
    scanf(" %d",&N);
    for(int i = 1;i <= N;i++){
	    scanf(" %lld",&ai);
        mp[ai]++;
        hash_a1[i] = hash_a1[i-1];
        hash_a2[i] = hash_a2[i-1];
        if(mp[ai] == 1){
            hash_a1[i] = (hash_a1[i]+ai*ai%mod_1*ai%mod_1) % mod_1;
            hash_a2[i] = (hash_a2[i]+ai*ai%mod_2*ai%mod_2) % mod_2;
        }
    }	
    mp.clear();
    for(int i = 1;i <= N;i++){
	    scanf(" %lld",&bi); 
        mp[bi]++;
        hash_b1[i] = hash_b1[i-1];
        hash_b2[i] = hash_b2[i-1];
        if(mp[bi] == 1){
            hash_b1[i] = (hash_b1[i]+bi*bi%mod_1*bi%mod_1) % mod_1;
            hash_b2[i] = (hash_b2[i]+bi*bi%mod_2*bi%mod_2) % mod_2;
        }
    }

    scanf(" %d",&Q);
    for(int i = 1;i <= Q;i++){
	    scanf(" %d %d",&xi,&yi);
	    if(hash_a1[xi] == hash_b1[yi] && hash_a2[xi] == hash_b2[yi])
	        printf("Yes\n");
	    else
	        printf("No\n");
    }
    return 0;
}
