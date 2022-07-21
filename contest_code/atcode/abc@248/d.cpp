#include<iostream>
#include<cstdio>
#include<algorithm>
#include<deque>
#include<string>
#include<vector>

const int max_n = 2e5+10;
std::vector qu(max_n,std::vector<int>());
int N,Q,L,R,X,ans;
bool flag = 0;

int main(){
    int a;
    scanf(" %d",&N);
    for(int i = 1;i <= N;i++){
        scanf(" %d",&a);
        qu[a].push_back(i);
    }
    scanf(" %d",&Q);
    while(Q--){
        scanf(" %d %d %d",&L,&R,&X);
        ans = 0;
        if(!qu[X].empty()){
            int l = std::lower_bound(qu[X].begin(),qu[X].end(),L) - qu[X].begin();
            int r = std::upper_bound(qu[X].begin(),qu[X].end(),R) - qu[X].begin();
            ans = r-l;
        }
        printf("%d\n",ans);
    }
    return 0;
}