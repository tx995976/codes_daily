#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>

const int  max_bit = 999;
using ll = long long;
int n;
ll pos;
std::string procs;
std::string num;


int main(){
    scanf(" %d %lld",&n,&pos);
    std::cin>>procs;
    while(pos){
        if(pos & 1)
            num.insert(0,1,'1');
        else
            num.insert(0,1,'0');
        pos >>= 1;
    }
    for(int i = 0;i < n;i++){
        switch(procs[i]){
            case 'U':
                num.erase(num.size()-1,1);
                break;
            case 'L':
                num.insert(num.end(),'0');
                break;
            case 'R':
                num.insert(num.end(),'1');
                break;
        }
    }
    pos = 0ll;
    ll plus = 1ll;
    for(int i = num.size()-1;i >= 0;i--){
        if(num[i] == '1')
            pos += plus;
        plus <<= 1;
    }
    printf("%lld\n",pos);
    return 0;
}