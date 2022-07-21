#include<iostream>
#include<cstdio>
#include<algorithm>
#include<deque>
#include<string>
#include<vector>

char str[3];
int cnt[26] = {0};

int main(){
    int ans = -1;
    scanf("%s",str);
    for(auto it : str)
        cnt[it-'a'] += 1;
    for(int i = 0; i < 26;i++)
        if(cnt[i] == 1)
            ans = i;
    if(ans == -1)
        printf("-1\n");
    else 
        printf("%c\n",ans+'a');
    return 0;
}