#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>
#include<vector>

using ll = long long;
std::vector<int> luc_num;
int l,r;
ll ans = 0;

void table(int x){
    if(x > 1e9)
        return;
    luc_num.push_back(x);
    table(x*10+4);
    table(x*10+7);
}

int main(){
    scanf(" %d %d",&l,&r);
    table(0);
    std::sort(luc_num.begin(),luc_num.end());
    while(l < r){
        
    }

    return 0;
}