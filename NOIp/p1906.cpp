#include<bits/stdc++.h>
using namespace std;   
//模块准备
int password=0;
vector<string> word;
int count(int a[]);//统计
string result(string,int);//解密

int count(int cou1[]){
    int max=1;
    for(int i = 2;i<=26;i++){
        if(cou1[max]<cou1[i]){max=i;}
        }
    
    
        
    /*int i=0,max=1;
    char in;
    for(int i = 0;i<input.length();i++){
        in=input[i];
        if(in==' '||in==',')continue;
        cou[in-'A'+1]+=1;
        in=input[++i];
    }*/
    return max;
}

string result(string input,int password){
    char in,temp;
    int i=0;
    in = input[i];
    while(i<input.length()){
        if(input[i]==' '||input[i]==','){i++;continue;}
        in = input[i];
        temp=in+1-'A'+password;
        if(temp<=0){temp+=26;}
        if(temp>26){temp-=26;}
        input[i]=temp+'A'-1;
        in = input[++i];
    }
    return input;
}

int main(){
    int i=0,max;
    char in;                   
    string temp,input,st,end;   //读入
    int * cou1 = new int [30]; 
    while(1){
        getline(cin,st);
        if(st=="ENDOFINPUT")break;
        getline(cin,input);
        for(int i = 0;i<input.length();i++){
            in=input[i];
            if(in==' '||in==',')continue;
            cou1[in-'A'+1]+=1;
            in=input[++i];
            }
        word.push_back(input);
        //count(cou1);                     //统计
        getline(cin,end);
        }  
    /*for(int i = 2;i<=26;i++){
        if(cou[max]<cou[i]){max=i;}
        i++;
        }*/
    password=count(cou1)-('E'-'A'+1);
    delete [] cou1;
    for(int i=0;i<sizeof(word);i++){
        cout<<result(word[i],password)<<endl;
    }
    return 0;
}

