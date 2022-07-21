#include<iostream>
#include<map>

using namespace std;

map<int,int> wood;
using itor_map = map<int,int>::iterator;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int a,b,n;
    cin>>n;
    for(int i = 1;i <= n;i++){
        cin>>a>>b;
        if(a == 1){
            if(wood.count(b))
                cout<<"Already Exist"<<endl;
            else
                wood[b] == 1;
        }
        else{
            if(wood.empty())
                cout<<"Empty"<<endl;
            else if(wood.count(b)){
                cout<<b<<endl;
                wood.erase(b);
            }
            else{
                wood[b] = 1;
                itor_map itor = wood.find(b);   itor_map itor2 = itor; //迭代器指定位置;
                itor2++; 
                if(itor == wood.begin()){
                    cout<<itor2->first<<endl;
                    wood.erase(itor2);
                }
                else if(itor2 == wood.end()){
                    cout<<(--itor)->first<<endl;
                    wood.erase(itor);
                }

                    else if(itor2->first-b < b-(--itor)->first){
                    cout<<itor2->first<<endl;
                    wood.erase(itor2);
                }
                else{
                    cout<<itor->first<<endl;
                    wood.erase(itor);
                }
                wood.erase(b);
            }
        }
    }
    return 0;
}