#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>

int A,B,C,D;

bool jugde(){
    return A != C ? A < C : B <= D;
}

int main(){
    scanf(" %d %d %d %d",&A,&B,&C,&D);
    printf("%s\n",jugde() ? "Takahashi" : "Aoki");
    return 0;
}