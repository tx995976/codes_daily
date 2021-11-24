#include <iostream>
#include <algorithm>

const int max_n = 1e6+10;

long long T,limit,a_n,b_x,b_y,a_z,a_i;
int sit;

struct card{
    int z,num;
};

card node[max_n];

bool cmp(const card &l_value,const card &r_value){
        return l_value.z < r_value.z;
}

int solve(){
    long long y_max = b_y,y_min = b_y,sit_t = sit;
    std::sort(node+1,node+a_n+1,cmp);
    for(int i = 1;i <= a_n;i++){
        if(node[i].z <= sit_t+1)
            y_max -= (node[i].z+1)*node[i].num;
        else if(node[i].z <= sit_t+node[i].num+1){
            y_max -= (node[i].z+1)*node[i].num-((node[i].z-sit_t-1)*(node[i].z-sit_t)/2);
        }
        else{
            y_max -= (node[i].z+1)*node[i].num-(((node[i].z-sit_t-1)+(node[i].z-(sit_t+node[i].num)))*(node[i].num)/2);
        }
        sit_t += node[i].num;
    }
    sit_t = sit;
    for(int i = a_n;i >= 1;i--){
        if(node[i].z == 0) 
            continue;
        y_min -= node[i].num;
        sit_t = std::max((long long)0,sit_t - (node[i].z-1)*node[i].num);
    }
    y_min -= (limit - sit_t);
    return y_min-y_max+1;
}

int main(){
    scanf("%d",&T);
    while(T-- > 0){
        scanf("%lld %lld %lld %lld",&limit,&a_n,&b_x,&b_y);
        sit = limit;
        for(int i = 1;i <= a_n;i++){
            scanf("%lld %lld",&a_z,&a_i);
            node[i].z = a_z;
            node[i].num = a_i;
            sit -= a_i;
        }
        if(b_x == 0)
            printf("1 \n");
        printf("%d \n",solve());

    }
    return 0;
}
