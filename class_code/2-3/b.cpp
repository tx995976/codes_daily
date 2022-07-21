#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>
#include<map>
#include<string>

std::map<std::string,int> cnt;

bool word_get(std::string &in){
    bool flag = 0;
    in.clear();
    char i;
    while(i = getchar()){
        if(!std::isalpha(i)){
            if(flag)
                return 1;
            if(i == EOF)
                return 0;
            if(i == '\n')
                scanf("\n");
        }
        else{
            if(std::isupper(i))
                i = std::tolower(i);
            in.push_back(i);
            flag = 1;
        }
    }
    return 0;
}

int main(){
    std::string str;
    freopen("article.txt","r",stdin);
    while(word_get(str)){
        cnt[str] += 1;
    }
    for(auto it : cnt){
        printf("%s %d\n",it.first.c_str(),it.second);
    }
    return 0;
}