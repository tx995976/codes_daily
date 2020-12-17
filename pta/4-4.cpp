#include<iostream>
#include<algorithm>

using namespace std;

int num[11],ma,mi,ans,temp;
int *num1 = num;

int main(){
    for(int i = 1;i <= 10;i++){
        cin>>temp;
        *(num1+i) = temp;
    }
    sort(num+1,num+11);
    cout<<num[10]-num[1]<<endl;
    return 0;
}
