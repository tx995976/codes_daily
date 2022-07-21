#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>

const int max_n = 2e3+10;
int father[max_n],ans,k = 1;
int ret_fa[max_n];

int find(int x){
    if(x != father[x]){
        int fa_x = find(father[x]);
        ret_fa[x] = (ret_fa[x]+ret_fa[father[x]])%2;
        father[x] = fa_x;
    }
    return father[x];
}
bool unionset(int a,int b){
    int fa,fb;
    fa = find(a);
    fb = find(b);
    if(fa == fb){
        if(ret_fa[a] == ret_fa[b])
            return 1;
    }
    else{
        father[fa] = fb;
        ret_fa[fa] = (ret_fa[b] - ret_fa[a] +1)%2;
    }
    return 0;
}

int main(){
    int T,n,m,a,b;
    bool flag;
    scanf(" %d",&T);
    while(T-- > 0){
        scanf(" %d %d",&n,&m);
        flag = 0;
        for(int i = 1;i <= n;i++){
            father[i] = i;
            ret_fa[i] = 0;
        }

        for(int i = 1;i <= m;i++){
            scanf(" %d %d",&a,&b);
            if(unionset(a,b))
                flag = 1;
        }

        printf("Scenario #%d:\n",k++);
        if(flag)
            printf("Suspicious bugs found!\n\n");
        else
            printf("No suspicious bugs found!\n\n");
    }   
    return 0;
}