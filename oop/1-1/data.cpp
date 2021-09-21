#include"member.hpp"
#include"data_info.hpp"

using itor_map = map<string,member>::iterator;
map<string,member> data_tree;                  ///////////索引树
itor_map now_contrl;
int i;

void login(){
    string a,b;
    system("cls");
    cout<<"id:";
    cin>>a;
    itor_map temp = data_tree.find(a);
    while(temp == data_tree.end()||temp->second.health == 0){
        cout<<"id不存在或已注销,请重试"<<endl<<"id:";
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

    //////////////////////////////////
    send_Key(now_contrl->second.show_id());
    user_load();
}

void logout(){
    user_info_money_add_write();
    user_info_cost_write();
    user_info_member_write();
    user_logout();
    return;
}

void welcome(){
    cout<<"欢迎:"<<now_contrl->second.show_name()<<endl;
}

void count_sys(){
    user_info_welcome();
    return;
     }

bool admin_log(){
    if(now_contrl->second.show_id().find("admin") != string::npos){
        admin_info_welcome();
        return 1;
    }
    else
        return 0;
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////


void return_money(){    
    time_t now = time(NULL);     //////////////////
    double temp;
    if(now_contrl->second.show_money() <= 0){
        cout<<"当前账户无法退费"<<endl;
        return;
    }
    cout<<"输入您希望的退费金额:"<<" (当前金额: "<<now_contrl->second.show_money()<<")"<<endl;
    cin>>temp;
    if(temp > now_contrl->second.show_money())
        cout<<"金额不足"<<endl;
    else{
        record_add_money(now,0-temp);
        now_contrl->second.cost_money(temp);
        cout<<"退费完成"<<endl;

    }
    return;
}

void add_money(){
    time_t now = time(NULL);
    double temp;
    cout<<"输入充值金额: "<<endl;
    cin>>temp;
    now_contrl->second.money_add(temp);
    cout<<"充值完成"<<endl
        <<"金额: "<<temp<<" $"<<endl;

    //////////////////////////////////////////
    record_add_money(now,temp);
    return;
}

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
        member empty;
        int i = 1;
        cout<<"输入你的名字: ";
        cin>>empty.name;
        while(i){
            cout<<"输入你的id: ";
            cin>>empty.id;
            if(data_tree.find(empty.id) != data_tree.end()){
                cout<<"id已存在,请重新输入:"<<endl;
                continue;
            }
            i = 0;
        }
        cout<<"输入你的密码: ";
        cin>>empty.password;
        cout<<"输入你的开卡金额: ";
        cin>>empty.money;
        data_tree[empty.id] = empty;
        user_new_member(empty.id,empty.name);
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
        if(i == 1){
            cout<<"退卡已完成"<<endl
                <<"姓名:"<<now_contrl->second.show_name()<<"        "<<"金额:"<<now_contrl->second.show_money()<<endl;
            now_contrl->second.health = 0;
            user_card_remove();
            return 1;
        }
        else
            cout<<"已取消"<<endl;
        return 0;
     }
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void user_data_read(){
    ifstream data_in("data.data",ios::in);
    member temp;
    while(data_in>>temp.id){
        data_in>>temp.password>>temp.name>>temp.money>>temp.status>>temp.health;
        data_tree[temp.id] = temp;
    }
    data_in.close();
    map_load();
    return;
}

 void user_data_write(){
    ofstream data_out;
    data_out.open("data.data",ios::out);
    for(itor_map now = data_tree.begin();now != data_tree.end();now++){
        data_out<<now->second.id<<" "<<now->second.password<<" "<<now->second.name<<" "<<now->second.money<<" "<<now->second.status<<" "<<now->second.health<<endl;
    }
    data_out.close();
    map_write();
    return;
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
 void start_up(){
    time_t now = time(NULL);
    if(now_contrl->second.show_money() < 0)
        cout<<"已欠费"<<endl;
    if(now_contrl->second.status == 1){
        cout<<"已上机"<<endl;
        return;
    }
    cout<<"欢迎使用，已开机"<<endl;
    cout<<"当前时间： "<<(char*)ctime(&now)<<endl;
    record_online(now);
    now_contrl->second.status = 1;
 }
 void shut_down(){
    time_t now = time(NULL);
    if(now_contrl->second.status == 0){
        cout<<"已下机"<<endl;
        return;
    }
    double cost = record_offline(now);
    now_contrl->second.status = 0;
    now_contrl->second.cost_money(cost);
    cout<<"欢迎下次使用"<<endl;
    cout<<"当前时间： "<<(char*)ctime(&now)<<endl
        <<"本次消费: "<<cost<<" $"<<endl
        <<"余额: "<<now_contrl->second.show_money()<<" $"<<endl;
 }