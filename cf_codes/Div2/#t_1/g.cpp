#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>

//<min_att,increase_at>
using pair = std::pair<int,int>; 
std::vector<pair> armor;

const int max_k = 1e5+10;
int t,num_k,temp,cave;

bool cmp(const pair &l,const pair &r){
    return l.first < r.first ? l.first < r.first : l.second > r.second;
}

void solve(){
    int plus_at = 0,min_at = 0;
    std::sort(armor.begin(),armor.end());
    for(auto it : armor){
        min_at = std::max(min_at,it.first - plus_at);
        plus_at += it.second;
    }
    printf("%d\n",min_at+1);
}

int main(){
    scanf("%d",&t);
    while(t--){
        armor.clear();
        scanf("%d",&cave);
        while(cave--){
            scanf("%d",&num_k);
            int min_at = 0;
            for(int i = 1;i <= num_k;i++){
                scanf("%d",&temp);
                min_at = std::max(min_at,temp-(i-1));
            }
            armor.push_back(pair(min_at,num_k));
        }
        solve();
    }
    return 0;
}