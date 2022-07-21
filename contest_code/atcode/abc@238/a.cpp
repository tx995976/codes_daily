#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>


int main(){
    int i;
    scanf(" %d",&i);
    if(i == 1){
        printf("Yes\n");
        return 0;
    }
    printf("%s\n",i > 4 ? "Yes" : "No");
    return 0;
}