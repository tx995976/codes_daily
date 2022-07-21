#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>

using namespace std;
using itor_map = map<string,int>::iterator;

map<string,int>node_map;

void func_map_add(string s1,int num){
    itor_map num1 = node_map.find(s1);
    if(num1 == node_map.end()){
        node_map[s1] = num;
        cout<<"OK"<<endl;
    }
    else{
        num1->second = num;
        cout<<"OK"<<endl;
    }
}

void func_map_find(string s1){
    itor_map num1 = node_map.find(s1);
    if(num1 == node_map.end())
        cout<<"Not found"<<endl;
    else
        cout<<num1->second<<endl;
}

void func_map_del(string s1){
    itor_map num1 = node_map.find(s1);
    if(num1 == node_map.end())
        cout<<"Not found"<<endl;
    else{
        node_map.erase(num1->first);
        cout<<"Deleted successfully"<<endl;
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int k,i,x;
    string s1;
    cin>>k;
    while(k--){
        cin>>i;
        switch(i){
            case 1:
                cin>>s1>>x;
                func_map_add(s1,x);
                break;
            case 2: 
                cin>>s1;
                func_map_find(s1);
                break;
            case 3:
                cin>>s1;
                func_map_del(s1);
                break;
            case 4:
                cout<<node_map.size()<<endl;
                break;
        }
    }

    return 0;
}