#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>
#include<list>

std::list<int> t1,t2,t3;
int temp;
char flag;

int main(){
    while(~scanf(" %d%c",&temp,&flag)){
        t1.push_back(temp);
        if(flag == '\n')
            break;
    }
    while(~scanf(" %d%c",&temp,&flag)){
        t2.push_back(temp);
        if(flag == '\n')
            break;
    }
    auto it_1 = t1.begin() , it_2 = t2.begin();
    while(it_1 != t1.end() || it_2 != t2.end()){
        if(it_2 == t2.end() ||(it_1 != t1.end() && *it_1 < *it_2)){
            if(t3.empty() || t3.back() != *it_1)
                t3.push_back(*it_1);
            it_1++;
        }
        else{
            if(t3.empty() || t3.back() != *it_2)
                t3.push_back(*it_2);
            it_2++;
        }
    }
    for(auto it : t3)
        printf("%d ",it);
    return 0;
}