#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>

using ll = long long;
std::vector<int> tab;
int i ;

void solve(){
    for(int i = 1;(i*(i+1))/2 < ::i;i++){
        tab.push_back((i*(i+1))/2);
    }
    for(auto it : tab){
        int i_2 = ::i - it;
        if(std::binary_search(tab.begin(),tab.end(),i_2)){
            printf("YES\n");
            return;
        }
    }
    printf("NO\n");
    return;
}

int main(){
    scanf("%d",&i);
    solve();
    return 0;
}
