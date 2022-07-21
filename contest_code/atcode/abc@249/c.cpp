#include<iostream>
#include<cstdio>
#include<algorithm>
#include<deque>
#include<string>

std::string bets[20];
int N,K;
int cnt_str[20][30];
int all_cnt[30];
int ans=0;

void fresh(){
    int cnt=0;
    for(int i = 0;i < 26;i++)
        if(all_cnt[i] == K)
            cnt++;
    ans = std::max(ans,cnt);
}

void dfs(int len,int cnt[]){
    if(len > N)
        return;
    fresh();
    dfs(len+1,cnt);
    for(int i = 0;i < 26;i++){
        all_cnt[i] += cnt_str[len][i];
    }
    fresh();
    dfs(len+1,cnt);
    for(int i = 0;i < 26;i++){
        all_cnt[i] -= cnt_str[len][i];
    }
    return;
}

int main(){
    scanf(" %d %d",&N,&K);
    for(int i = 1;i <= N;i++){
        std::cin>>bets[i];
        for(auto it : bets[i])
            cnt_str[i][it-'a'] += 1;
    }
    dfs(1,all_cnt);
    printf("%d\n",ans);
    return 0;
}