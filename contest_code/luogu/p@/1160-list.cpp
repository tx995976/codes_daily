#include<iostream>
#include<list>

using namespace std;
using it_itor = list<int>::iterator;

bool rmove[100010];
it_itor mover[100010];
list<int> my_list[100010];
int n,m;

void list_build (){
    my_list->push_front(1);
    mover[1] = my_list->begin();
    it_itor next_itor; 
    int a,b;
    for(int i = 2;i <= n;i++){
        cin>>a>>b;
        if(b == 0)
            mover[i] = my_list->insert(mover[a], i);
        else{
            next_itor = next(mover[a]);
            mover[i] = my_list->insert(next_itor,i);
        }
    }
}

inline void erased(){
    int a;
    for(int i = 1;i <= m;i++){
        cin>>a;
        if(!rmove[a])
            my_list->erase(mover[a]);
        rmove[a] = 1;
    }
}

inline void print(){
    it_itor a = my_list->begin();
    while(a != my_list->end()){
        cout<<*a<<" ";
        a = next(a);
    }
    cout<<endl;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    list_build();
    cin>>m;
    erased();
    print();
    return 0;
}