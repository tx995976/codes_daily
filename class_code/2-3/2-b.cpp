#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>
#include<list>

std::list<int> q_list[2];
int m,n;
int id_list = 1;

void prt(){
    for(auto it : q_list[id_list^1])
        printf("%4d",it);
    printf("\n"); 
}

int main(){
    scanf(" %d",&m);
    for(int i = 1;i <= m;i++)
        q_list[0].push_back(i);

    while(~scanf(" %d",&n)){
        id_list ^= 1;
        q_list[id_list^1].clear();
        auto it  = q_list[id_list].begin();

        while(!q_list[id_list].empty()){

            int i = n-1;
            while(i--){
                //边界
                if(++it == q_list[id_list].end())
                    it = q_list[id_list].begin();
            }

            auto er_it = it;

            //边界
            if(++it == q_list[id_list].end())
                it = q_list[id_list].begin();

            q_list[id_list^1].push_back(*er_it);
            q_list[id_list].erase(er_it);
        }
    }
    prt();
    return 0;
}
