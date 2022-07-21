#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<iostream>


std::string s,t;
std::set<char> v;

int main(){
	std::getline(std::cin,s);
	std::getline(std::cin,t);
	s.insert(s.end(),t.length()-s.length(),' ');
    int l_s= 0,l_t= 0;	
	while(l_t < t.length()){
    	if(s[l_t] == t[l_t]){
			l_t++;
		}
		else{
			v.insert(t[l_t]);
			t.erase(l_t,1);
		}
	}
	for(auto it : v){
		printf("%c",it);
	}
	printf("\n");
	return 0;
}

