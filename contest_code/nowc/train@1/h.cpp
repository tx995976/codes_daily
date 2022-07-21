#include<iostream>
#include<algorithm>
#include<cstdio>
#include <vector>

using itor = std::vector<int>::iterator;

const int max_n = 4e3+10;
int ans,n,a[max_n],b[max_n],c[max_n],d[max_n];
std::vector<int> ab,cd;

void solve(){
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n;j++){
            ab.push_back(a[i]+b[j]);
            cd.push_back(c[i]+d[j]);
        }
    //std::sort(ab.begin(),ab.end());
    std::sort(cd.begin(),cd.end());

    itor ab_it = ab.begin();
    while(ab_it != ab.end()){
        int val = -*ab_it;
        itor i = std::lower_bound(cd.begin(),cd.end(),val);
        while(i != cd.end() && *i == val){
            i++;
            ans++;
        }
        ab_it++;
    }
    printf("%d\n",ans);
}

int main(){ 
    scanf("%d",&n);
    for(int i = 1;i <= n;i++){
        scanf("%d %d %d %d",&a[i],&b[i],&c[i],&d[i]);
    }
    solve();
    return 0;
}