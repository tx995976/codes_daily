#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>
#include<vector>
#include<set>

const int max_n = 2e5+10;

struct bc{
    int wid,length,type;
    bool operator < (const bc &r){
        return wid != r.wid ? (wid > r.wid) : (type < r.type);
    }
};

std::vector<bc> sen;
std::multiset<int> check;
int N,M;
bool flag = 0;

int main(){
    scanf(" %d %d",&N,&M);
    sen.resize(N+M);

    for(int i = 0;i < N;i++){
        scanf(" %d",&sen[i].wid);
        sen[i].type = 1;
    }
    for(int i = 0;i < N;i++)
        scanf(" %d",&sen[i].length);

    for(int i = N;i < N+M;i++){
        scanf(" %d",&sen[i].wid);
        sen[i].type = 0;
    }
    for(int i = N;i < N+M;i++)
        scanf(" %d",&sen[i].length);
        
    std::sort(sen.begin(),sen.end());    
    for(auto it : sen){
        if(it.type){
            auto l = check.lower_bound(it.length);
            if(l != check.end()){
                check.erase(l);
            }
            else{
                flag = 1;
                break;
            }
        }
        else
            check.insert(it.length);
    }

    printf("%s\n",flag ? "No" : "Yes");
    return 0;
}