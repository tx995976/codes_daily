#include<iostream>
#include<cmath>

using namespace std;


int narcissistic( int number ){
    int temp,total=0,all[10],result=0;
    temp = number;
    while(number!=0){
        all[total+1]=number%10;
        number=number/10;
        total++;
    }
    for(int k = 1;k<=total;k++)
        result+=pow(all[k],total);
    if(result==temp)return 1;
    else return 0;
}

void PrintN( int m, int n ){
    int temp=m+1;
    while(temp>m&&temp<n){
        if(narcissistic(temp))printf("%d\n",temp);
        temp++;
    }
}
int main(){
    int m,n;
    cin>>m>>n;
    if ( narcissistic(m) )
        cout<<n<<" is a narcissistic number"<<endl;
    PrintN(m, n);
    if ( narcissistic(n) ) 
        cout<<n<<" is a narcissistic number"<<endl;
    return 0;
}
