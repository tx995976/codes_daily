#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>
#include<list>
#include<forward_list>
#include<fstream>

std::string cstr_in;

int main(){
    std::ifstream in;
    in.open("bgstations.txt",std::ios::in);
    while(std::getline(std::cin,cstr_in))
        printf("%s\n",cstr_in.c_str());
}

