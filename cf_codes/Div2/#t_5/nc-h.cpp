#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>
#include<queue>

std::priority_queue<int,std::vector<int>,std::greater<int>> fruit;

int main(){
    int n,temp,ans = 0,f1,f2,plus;
    scanf(" %d",&n);
    for(int i = 1;i <= n;i++){
        scanf(" %d",&temp);
        fruit.push(temp);
    }
    while(fruit.size() > 1){
        f1 = fruit.top(); fruit.pop();
        f2 = fruit.top(); fruit.pop();
        plus = f1 + f2;
        ans += plus;
        fruit.push(plus);
    }
    printf("%d\n",n == 1 ? 0 : ans);
    return 0;
}