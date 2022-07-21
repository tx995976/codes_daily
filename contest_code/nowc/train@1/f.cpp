#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>

using ll = long long;

std::vector<ll> hero;
ll num_hero,num_boss,temp,b_atk,b_def,sum_str = 0ll;

void solve(){
    ll ans_c1 = INT64_MAX, ans_c2;
    auto it = std::lower_bound(hero.begin(),hero.end(),b_def);
    if(it != hero.end()){
        ans_c1 = std::max(0ll,b_atk-(sum_str - *it));
    }
    if(it != hero.begin())
        it--;
    ans_c2 = std::max(0ll,b_def - *it)+std::max(0ll,b_atk-(sum_str - *it));
    printf("%lld\n",std::min(ans_c1,ans_c2));
}

int main(){
    scanf("%d",&num_hero);
    for(int i = 0;i < num_hero;i++){
        scanf("%lld",&temp);
        hero.push_back(temp);
        sum_str += temp;
    }
    std::sort(hero.begin(),hero.end());
    scanf("%lld",&num_boss);
    while(num_boss--){
        scanf("%lld %lld",&b_def,&b_atk);
        solve();    
    }
    return 0;
}