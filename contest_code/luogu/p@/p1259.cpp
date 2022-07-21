#include<bits/stdc++.h>
using namespace std;
int n,st,line_;
string chess[206];

void print(){
    for(int i=1;i<=2*n+2;i++){
        cout<<chess[i];
    }
    cout<<endl;
}

int first_load(int n){
    line_=n*2+1;
    for(int i = 1; i<=n; i++)               {chess[i]='o';}
    for(int i = n+1; i<=2*n; i++)           {chess[i]='*';}
    for(int i = 2*n+1; i<=2*n+2; i++)       {chess[i]='-';}
    print();
    return 0;
}

void move(int st){
    for(int i = 0;i<=1;i++){
        chess[line_+i]=chess[st+i];
        chess[st+i]='-';
    }
    line_=st;
    print();    
}

void move_chess(int n){
    if(n==4){
        move(4);move(8);move(2);move(7);move(1);
    }
    else{
        move(n);
        move(2*n-1);
        move_chess(n-1);
    }
}

int main(){
    cin>>n;
    first_load(n);
    move_chess(n);
    return 0;
}