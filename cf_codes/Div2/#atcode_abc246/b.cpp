#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>

double x,y,k;
int a,b;

int main(){
    scanf(" %d %d",&a,&b);
    if(a != 0){
        k = (double)b/(double)a;
        x = std::sqrt(1.0/(1.0+(k*k)));
        y = k*x;
    }
    else{
        x = 0;
        y = b > 0 ? 1 : -1;
    }
    printf("%.10f %.10f\n",x,y);
    return 0;
}