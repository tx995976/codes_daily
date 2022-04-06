#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>
#include<set>
#include<vector>

//std::multiset<int> array;
std::vector<int> arr;
bool flag = 0;

int main(){
    int temp,tar;
    char end;
    while(scanf("%d%c",&temp,&end)){
        arr.push_back(temp);
        if(end == '\n')
            break;
    }

    scanf(" %d",&tar);
    int pos_l = 0,pos_r = arr.size()-1;
    while(pos_l <= pos_r){
        int jud = arr[pos_l]+arr[pos_r];
        if(tar > jud)
            pos_l++;
        else if(tar == jud){
            flag = 1;
            break;
        }
        else
            pos_r--;
    }
    if(flag)
        printf("%d %d\n",arr[pos_l],arr[pos_r]);
    return 0;
}