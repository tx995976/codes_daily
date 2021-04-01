#include"member.hpp"
#include"data_info.hpp"

using itor_map = map<string,member>::iterator;
map<string,member> data_tree;                  ///////////索引树
itor_map now_contrl;
int i;

//////////////////////////////////////////////////////////////////////////////
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
        temp = data_tree.find(a);
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
//////////////////////////////////////////////////////////////////////////////

void query_card(){
        string status;
        if(now_contrl->second.status == 1)
            status = "online";
        else
            status ="offline";    
        cout<<"当前用户:"<<now_contrl->second.show_name()<<"     余额:"<<now_contrl->second.show_money()<<endl
            <<"状态: "<<status<<endl;
        return;
}

void add_card(){
         string temp,temp1,temp3;
         double temp2;
         cout<<"输入你的名字: ";
         cin>>temp;
         cout<<"输入你的id: ";
         cin>>temp3;
         cout<<"输入你的密码: ";
         cin>>temp1;
         cout<<"输入你的开卡金额: ";
         cin>>temp2;
         member new_card(temp3,temp1,temp,temp2);
         data_tree[temp3] = new_card;
         cout<<"注册已完成"<<endl;
         return;
     }

    bool delete_card(){
        string b;
        cout<<"password:";
        cin>>b;
        while(!(now_contrl->second.match_password(b))){
            cout<<"密码错误，请重试"<<endl<<"password:";
            cin>>b;
        }
        cout<<now_contrl->second.show_name()<<" 您确定要退卡吗?"<<endl<<"1.是      2.否"<<endl;
        cin>>i;
        if(i){
            cout<<"退卡已完成"<<endl
                <<"姓名:"<<now_contrl->second.show_name()<<"        "<<"金额:"<<now_contrl->second.show_money()<<endl;
            data_tree.erase(now_contrl);
            return 1;
        }
        return 0;
     }



//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
////改二进制
void user_data_read(){
    ifstream data_in;
    string a,b,c;
    double d;
    data_in.open("data.data",ios::in);
    while(data_in.good()){
        data_in>>a>>b>>c>>d;
        member temp(a,b,c,d);
        data_tree[a] = temp;
    }
    data_in.close();
    return;
}

 void user_data_write(){
    ofstream data_out;
    string a,b,c;
    double d;
    data_out.open("data.data",ios::out);
    for(itor_map now = data_tree.begin();now != data_tree.end();now++){
        a = now->second.show_id();
        b = now->second.show_password();
        c = now->second.show_name();
        d = now->second.show_money();
        data_out<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    }
    data_out.close();
    return;
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
 void start_up(){
    time_t now = time(NULL);
    record_online(now);
    cout<<"欢迎使用，已开机"<<endl;
    cout<<"当前时间： "<<(char*)ctime(&now)<<endl;
    now_contrl->second.status = 1;
 }
 void shut_down(){
    time_t now = time(NULL);
    record_offline(now);
    cout<<"欢迎下次使用"<<endl;
    cout<<"当前时间： "<<(char*)ctime(&now)<<endl;
    now_contrl->second.status = 0;

 }