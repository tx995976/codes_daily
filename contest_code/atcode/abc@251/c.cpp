#include<iostream>
#include<cstdio>
#include<algorithm>
#include<deque>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>

std::unordered_set<std::string> index;
int N,T;
std::string in;
int ans = 0,s_max = 0;

int main(){
    scanf(" %d",&N);
    for(int i=1;i <= N;i++){
        std::cin>>in>>T;
        if(index.count(in))
            continue;
        index.insert(in);
        if(T > s_max){
            s_max = T;
            ans = i;
        }
    }
    printf("%d\n",ans);
    return 0;
}