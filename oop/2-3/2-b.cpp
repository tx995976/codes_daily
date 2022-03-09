#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>
#include<list>

std::list<int> q_list[2];
int m,n;
int id_list = 1;

int main(){
    scanf(" %d",&m);
    for(int i = 1;i <= m;i++)
        q_list[0].push_back(i);
    while(~scanf(" %d",&n)){
        id_list ^= 1;
        q_list[id_list^1].clear();
        auto it  = q_list[id_list].begin();
        while(!q_list[id_list].empty()){

            int c = q_list[id_list].size();

            int i = n;
            while(i--){
                if(it == q_list[id_list].end())
                    it = q_list[id_list].begin();
                else
                    it++;
            }
            auto er_it = it;
            if(it == q_list[id_list].end())
                it = q_list[id_list].begin();
            else
                it++;
            q_list[id_list^1].push_back(*er_it);
            q_list[id_list].erase(er_it);

        }
    }
    for(auto it : q_list[id_list])
        printf("%-4d",it);
    return 0;
}