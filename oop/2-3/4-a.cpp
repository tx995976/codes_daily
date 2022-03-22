#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>

std::string middle,back;
std::string pre;

void get_pre(std::string mid,std::string ba){
    if(ba.empty())
        return;
    std::string mid_l,mid_r,ba_l,ba_r;
    char m_p = ba.back();
    ba.pop_back();

    int f_pos = mid.find(m_p);

    ba_l = ba.substr(0,f_pos);
    ba_r = ba.substr(f_pos);

    mid_l = mid.substr(0,f_pos);
    mid_r = mid.substr(f_pos+1);

    pre.push_back(m_p);
    get_pre(mid_l,ba_l);
    get_pre(mid_r,ba_r);

}

int main(){
    std::cin>>middle>>back;
    get_pre(middle,back);
    printf("%s\n",pre.c_str());
    return 0;
}