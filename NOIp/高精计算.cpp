#include<bits/stdc++.h>
using namespace std;
int main(){
    //高精度加法尝试
    string number1,number2,result;
    int i;
    cin>>number1>>number2;
    int length1=number1.length(),
        length2=number2.length();
    //平衡位数
    while(length1>length2){
        number2="0"+number2;
        length2=number2.length();
    }
    while(length1<length2){
        number1="0"+number1;
        length1=number1.length();
    }
    //开始加数;
    int temp=0,bit=0;
    for( int i=length1-1;i>=0;i--){
        temp=(number1[i]-'0')+(number2[i]-'0')+bit;
        bit=temp/10;
        temp%=10;
        result=char(temp+'0')+result;
    }
    if(bit!=0){result=char(bit+'0')+result;}
    cout<<result;
    return 0;
    
}
// char 转 int -‘0’
// int 转 char +‘0’
// string 类默认元素为char型。  