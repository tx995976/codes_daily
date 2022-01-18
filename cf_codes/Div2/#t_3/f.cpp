#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<set>

const int max_n = 5e4+10;
int father[max_n],ans,k = 1;


int find(int x){
    if(x != father[x])
        father[x] = find(father[x]);
    return father[x];
}
void unionset(int a,int b){
    a = find(a);
    b = find(b);
    if(a != b)
        ans--;
    father[a] = b;
}

int main(){
    int m,n,p1,p2;
    while(scanf(" %d %d",&m,&n) && m && n){
        ans = m;
        for(int i = 1;i <= m;i++){
            father[i] = i;
        }
        
        for(int i = 1;i <= n;i++){
            scanf(" %d %d",&p1,&p2);
            unionset(p1,p2);
        }
        printf("Case %d: %d\n",k++,ans);
    }    

    return 0;
}