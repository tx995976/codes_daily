#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>

using ll = long long;
const ll opera = 1e18;

char in[3],tar[3];

int main(){
    scanf(" %c %c %c",&in[0],&in[1],&in[2]);
    scanf(" %c %c %c",&tar[0],&tar[1],&tar[2]);
    int match = 0;
    for(int i = 0;i <= 2;i++)
        if(in[i] == tar[i])
            match++;
    switch(match){
        case 0 :
            printf("%s\n","Yes");
            break;
        case 1 :
            printf("%s\n","No");
            break;    
        case 3 :
            printf("%s\n","Yes");
            break;
    }
    return 0;
}