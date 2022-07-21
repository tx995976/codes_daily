#include<iostream>
#include<algorithm>
#include<cstdio>
#include <cstring>
#include <utility>

const int max_m = 1e2+10;
char DNA[max_m][max_m],t_char[max_m],t_dna[max_m];
int n,m,ans = 0,i = 0;

using i_p = std::pair<int,int>;
i_p res[max_m];
bool cmp(const i_p &l,const i_p &r){
    return l.first == r.first ? l.second < r.second : l.first < r.first;
}

void sort(int l,int r){
    if(r - l <= 1)
        return;
    int mid = (l+r) >> 1;
    sort(l,mid);
    sort(mid,r);

    int p_char = l ,p_l = l ,p_r = mid;
    while(p_char < r){
        if(p_l >= mid || (p_r < r && t_dna[p_l] > t_dna[p_r] )){
            t_char[p_char++] = t_dna[p_r++];
            ans += mid - p_l;
        }
        else
            t_char[p_char++] = t_dna[p_l++];
    }
    for(int i = l;i < r;i++)
        t_dna[i] = t_char[i];
}

void solve(){
    for(int i = 1;i <= ::i;i++){
        ans = 0;
        memset(t_char,0,sizeof(t_char));
        memcpy(t_dna,DNA[i],sizeof(t_dna));
        sort(0,n);
        res[i] = i_p(ans,i);
    }
    std::sort(res+1,res+i+1,cmp);
    for(int i =1;i <= ::i;i++){
        printf("%s\n",DNA[res[i].second]);
    }
}

int main(){
    scanf("%d %d",&n,&m);
    while(m--){
        scanf("%s",DNA[++i]);
    }
    solve();
    return 0;
}
