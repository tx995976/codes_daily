#include<iostream>
#include<vector>
#include<cstdio>

using namespace std;

vector<int> num;

void search(int len = num.size()){
    int n;
    scanf("%d",&n);
    int address = lower_bound(num.begin(),num.end(),n) - num.begin();
    for(int i = len-1;i >= address;i--)
        num[i+1] = num[i];
    num[address] = n;
}

int main(){
    int temp;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(cin>>temp)
        num.push_back(temp);
    cin.clear();
    cin.sync();
    num.push_back(0);
    search();
    for(int i = 0;i < num.size();i++)
        cout<<num[i]<<" ";
    return 0;
}