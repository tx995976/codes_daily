#include<iostream>  
#include<cstring>

using namespace std;

int t,a,b,ans=0;
char chess[110][110];

void search(int a){
    b = a/2;
    ans = 0;
    if(a%2 != 0)
        if(chess[b+1][b+1]!='O'){
            cout<<"-1"<<endl;
            return;
        }
    for(int k = 1;k <= a;k++){
        for(int i = 1;i <= a-b;i++){
            if(k == a-k+1 &&  i == a-i+1)
                continue;
            if(chess[k][i] != 'O'){
                if(chess[a-k+1][a-i+1] == chess[k][i])
                    ans++;    
                else if(chess[a-k+1][a-i+1] != 'O')
                    continue;
                else{
                    cout<<"-1"<<endl;
                    return;
                }
            }
            else if(chess[k][i] =='O')
                if(chess[a-k+1][a-i+1] == 'O')
                    continue;
                else{
                    cout<<"-1"<<endl;
                    return;
                }
        }
        
    }
    cout<<ans<<endl;
    return;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>t;
    for(int i = 1;i <= t;i++){
        memset(chess,0,sizeof(chess));
        cin>>a;
        for(int k = 1;k <= a;k++){
            for(int i = 1;i <= a;i++)
                cin>>chess[k][i];
    }
    search(a);
    }
    return 0;    
}