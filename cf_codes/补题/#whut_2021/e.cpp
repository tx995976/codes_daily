#include <iostream>
#include <algorithm>

const int max_n = 1e6+10;
int T,limit,a_n,b_x,b_y,a_z,a_i;
int sit,z[max_n],z_i[max_n];

int solve(){
    int y_max = b_y,y_min = b_y;
    std::sort(z+1,z+a_n+1);
    for(int i = 1,j = a_n;i <= a_n;i++,j--){
        if(z[i] <= sit+1)
            y_max -= (z[i]+1)*z_i[z[i]];
        else if(z[i] <= sit+z_i[z[i]]){
            y_max -= (z[i]+1)*z_i[z[i]]-((z[i]-sit+1)*(z[i]-sit+2)/2);
        }
        else{
            y_max -= 
        }
        sit -= z_i[z[i]];
    }
}

int main(){
    scanf("%d",&T);
    while(T-- > 0){
        scanf("%d %d %d %d",&limit,&a_n,&b_x,&b_y);
        sit = limit;
        for(int i = 1;i <= a_n;i++){
            scanf("%d %d",&a_z,&a_i);
            z[i] = a_z;
            z_i[a_z] = a_i;
            sit -= a_i;
        }
        printf("%d \n",solve());
    }
    return 0;
}
