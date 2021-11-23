#include <iostream>
#include <algorithm>

const int max_n = 1e6+10;
int T,limit,a_n,b_x,b_y,a_z,a_i;
int sit,z[max_n],z_i[max_n];

int solve(){
    int ans_max,ans_min,y = b_y;
    std::sort(z+1,z+a_n+1);
    for(int i = 1;i <= a_n;i++){
        

    }
}

int main(){
    scanf("%d",&T);
    while(T-- > 0){
        scanf("%d %d %d %d",&limit,&a_n,&b_x,&b_y);
        sit = limit;
        scanf("%d %d",&a_z,&a_i);
        for(int i = 1;i <= a_n;i++){
            z[i] = a_z;
            z_i[a_z] = a_i;
            sit -= a_i;
        }
        printf("%d \n",solve());
    }
    return 0;
}
