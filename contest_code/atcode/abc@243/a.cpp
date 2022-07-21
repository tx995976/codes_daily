#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>

int V,U[3];
int i = 0;

char ans[] = {'F','M','T'};

bool use(int i){
    if(V >= U[i]){
        V -= U[i];
        return 1;
    }
    return 0;
}

int main(){
    scanf(" %d %d %d %d",&V,&U[0],&U[1],&U[2]);
    while(use(i))
        i = (i+1)%3;
    printf("%c\n",ans[i]);
    return 0;
}