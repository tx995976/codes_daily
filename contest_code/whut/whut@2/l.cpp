#include<iostream>
#include<algorithm>
#include<cstdio>
#include<unordered_map>
#include<queue>
#include<vector>

int _mod = 1919810;
std::unordered_map<std::string,int> hash;
std::vector<int> pos[11];

long long dp[11];
int n,m;
int hash_id = 1;

int main(){
    std::string word;
    scanf(" %d %d",&n,&m);
    for(int i = 1;i <= n;i++){
        std::cin>>word;
        if(hash.count(word) == 0){
            hash[word] = hash_id++;
            pos[hash[word]].push_back(i);
        }
        else{
            pos[hash[word]].push_back(i);
        }
    }

    dp[0] = 1ll;
    for(int i = 1; i <= m;i++){
        std::cin>>word;
        if(hash.count(word) == 0)
            continue;
        int id = hash[word];
        for(int i = pos[id].size()-1;i >= 0;i--){
           dp[pos[id][i]] = (dp[pos[id][i]] + dp[pos[id][i]-1])%_mod;
        }
    }
    printf("%lld\n",dp[n]);
    return 0;
}