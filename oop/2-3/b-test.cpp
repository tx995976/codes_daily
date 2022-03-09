#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>
#include<list>
#include<forward_list>

std::string in;
//std::list<int> test;
std::forward_list<int> test;

int main(){
    test.push_front(1);
    test.push_front(2);
    auto it = test.end();
    std::cout<<*it<<std::endl;
    //it++;
    std::cout<<*it;
    return 0;
}


/*if(std::cin>>in){
        for(auto it = in.begin();it != in.end();){
            if(!std::isalpha(*it))
                in.erase(it);
            else{
                //if(std::isupper(*it))
                  //  *it = std::tolower(*it);
                it++;
            }
        }
    }
    else
        return 0;
    return 1;*/