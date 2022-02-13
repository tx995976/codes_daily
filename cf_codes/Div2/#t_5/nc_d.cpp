#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>
#include<string>

std::string in;

int main(){
    while(std::cin>>in){
        int pos = 0,next_pos = 1;
        for(pos = 0;pos < in.size();){
            if(in[next_pos] == in[pos]){
                switch(in[pos]){
                    case 'o' :
                        in.erase(pos,2);
                        in.insert(pos,1,'O');
                        break;
                    case 'O' :
                        in.erase(pos,2);
                        break;
                }
                pos = 0,next_pos = 1;
            }
            else
                next_pos = ++pos + 1;
        }
        printf("%s\n",in.c_str());
    }
    return 0;
}