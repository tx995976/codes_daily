#include<iostream>
#include<cstdio>
#include<algorithm>
#include<deque>
#include<string>
#include<vector>
#include<unordered_map>

std::unordered_map<std::string,int> str_map;
std::string in;

int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        std::cin>>in;
        if(str_map[in]++){
            printf("%s(%d)\n",in.c_str(),str_map[in]-1);
        }
        else
            printf("%s\n",in.c_str());
    }
    return 0;
}