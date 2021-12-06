#include<iostream>
#include<algorithm>
#include<cstdio>


const int max_n = 4e3+10;
const int max_n2 = max_n*max_n;
int ans,n,a[max_n],b[max_n],c[max_n],d[max_n];
int ab[max_n2],cd[max_n2];


void solve(){
    std::string
    int it = 1;
    int end = (n*n)+1;
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n;j++){
           ab[it] = a[i]+b[j];
           cd[it] = c[i]+d[j];
           it++;
        }
    //std::sort(ab.begin(),ab.end());
    std::sort(cd+1,cd+end);
    int ab_it = 1;
    while(ab_it != end){
        int val = -ab[ab_it];
        int i = std::lower_bound(cd+1,cd+end,val) - cd;
        while(i != end && cd[i] == val){
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