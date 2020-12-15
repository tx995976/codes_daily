#include<iostream>
#include<cmath>

using namespace std;

bool IsSquare(int n){
    int temp;
    temp = sqrt(n);
    if(pow(temp,2) == n)
        return 1;
    else 
        return 0;
}

int main(){
    int n;
    cin>>n;
    if(IsSquare(n))
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}