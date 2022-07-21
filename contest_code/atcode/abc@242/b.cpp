#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>

const int max_n = 2e5+10;
char str[max_n];
int letter[30];
std::string ans;

int main(){
    scanf(" %s",&str);
    for(auto it : str){
        if(it != '\0')
            letter[it-'a']++;
        else
            break;
    }
    for(int i = 0;i < 26;i++)
        ans.insert(ans.end(),letter[i],(i+'a'));
    printf("%s\n",ans.c_str());
    return 0;
}