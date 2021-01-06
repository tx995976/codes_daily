#include<iostream>
#include<vector>

using namespace std;
 
vector<int> num;

int main(){
    int temp;
    while(cin>>temp)
        num.push_back(temp);
    for(int i = 0;i < num.size();i++)
        for(int k = 0;k < num.size();k++)
            if(num[i]<num[k])
                swap(num[i],num[k]);
    for(int i = 0;i < num.size();i++)
        cout<<num[i]<<" ";
    return 0;
}