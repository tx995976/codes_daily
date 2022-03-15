#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>
#include<vector>

struct b_pair{
    int x = 0,y = 0,direct = 0;

    bool operator < (const b_pair r){
        if(y != r.y)
            return y < r.y;
        else
            return x < r.x;
    }
};

std::vector<b_pair> peo;
std::string dic;
int n,x,y;
bool flag = 0;

int main(){
    scanf(" %d",&n);
    for(int i = 1;i <= n;i++){
        scanf(" %d %d",&x,&y);
        peo.push_back({x,y,0});
    }
    std::cin>>dic;
    for(int i = 0;i < n;i++)
        peo[i].direct = (dic[i] == 'L' ? 0 : 1);
    std::sort(peo.begin(),peo.end());
    int l = 0,r = 1;
    while(r < n){
        if(peo[l].y != peo[r].y){
            l++,r++;
            continue;
        }
        if(peo[l].direct == 1 && peo[r].direct == 0){
            flag = 1;
            break;
        }
        else
            l++,r++;
    }
    printf("%s\n",flag ? "Yes" : "No");
    return 0;
}