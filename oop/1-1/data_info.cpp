#include"data_info.hpp"

map<string,all_member_info> data_info;
vector<total_income> income_record;

using itor_info = map<string,all_member_info>::iterator;
using itor_cost = vector<info_cost>::iterator;
using itor_money = vector<info_money_add>::iterator;

itor_info user;
string control_id;
double time_price = 5;
double price_for_night = 15;

///////////////////////////////////////////////////////////////////////
void info_member::show(){
    cout<<"id:     "<<this->id<<endl
        <<"名字:    "<<this->name<<endl
        <<"开卡时间: "<<(char*)ctime(&this->card_start)
        <<"注销时间: "<<(char*)ctime(&this->card_end)    
        <<"累计消费: "<<this->money_all<<" $"<<endl
        <<"用户状态: "<<this->status<<endl<<endl;
}

void info_cost::show(){
    cout<<"上机时间:"<<(char*)ctime(&this->online)
        <<"下机时间:"<<(char*)ctime(&this->offline)
        <<"消费金额:"<<this->cost<<" $"<<endl<<endl;
}

void info_money_add::show(){
    cout<<"时间: "<<(char*)ctime(&this->time)
        <<"金额: "<<this->add_money<<" $"<<endl<<endl;
}
///////////////////////////////////////////////////////////////////////

void send_Key(string id){
    ::control_id = id;                        
    user = data_info.find(id);
}

void record_online(time_t time){
    info_cost temp;
    temp.online = time;
    user->second.cost.push_back(temp);
    return;
}   

double record_offline(time_t time){
    double cost;
    info_cost &temp = user->second.cost.back();
    temp.offline = time;
    cost = once_cost();
    temp.cost = cost;
    return cost;
}

double once_cost(){
    info_cost &temp = user->second.cost.back();
    double cost; 
    //  23-6为包夜时间 15元 //
    tm online ,offline;
    localtime_s(&online,&temp.online);
    localtime_s(&offline,&temp.offline);
   
    //默认不超过一天//
        if(online.tm_hour > 23||online.tm_hour < 6){
            if(offline.tm_hour > 23||offline.tm_hour < 6)
                cost = price_for_night;
            else{
                if(offline.tm_min == 0&&offline.tm_sec == 0)
                    cost = price_for_night + (offline.tm_hour - 6)*time_price;
                else
                    cost = price_for_night +(offline.tm_hour - 5)*time_price;
            }
        }
        else if(offline.tm_hour > 23||offline.tm_hour < 6){
                cost = price_for_night+(23 - online.tm_hour) * time_price;
        }
        else if(online.tm_hour < 23 &&  offline.tm_hour > 6.& online.tm_mday != offline.tm_mday){
            if(offline.tm_min == 0 && offline.tm_sec == 0)
                cost = price_for_night + (offline.tm_hour - 6)*time_price + (23 - online.tm_hour)*time_price;
            else
                cost = price_for_night +(offline.tm_hour - 5)*time_price + (23 - online.tm_hour)*time_price;
        }
        else{
            if(offline.tm_min > online.tm_min){
                cost = (offline.tm_hour - online.tm_hour+1) * time_price;
            }
            else if(offline.tm_sec > online.tm_sec)
                cost = (offline.tm_hour - online.tm_hour+1) * time_price;
            else{
                cout<<"this"<<endl;
                cost = (offline.tm_hour - online.tm_hour) * time_price;
            }

        }
        income_data_write(temp.offline,cost);
        user->second.member.money_all += cost;
        return cost;
}

