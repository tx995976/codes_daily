#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>

int x1,x2,x3,x4;
int y1_,y2,y3,y4;

int main(){
    scanf(" %d %d",&x1,&y1_);
    scanf(" %d %d",&x2,&y2);
    scanf(" %d %d",&x3,&y3);
    x4 = x1 == x3 ? (x2) : (x1 == x2 ? x3 : x1);
    y4 = y1_ == y3 ? (y2) : (y1_ == y2 ? y3 : y1_);
    printf("%d %d\n",x4,y4);
    return 0;
}