#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>


int main(){
    int num,bit_1;
    scanf(" %d",&num);
    bit_1 = num % 10;
    num = num / 10;
    if(bit_1 > 4)
        num += 1;
    num = num * 10;
    printf("%d\n",num);
    return 0;
}