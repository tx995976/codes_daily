#include <cstdint>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>
#include <string>

const int mod = 998244353;
int64_t ans = 0;
int n,Q;
std::string s,per;

int main(){
    scanf(" %d",&Q);
    while(Q--){
        ans = 0;
        scanf(" %d",&n);
        std::cin>>s;
        per = s;
        int l = 0,r = n-1;
        while(l < r){
            per[r] = per[l];
            l++,r--;
        }
        int middle = (n-1)/2;
        for(int i = 0;i <= middle;i++){
            ans *= 26ll;
            ans %= mod;
            ans += (s[i] - 'A');
            ans %= mod;
        }
        ans++;
        ans %= mod;
        if(s < per){
            ans += (mod-1);
            ans %= mod;
        }
        printf("%d\n",ans);
    }
    return 0;
}
