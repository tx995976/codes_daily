#include"test.hpp"

using itor_map = map<string,member>::iterator;
map<string,member> data_tree;                  ///////////索引树
itor_map now_contrl;


//////////////////////////////////////////////////////////////////////////////
void login(){
    string a,b;
    system("cls");
    cout<<"id:";
    cin>>a;
    itor_map temp = data_tree.find(a);
    while(temp == data_tree.end()){
        cout<<"id不存在,请重试"<<endl<<"id:";
        cin>>a;
        itor_map temp = data_tree.find(a);
    }
    cout<<"password:";
    cin>>b;
    while(!(temp->second.match_password(b))){
        cout<<"密码错误，请重试"<<endl<<"password:";
        cin>>b;
    }
    now_contrl = temp;
}

void welcome(){
    cout<<"欢迎:"<<now_contrl->second.show_name()<<endl;
}

//////////////////////////////////////////////////////////////////////////////

void add_card(){
         string temp,temp1,temp3;
         double temp2;
         cout<<"输入你的名字:";
         cin>>temp;
         cout<<"输入你的id";
         cin>>temp3;
         cout<<"输入你的密码";
         cin>>temp1;
         cout<<"输入你的开卡金额";
         cin>>temp2;
         member new_card(temp3,temp1,temp,temp2);
         data_tree[temp3] = new_card;
         cout<<"注册已完成"<<endl;
         return;
     }

//////////////////////////////////////////////////////////////////////////////
    ifstream data_in;
    ofstream data_out;

void data_read(){
    string a,b,c;
    double d;
    data_in.open("data.txt",ios::in);
    while(cin>>a){
        cin>>b>>c>>d;
        member temp(a,b,c,d);
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

//////////////////////////////////////////////////////////////////////////////