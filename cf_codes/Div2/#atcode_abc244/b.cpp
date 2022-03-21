#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>

std::string in;
int n;
int x = 0,y = 0,dic = 0;
int d_x[] = {1,0,-1,0};
int d_y[] = {0,-1,0,1};


int main(){
    std::cin>>n>>in;
    for(auto it : in){
        switch(it){
            case 'S' :
                x += d_x[dic];
                y += d_y[dic];
                break;
            case 'R' :
                dic = (dic+1) % 4;
                break;
        }
    }
    printf("%d %d\n",x,y);
    return 0;
}