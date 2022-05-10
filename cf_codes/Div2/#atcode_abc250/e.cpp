#include<iostream>
#include<cstdio>
#include<algorithm>
#include<deque>
#include<string>
#include<vector>
#include<set>

using ll = long long;
const int max_n = 2e5 + 5;
std::set<int> a,b;
int N,Q,ai,bi,xi,yi;
ll hash_a[max_n],hash_b[max_n];

ll gethash(std::set<int>& s) {
    ll ret = 0;
    for(auto i:s) 
	ret ^= i * 233;
    return ret;
}

int main(){
    scanf(" %d",&N);
    for(int i = 1;i <= N;i++){
	scanf(" %d",&ai);
	a.insert(ai);
	hash_a[i] = gethash(a);
    }	
    for(int i = 1;i <= N;i++){
	scanf(" %d",&bi);
	b.insert(bi);
	hash_b[i] = gethash(b);
    }
    scanf(" %d",&Q);
    for(int i = 1;i <= Q;i++){
	scanf(" %d %d",&xi,&yi);
	if(hash_a[xi] == hash_b[yi]){
	    printf("Yes\n");
	else
	    printf("No\n");
    }
    return 0;
}