void record_add_money(time_t time,double money){
    info_money_add empty;
    empty.add_money = money;
    empty.time = time;
    user->second.money_add.push_back(empty);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define error cerr<<"error"<<endl;

void map_load(){
    all_member_info empty;
    string id;
    ifstream map_in("./user_info/map.data",ios::in);
    if(map_in)
        while(map_in>>id){
            data_info[id] = empty;
        }
    else
        error
    map_in.close();
}

void map_write(){
    ofstream map_out("./user_info/map.data",ios::out);
    itor_info temp = data_info.begin();
    for(temp;temp != data_info.end();temp++){
        map_out<<temp->first<<endl;
    }
    map_out.close();
}

void user_info_member_load(){
    info_member empty;
    ifstream load("./user_info/"+user->first+"_member.data",ios::in);
    if(load){
        load>>empty.id>>empty.name>>empty.card_start>>empty.card_end>>empty.money_all>>empty.status;
        user->second.member = empty;
    }
    else
        error
    load.close();
}

void user_info_member_write(){
    ofstream write("./user_info/"+user->first+"_member.data",ios::out);
    write<<user->second.member.id<<" "<<user->second.member.name<<" "<<user->second.member.card_start<<" "<<user->second.member.card_end<<" "<<user->second.member.money_all<<" "<<user->second.member.status<<endl;
    write.close();
}

void user_info_cost_load(){
    info_cost empty;
    ifstream load("./user_info/"+user->first+"_cost.data",ios::in);
    if(load)
        while(load>>empty.online>>empty.offline>>empty.cost)
            user->second.cost.push_back(empty);
    else 
        error
    load.close();
}

void user_info_cost_write(){
    ofstream write("./user_info/"+user->first+"_cost.data",ios::out);
    for(auto i = user->second.cost.begin();i != user->second.cost.end();i++){
        write<<i->online<<" "<<i->offline<<" "<<i->cost<<endl;
    }
    write.close();
}

void user_info_money_add_load(){
    info_money_add empty;
    ifstream load("./user_info/"+user->first+"_money,data",ios::in);
    if(load)
        while(load>>empty.time>>empty.add_money)
            user->second.money_add.push_back(empty);
    else
        error
    load.close();
}
void user_info_money_add_write(){
    ofstream write("./user_info/"+user->first+"_money,data",ios::out);
    for(auto i = user->second.money_add.begin();i != user->second.money_add.end();i++){
            write<<i->time<<" "<<i->add_money<<endl;
    }
    write.close();
}

void income_data_load(){
    total_income empty;
    ifstream load("./user_info/income.data",ios::in);
    if(load)
        while(load>>empty.time){
            load>>empty.income;
            income_record.push_back(empty);
        }
    else
        error
    load.close();
}

void income_data_write(time_t time,double income){
    ofstream write("./user_info/income.data",ios::out|ios::app);
    write<<time<<" "<<income<<endl;
    write.close();
}

////////////////////////////////////////////////////////////////////////////////////////////

void user_card_remove(){
    time_t now = time(NULL);
    user->second.member.card_end = now;
    user->second.member.status = 0;
}

void user_new_member(string id,string name){
    time_t now = time(NULL);
    all_member_info empty;
    empty.member.id = id;
    empty.member.name = name;
    empty.member.card_start = now;
    data_info[id] = empty;
}


void user_card_info(){
    user->second.member.show();
}

void user_record_cost(){
    auto i =user->second.cost.begin();
    int a = 0;
    for(;i != user->second.cost.end();i++){
        i->show();
        a++;
    }
    cout<<"共有 "<<a<<" 条记录"<<endl;

}

void user_info_add_money(){
    auto i =user->second.money_add.begin();
    int a = 0;
    for(;i != user->second.money_add.end();i++){
        i->show();
        a++;
    }
    cout<<"共有 "<<a<<" 条记录"<<endl;
}

void user_load(){
    user_info_cost_load();
    user_info_member_load();
    user_info_money_add_load();
}

void user_logout(){
    all_member_info empty;
    user->second = empty;
}

/////////////////////////////////////////////////////////////////////////////////////////
void admin_search_id(){
    string temp;
    cout<<"输入id:"<<endl;
    cin>>temp;
    auto i = data_info.find(temp);
    if(i == data_info.end())
        cout<<"id不存在"<<endl;
    else{
        user = i;
        user_load();
        cout<<"找到用户 :"<<i->second.member.name<<endl;
        admin_view_user();
    }
}

void admin_search_non(){
    int a = 0;
    vector<itor_info> tree;
    auto i =data_info.begin();
    string temp;
    cout<<"输入id模糊查找:"<<endl;
    cin>>temp;
    for(;i != data_info.end();i++){
        user = i;
        user_load();
        if(i->first.find(temp) != string::npos || i->second.member.name.find(temp) != string::npos){
            tree.push_back(i);
            cout<<a<<".  "<<i->first<<" "<<i->second.member.name<<endl;
            a++;
        }
    }
    cout<<"共找到 "<<a<<" 个用户"<<endl<<"输入序号查看特定用户:"<<endl;
    cin>>a;
    user = tree[a];
    admin_view_user();
}

void admin_list_users(){
    int a = 0;
    vector<itor_info> tree;
    auto i =data_info.begin();
    for(;i != data_info.end();i++){
        user = i;
        user_load();
        tree.push_back(i);
        cout<<a<<".  "<<i->first<<" "<<i->second.member.name<<endl;
        a++;
    }
    cout<<"输入序号查看特定用户:"<<endl;
    cin>>a;
    user = tree[a];
    admin_view_user();
}

void admin_total_money(){
    int i = 0;
    cout<<"选择你需要查看收入的方式"<<endl
        <<"1.按月"<<endl
        <<"2.按时间段"<<endl;
    cin>>i;
    switch(i){
        case 1:
            admin_search_month();
            break;
        case 2:
            admin_search_timepoint();
            break;
        default:
            return;
    }
    return;
}

void admin_search_month(){
    int i;
    double total = 0;
    auto k = income_record.begin();
    tm j;
    cout<<"输入月份(默认年份为当前年份):"<<endl;
    cin>>i;
    for(;k != income_record.end();k++){
        localtime_s(&j,&k->time);
        if(j.tm_mon+1 == i)
            total += k->income;
    }
    cout<<i<<"月份的营业额为: "<<total<<endl;
    return;
}

void admin_search_timepoint(){
    stringstream input;
    stringstream input2;
    string st,ed;
    double total;
    int st_year,st_mon,st_day,ed_year,ed_mon,ed_day;
    auto i = income_record.begin();
    tm j;
    cout<<"输入时间段(示例: 2021.3.21 2021.6.30)"<<endl;
    cin>>st>>ed;
    replace(st.begin(),st.end(),'.',' ');
    replace(ed.begin(),ed.end(),'.',' ');
    input<<st;
    input2<<ed;
    input>>st_year>>st_mon>>st_day;
    st_year -= 1900;
    input2>>ed_year>>ed_mon>>ed_day;
    ed_year -= 1900;

    for(;i != income_record.end();i++){
        localtime_s(&j,&i->time);
        if((j.tm_year >= st_year && j.tm_year <= ed_year)
        && (j.tm_mon+1 >= st_mon && j.tm_mon+1 <= ed_mon)
        && (j.tm_mday >= st_day && j.tm_mday <= ed_day)
        ){
            total += i->income;            
        }
    }
    cout<<"时间段内的收入为: "<<total<<endl;
    return;
}

void admin_view_user(){
    int i = 1;
    while(1){
    cout<<"选择要查看的内容:"<<endl;
    cout<<"1.卡信息记录"<<endl
        <<"2.消费记录"<<endl
        <<"3.充值记录"<<endl
        <<"4.退出"<<endl<<endl;
    cin>>i;
        switch(i){
            case 1:
                user_card_info();
                break;            
            case 2:
                user_record_cost();
                break;                     
            case 3:
                user_info_add_money();
                break;            
            case 4:
                user_logout();
                return;                            
        }
        cout<<endl;
    }
}
