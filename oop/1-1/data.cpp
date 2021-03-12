#include"test.hpp"

map<string,member> data_tree;
ifstream data_in;
ofstream data_out;

using itor_map = map<string,member>::iterator;
extern itor_map now_contrl;

bool login(){
    string a,b;
    cout<<"id:";
    cin>>a;
    itor_map temp = data_tree.find(a);
    if(temp == data_tree.end()){
        cout<<"id不存在"<<endl;
        return 0;
    }
    cout<<"password:";
    cin>>b;
    if(temp->second.match_password(b))
        
        
}



void data_read(){
    member temp;
    string a,b,c;
    double d;
    data_in.open("data.txt",ios::in);
    while(cin>>a){
        cin>>b>>c>>d;
        temp.new_card(a,b,c,d);
        data_tree[a] = temp;
    }
    data_in.close();
    return;
}
 void data_write(){
    string a,b,c;
    double d;
    data_out.open("data.txt",ios::out);
    for(itor_map now = data_tree.begin();now != data_tree.end();now++){
        a = now->second.show_id();
        b = now->second.show_password();
        c = now->second.show_name();
        d = now->second.show_money();
        data_out<<a<<" "<<b<<" "<<c<<" "<<d;
    }
    data_out.close();
    return;
}
