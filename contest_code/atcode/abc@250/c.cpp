#include<iostream>
#include<cstdio>
#include<algorithm>
#include<deque>
#include<string>
#include<vector>
#include<list>

const int max_n = 2e5+10;
int opera[max_n];
int n,q;
std::list<int> ball;
std::list<int>::iterator ptr_ball[max_n];


int main(){
    scanf(" %d %d",&n,&q);
    for(int i = 1;i <= n;i++){
        ball.push_back(i);
        ptr_ball[i] = --ball.end();
    }
    for(int i = 1;i <= q;i++){
        scanf(" %d",&opera[i]);
    }
    for(int i = 1;i <= q;i++){
        auto it = ptr_ball[opera[i]];
        auto it_next = it; it_next++;
        if(it_next != ball.end()){
            it_next++;
            ball.erase(it);
            ptr_ball[opera[i]] = ball.emplace(it_next,opera[i]);
        }
        else{
            it_next--;
            it_next--;
            ball.erase(it);
            ptr_ball[opera[i]] = ball.emplace(it_next,opera[i]);
        }
    }

    for(auto it : ball){
        printf("%d ",it);
    }
    printf("\n");
    return 0;
}