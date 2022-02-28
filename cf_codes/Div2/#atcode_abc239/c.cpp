#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>
#include<set>

using ll = long long;
int x1,x2,y_1,y2;
bool flag = 0;
std::set<std::pair<int,int>> position;

int dx[] = {-2,-1,1,2};
int dy[] = {1,2,2,1};

int main(){
    scanf(" %d %d %d %d",&x1,&y_1,&x2,&y2);
    for(int i = 0;i < 4;i++){
        position.insert({x1+dx[i],y_1+dy[i]});
        position.insert({x1+dx[i],y_1-dy[i]});
    }
    for(int i = 0;i < 4;i++){
        if(position.count({x2+dx[i],y2+dy[i]}) || position.count({x2+dx[i],y2-dy[i]}))
            flag = 1;
    }
    printf("%s\n",flag ? "Yes" : "No");
    return 0;
}