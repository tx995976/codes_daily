#include <iostream>
#include <algorithm>

const int max_n = 1e6+10;

long long T,limit,a_n,b_x,b_y,a_z,a_i;
long long sit;
struct card{
    int z,num;
};

card node[max_n];

bool cmp(const card &l_value,const card &r_value){
        return l_value.z < r_value.z;
}

long long solve(){
    long long y_max = b_y,y_min = b_y,sit_t = sit;
    std::sort(node+1,node+a_n+1,cmp);
    int i = 1;
    if(node[i].z == 0){
        sit_t += node[i].num;
        y_max -= node[i].num;
        i = 2;
    }
    for(i;i <= a_n;i++){
        if(sit_t+1 < node[i].z){
            long long overflow = node[i].z - sit_t - 1LL;
            if(node[i].num >= overflow){
                y_max -= overflow * ((sit_t+1LL) + (sit_t+overflow)) / 2LL + overflow;
                y_max -= (node[i].num - overflow) * (node[i].z+1LL);
            }
            else{
                y_max -= node[i].num * ((sit_t+1LL) + (sit_t+node[i].num)) / 2LL + node[i].num;
            }
        }
        else
            y_max -= node[i].num * (node[i].z+1LL);
        sit_t += node[i].num;
    }
    sit_t = sit;
    for(int i = 1;i <= a_n;i++){
        if(node[i].z == 0) 
            continue;
        y_min -= node[i].num;
        sit_t = std::max(0LL,sit_t - (node[i].z-1LL)*node[i].num);
    }
    y_min -= (limit - sit_t);
    return y_min-y_max+1LL;
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
        else
            printf("%lld \n",solve());
    }
    return 0;
}
