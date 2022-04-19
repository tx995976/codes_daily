#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>
#include<string>

using ll = long long;
int Q,x,c,fn;
ll ans;
std::deque<std::pair<int,int>> items;

int main(){
    scanf(" %d",&Q);
    while(Q--){
        scanf(" %d",&fn);
        switch(fn){
            case  1:
                scanf(" %d %d",&x,&c);
                items.push_back({x,c});
                break;
            case  2:
                scanf(" %d",&c);
                ans = 0ll;
                while(c){
                    if(items.front().second > c){
                        items.front().second -= c;
                        ans += (ll)items.front().first*c;
                        c = 0;
                    }
                    else{
                        c -= items.front().second;
                        ans += (ll)items.front().first * (ll)items.front().second;
                        items.pop_front();
                    }
                }
                printf("%lld\n",ans);
                break;
        }
    }
    return 0;
}