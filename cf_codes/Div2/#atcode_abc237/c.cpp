#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>
#include<string>

std::string in;
int cnt_l=0,cnt_r=0,length,flag = 1;

bool judge(){
    int pos_l = 0,pos_r = in.length()-1;
    while(pos_l < pos_r){
        if(in[pos_l++] != in[pos_r--])
            return 0;
    }
    return 1;
}

int main(){ 
    std::cin>>in;
    length = in.size()-1;
    while(in[length--] == 'a')
        cnt_r++;
    if(cnt_r >= in.size()-1)
        flag = 0;
    if(flag){
        length = 0;
        while(in[length++] == 'a')
            cnt_l++;
        int n = cnt_r - cnt_l;
        if(n < 0){
            printf("No\n");
            return 0;
        }
        in.insert(0,n,'a');
        printf("%s\n",judge() ? "Yes" : "No");
        return 0;
    }
    else
        printf("Yes\n");
    return 0;
}