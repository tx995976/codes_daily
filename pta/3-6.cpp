#include<iostream>
#include<vector>

using namespace std;

vector<int> num;
vector<int> num_edge;


int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int temp;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(cin>>temp)
        num.push_back(temp);
    for(int i = 0, k = num.size()-1;i < num.size();i++,k--){
        temp = num[k];
        num_edge.push_back(temp);
    }
    for(int i = 0;i < num_edge.size();i++)
        cout<<num_edge[i]<<" ";
    return 0;
}