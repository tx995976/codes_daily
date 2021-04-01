#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;


int fibo(int i){
    if(i == 1)
        return 1;
    if(i == 2)
        return 1;
    return fibo(i - 1)+fibo(i - 2);
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int i;
    while(1){
        cout<<"month: "<<endl;
        cin>>i;
        if(i <= 0)
            return 0;
        cout<<"result: "<<fibo(i)<<endl;
    }
    return 0;
}