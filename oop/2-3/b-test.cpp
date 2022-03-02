#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>

std::string in;

int main(){
    freopen("article.txt","r",stdin);
    while(std::getline(std::cin,in))
        printf("%s\n",in.c_str());
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