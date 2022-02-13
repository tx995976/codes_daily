#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>

const int max_str = 1e6+10;

char str[max_str];
int k_next[max_str],ans;


int main(){
    while(scanf("%s",str) && str[0] != '.'){
        int len = strlen(str);
        k_next[0] = 0,k_next[1] = 0;
        for(int i = 1;i < len;i++){
            int pos = k_next[i];
            while(pos && str[i] != str[pos])
                pos = k_next[pos];
            k_next[i+1] = str[i] == str[pos] ? pos+1 : 0;
        }
        int max_str = len - k_next[len];
        printf("%d\n",len%max_str != 0 ? 1 : len / max_str);
    }
    return 0;
}