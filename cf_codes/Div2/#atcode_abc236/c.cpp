#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>
#include<unordered_map>

const int max_n = 1e5+10;
std::unordered_map<std::string,int> id_st;
std::string in;

bool stop[max_n];

int main(){
    int n,m;
    scanf(" %d %d",&n,&m);
    for(int i = 1;i <= n;i++){
        std::cin>>in;
        id_st[in] = i;
    }
    for(int i = 1;i <= m;i++){
        std::cin>>in;
        stop[id_st[in]] = 1;
    }
    for(int i = 1;i <= n;i++)
        printf("%s\n",stop[i] ? "Yes" : "No");
    return 0;
}