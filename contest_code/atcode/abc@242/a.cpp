#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>

int A,B,C,X;
double ans;
const int all_rank = 1000;

int main(){
    scanf(" %d %d %d %d",&A,&B,&C,&X);
    if(X <= A)
        ans = 1;
    else if(X > A && X <= B)
        ans = (double)(C)/(double)(B-A);
    else
        ans = 0;
    printf("%.12f\n",ans);
    return 0;
}