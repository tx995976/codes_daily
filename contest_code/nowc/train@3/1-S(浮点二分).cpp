#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>

const int max_F = 1e5+10;
const double pi = acos(-1);

double R_pow[max_F];
int N,F,temp;

bool judge(double R){
    int cnt = 0;
    for(int i = 1;i <= N;i++){
        cnt += (int)(R_pow[i] / R);
    }
    return cnt >= F;
}

void solve(){
    double ans_l = 0 ,ans_r = 4e8,mid;
    while(ans_r - ans_l > 1e-5){  //精度控制
         mid = (ans_l + ans_r)/2;
        if(judge(mid))
            ans_l = mid;
        else 
            ans_r = mid;
    }
    printf("%.3f\n",mid);
}

int main(){
    scanf("%d %d",&N,&F);
    F += 1;
    for(int i = 1;i <= N;i++){
        scanf(" %lf",&R_pow[i]);
        R_pow[i] = R_pow[i] * R_pow[i] * pi;
    }
    solve();
    return 0;
}