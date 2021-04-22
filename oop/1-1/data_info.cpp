#include"data_info.hpp"

map<string,all_member_info> data_info;
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
        <<"开卡时间: "<<this->card_start<<endl
        <<"注销时间: "<<this->card_end<<endl
        <<"累计消费: "<<this->money_all<<endl
        <<"用户状态: "<<this->status<<endl;
}

void info_cost::show_offline(){
    cout<<"下机时间: "<<(char*)ctime(&this->offline)<<endl;
}

void info_cost::show_online(){
    cout<<"上机时间: "<<(char*)ctime(&this->online)<<endl;
}

void info_money_add::show(){
    cout<<"充值时间: "<<(char*)ctime(&this->time)<<endl
        <<"金额: "<<this->add_money<<" $"<<endl;
}
///////////////////////////////////////////////////////////////////////

void send_Key(string id){

    ::control_id = id;                         //////////////////////////////
    if(data_info.find(id) == data_info.end()){ //////////////////////////////
        all_member_info empty;
        data_info[id] = empty;
    }
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
    cout<<offline.tm_sec<<" "<<online.tm_sec<<endl;
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
    
        user->second.member.money_all += cost;
        return cost;
}

void record_add_money(time_t time,double money){
    info_money_add empty;
    empty.add_money = money;
    empty.time = time;
    user->second.money_add.push_back(empty);
}

/////////////////////////////////////////////////////////////////////////////////////////////

#define error cerr<<"failed"<<endl;

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

////////////////////////////////////////////////////////////////////////////////////////////

void user_record_online(){
    


}

void user_record_offline(){

}

void user_card_info(){

}

void user_record_cost(){

}

/////////////////////////////////////////////////////////////////////////////////////////
void admin_search_id(){

}

void admin_search_non(){

}

void admin_list_users(){

}

void admin_delete_card(){

}














