#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>

const int max_n = 1e5+10;
const double eps = 1e-6;

int n,array[max_n];
double dp_e[max_n];

bool check_mid(int it){
    int sum_ = 0,flag = 1;
    for(int i = 1;i <= n;i++){
        if(flag && array[i] < it){
            flag = 0;
            continue;
        }
        else{
            flag = 1;
            sum_ += (array[i] >= it ? 1 : -1);
        }
    }
    return sum_ > 0;
}

bool check_ever(double it){
    dp_e[1] = 1.0 * array[1] - it;
    for(int i = 2;i <= n;i++){
        double temp = 1.0 * array[i]-it;
        dp_e[i] = std::max(dp_e[i-1]+temp,dp_e[i-2]+temp);//
    }
    return (dp_e[n]+eps > 0 || dp_e[n-1]+eps > 0);
}

void bin_mid(){
    int l = 1, r = 1e9;
    while(l <= r){
        int mid = (l+r)>> 1;
        if(check_mid(mid))
            l = mid+1;
        else
            r = mid-1;
    }
    printf("%d\n",l-1);
}

void bin_ever(){
    double l = 0 , r = 1e9;
    while(r-l > eps){
        double mid = (l+r)/2;
        if(check_ever(mid))
            l = mid;
        else
            r = mid;
    }
    printf("%.9f\n",l);
}

int main(){
    scanf(" %d",&n);
    for(int i = 1;i <= n;i++){
        scanf(" %d",&array[i]);
    }
    bin_ever();
    bin_mid();
    return 0;
}