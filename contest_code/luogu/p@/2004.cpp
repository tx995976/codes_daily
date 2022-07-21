#include<iostream>

using namespace std;

const int node = 1010;
int squre[node][node];
int squreAdd[node][node];

void search(int n,int m,int c){
    int ans=-2147483000,temp,x,y;
    for(int i = c;i <= n;i++){
        for(int k = c;k <= m;k++){
            temp = squreAdd[i][k]+squreAdd[i-c][k-c]-squreAdd[i-c][k]-squreAdd[i][k-c];
            if(temp > ans){
                ans = temp;
                x=i-c+1;y=k-c+1;
            }     
        }
    }
    cout<<x<<" "<<y<<endl;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,m,c;
    cin>>n>>m>>c;
    for(int i = 1;i <= n;i++){
        for(int k = 1;k <= m;k++){
            cin>>squre[i][k];
            squreAdd[i][k] = squreAdd[i][k-1]+squreAdd[i-1][k]-squreAdd[i-1][k-1]+squre[i][k];
        }
    }    
    search(n,m,c);
    return 0;
}
