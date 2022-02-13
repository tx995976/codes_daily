#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>

long long in;

int main(){
    scanf(" %lld",&in);
    printf("%s\n",(in > INT32_MAX ||in < INT32_MIN) ? "No" : "Yes");
    return 0;
}