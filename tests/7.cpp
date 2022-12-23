#include <stdio.h>

int x,y;

int main(){
    scanf("%d",&x);
    if(x < 1)
        y = x;
    else if(x >= 10)
        y = 3*x-11;
    else 
        y = 2*x-1;
    printf("result is %d\n",y);
}