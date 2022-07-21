#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>

const int max_n = 3e3;
int ans = 0;

struct pairs{
    int a,b;
};

pairs cows[max_n],spf[max_n];                                                                                                                                                                                                                                                                                                                                                                  

bool sort_cows(const pairs &l ,const pairs &r){
    return l.b < r.b;
}

bool sort_spf(const pairs &l ,const pairs &r){
    return l.a < r.a;
}
int main(){
    int c,l;
    scanf(" %d %d",&c,&l);
    for(int i = 1;i <= c;i++){
        scanf(" %d %d",&cows[i].a,&cows[i].b);
    }
    for(int i = 1;i <= l;i++){
        scanf(" %d %d",&spf[i].a,&spf[i].b);
    }
    std::sort(cows+1,cows+1+c,sort_cows);
    std::sort(spf+1,spf+1+l,sort_spf);
    for(int num_c = 1;num_c <= c;num_c++){
        for(int i = 1;i <= l;i++){
            if(spf[i].b > 0 && spf[i].a <= cows[num_c].b && spf[i].a >= cows[num_c].a){
                ans++;
                spf[i].b--;
                break;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}