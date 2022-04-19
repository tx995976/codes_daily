#include<iostream>
#include<algorithm>
#include<cstdio>
#include<map>
#include<fstream>
#include<vector>

struct info{
    std::string au,co,da;
};
std::map<std::string,info> data;

void find_book(std::string &key){
    for(auto it : data){
        if(it.first.find(key) != std::string::npos){
            printf("%-50s%-20s%-30s%-10s\n",
                it.first.c_str(),
                it.second.au.c_str(),
                it.second.co.c_str(),
                it.second.da.c_str());
        }
    }
}
//
void de_book(std::string &key){
    std::vector<std::string> matchs;
    for(auto it : data){
        if(it.first.find(key) != std::string::npos){
           matchs.push_back(it.first);
        }
    }
    for(auto it : matchs)
        data.erase(it);
}

int main(){
    int func;
    std::string temp,au,co,da;
    std::ifstream in("books.txt",std::ios::in);
    while(in.good() && !in.eof()){
        in>>temp>>au>>co>>da;
        data[temp] = {au,co,da};
    }
    while(scanf(" %d",&func)&&func){
        switch(func){
            case  1:
                std::cin>>temp>>au>>co>>da;
                data[temp] = {au,co,da};
                break;
            case  2:
                std::cin>>temp;
                find_book(temp);
                break;
            case  3:
                std::cin>>temp;
                de_book(temp);
                break;
        }
    }
    freopen("ordered.txt","w",stdout);
    for(auto it : data){
        printf("%-50s%-20s%-30s%-10s\n",
                it.first.c_str(),
                it.second.au.c_str(),
                it.second.co.c_str(),
                it.second.da.c_str());
    }
    return 0;
}