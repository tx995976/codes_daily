#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>
#include<string>

std::string st = "1";

int main(){
    int n;
    scanf(" %d",&n);
    for(int i = 2;i <= n;i++){
        st = st+" "+std::to_string(i)+" "+st;
    }
    printf("%s\n",st.c_str());
    return 0;
}