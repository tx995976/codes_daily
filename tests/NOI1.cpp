#include<bits/stdc++.h>
using namespace std;
int main(){
    int i=0,w=0,l=0,result[62509]{};
    char temp;
    while(cin>>temp){
        if(temp=='E')break;
        if(temp=='W'){result[i++]=1;}
        if(temp=='L'){result[i++]=2;}
    }
    //11分处理
    for (int i = 0;1;i++){
        if(result[i]==1){w++;}
        if(result[i]==2){l++;}
        if(result[i]==0){
            cout<<w<<":"<<l<<endl<<endl;
            w=0,l=0;
            break;
        }
        if(w-l>=2||l-w>=2){
            if(w>=11||l>=11){
                cout<<w<<":"<<l<<endl;
                w=0,l=0;
            }
        }
    }
    //21分处理
    for(int i = 0;1;i++){
        if(result[i]==1){w++;}
        if(result[i]==2){l++;}
        if(result[i]==0){
            cout<<w<<":"<<l;
            break;
        }
        if(w-l>=2||l-w>=2){
            if(w>=21||l>=21){
                cout<<w<<":"<<l<<endl;
                w=0,l=0;               
            }
        }
    }
    return 0;    
}