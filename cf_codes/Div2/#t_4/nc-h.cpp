#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>
#include<set>

std::set<int> ids;

int main(){
    int n,temp;
    scanf(" %d",&n);
    for(int i = 1;i <= n;i++){
        scanf(" %d",&temp);
        ids.insert(temp);
    }
    printf("%d\n",ids.size());
    for(auto it : ids)
        printf("%d ",it);
    printf("\n");
    return 0;
}