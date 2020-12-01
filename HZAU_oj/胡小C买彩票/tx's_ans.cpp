#include<iostream>
#include<set>

using namespace std;

int n,m,temp,all;
set<int> ans;

int get_ans(int t){
        if(t==7)       return m;
        else if(t==6)  return n;
        else if(t==5)  return 150;
        else if(t==4)  return 10;
        else if(t==3)  return 5;
        else           return 0;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    cin>>m>>n;
    for(int k = 1;k <= 7;k++){
        cin>>temp;
        ans.insert(temp);
    }
    for(int i = 1;i <= t;i++){
        int l;
        cin>>l;
        for(int j = 1;j <= l;j++){
            all=0;
            for(int k = 1;k <= 7;k++){
                int total = 0;
                cin>>temp;
                if(ans.count(temp))
                    total++;
                all+=get_ans(total);
            }
            cout<<all<<endl;
        }
    }
    return 0;
}