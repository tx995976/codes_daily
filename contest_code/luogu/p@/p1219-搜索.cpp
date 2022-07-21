#include<bits/stdc++.h>
using namespace std;
int y[20],x[20];
int y_left_right[50],y_right_left[50];
int all,n;

inline void print(){
    if(all<3){
        for(int i = 1;i<=n;i++){
            cout<<y[i]<<" ";
        }
        cout<<endl;
    }
    all++;    
  
}

void find_queen(int i){
    if(i>n){
        print();
        return;
    }
    else{
        for(int k = 1;k<=n;k++){
            if((!x[k])&&(!y_left_right[k+i])&&(!y_right_left[i-k+n])){
                y[i]=k;
                x[k]=1;
                y_left_right[k+i]=1;
                y_right_left[i-k+n]=1;    //另一条对角线的标记方法 n可替换为其他不冲突的数
                find_queen(i+1);
                x[k]=0;
                y_left_right[k+i]=0;
                y_right_left[i-k+n]=0;
            }
        }
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    find_queen(1);
    cout<<all;
    return 0;
}