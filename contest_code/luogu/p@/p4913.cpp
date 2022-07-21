#include<iostream>
using namespace std;

struct str_tree{
    int lef;
    int rig;
}tree [1000010];
int result=0;

int deep_search(int i,int deep){
    if(i == 0) return 0;
    result = max(result,deep);
    deep_search(tree[i].lef,deep+1);
    deep_search(tree[i].rig,deep+1);
    return 0;
}


int main(){
    ios::sync_with_stdio(0);cin.tie();
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++)
        cin>>tree[i].lef>>tree[i].rig;   
    deep_search(1,1);
    cout<<result<<endl;
    return 0;
}