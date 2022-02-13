#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<vector>
#include<map>


const int max_n = 2e5+10;

struct ans{
    int id,almost_like,like;
    bool operator<(const ans &r)const{
        if(almost_like != r.almost_like)
            return almost_like < r.almost_like;
        else
            return like < r.like; 
    }
};

ans movies[max_n];
std::map<int,int> lan_num;



int main(){
    int n,m,temp;
    scanf(" %d",&n);
    for(int i = 1;i <= n;i++){
        scanf(" %d",&temp);
        lan_num[temp] += 1;
    }
    scanf(" %d",&m);
    for(int i = 1;i <= m;i++){
        scanf(" %d",&temp);
        movies[i].id = i;
        movies[i].almost_like += lan_num[temp];
    }
    for(int i = 1;i <= m;i++){
        scanf(" %d",&temp);
        movies[i].like += lan_num[temp];
    }
    std::sort(movies+1,movies+m+1);
    printf("%d\n",movies[m].id);
    return 0;
}
//tx995976