#include<bits/stdc++.h>   
using namespace std;
int count(int a[]);
string result(string,int);

int count(int cou1[]){          //计算密码
    int max=0;
    for(int i = 1;i<=25;i++){
        if(cou1[max]<cou1[i]){max=i;}
        }
        max=max+'A'-'E';
        return max;
}
string result(string input,int password){   //解密
    int i=0;
    for(int i = 0;i<input.length();i++){
        if(input[i]>='A'&&input[i]<='Z'){
        input[i]=input[i]-password;
        if(input[i]<'A')input[i]+=26;
        if(input[i]>'Z')input[i]-=26;
        }
    }
    return input;
}
int main(){      
    using namespace std;          
    string input,st,en;  
    int temp,password=0;
    vector<string> word;
    int a[26]{0};
    while(1){
        cin>>st;
        if(st=="ENDOFINPUT") break;
        getline(cin,input);
        getline(cin,input);
        for(int i = 0;i<input.length();i++){
            if(input[i]>='a'&&input[i]<='z'){
                input[i]=toupper(input[i]);
            }
        }
        for(int i = 0;i<input.length();i++){    //记录字符出现数      
            if(input[i]>='A'&&input[i]<='Z'){
                temp=input[i]-'A';
                a[temp]+=1;
                }
            }
        word.push_back(input);
        cin>>en;
        }  
    password=count(a);
    for(int i=0;i<word.size();i++){
        cout<<result(word[i],password)<<endl;
        
    }
    return 0;
}
