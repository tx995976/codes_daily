//遍历
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

string s1,s2;
int ans;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    getline(cin,s1);
    getline(cin,s2);
    for(int i = 0;i < s1.length();i++)
        for(int k = 1;k < s2.length();k++)
            if(s1[i] == s2[k] && s1[i+1] == s2[k-1])
                    ans++;
    cout<<(1<<ans)<<endl;
    return 0;
}