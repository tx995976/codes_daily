#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>
#include<string>
#include<cstring>

int node[10] = {0},node_group[10] = {0,1,2,1,3,0,3,1,2,1};
std::string input;

int main(){
    while(std::cin>>input){
        int flag = 1;
        memset(node,0,sizeof(node));
        for(int i = 0;i < input.size()-1;i++){
            int it = input[i] - '0' , it_next = input[i+1] - '0';
            if(it == it_next || node[it_next] || node[it]){
                flag = 0;
                break;
            }
            node[it] = 1;
            if(node_group[it] == node_group[it_next] && !node[(it+it_next)/2]){
                flag = 0;
                break;
            }
        }
        printf("%s\n",flag == 1 ? "YES" : "NO");
    }
    return 0;
}