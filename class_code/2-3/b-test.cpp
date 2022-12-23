#include<iostream>
#include<cstdio>


std::string cstr_in;

int main(){
    while(std::getline(std::cin,cstr_in))
        printf("%s\n",cstr_in.c_str());
}

