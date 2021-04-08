#include"data_info.hpp"

map<string,all_member_info> data_info;
using itor_info = map<string,all_member_info>::iterator;

itor_info user;
string control_id;
const double time_price = 5;

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

void send_Key(string id){

    ::control_id = id;
    if(data_info.find(id) == data_info.end()){
        all_member_info empty;
        data_info[id] = empty;
    }
    user = data_info.find(id);
}

void record_online(time_t time){
    info_online temp;
    temp.id = ::control_id;
    temp.member_online = time;
    user->second.online.push_back(temp);
    cout<<"ok"<<endl;
    return;
}   
double record_offline(time_t time){
    info_offline temp;
    temp.id = ::control_id;
    temp.member_offline = time;
    user->second.offline.push_back(temp);
    cout<<"ok"<<endl;
    return once_cost();
}

double once_cost(){
    info_cost temp;
    temp.id = ::control_id;
    double cost;
    info_online online_time = user->second.online.back();
    info_offline offline_time = user->second.offline.back(); 
    //  23-6为包夜时间 15元 //
    tm *online = localtime(&online_time.member_online),
        *offline = localtime(&offline_time.member_offline);
    ////////////////////////////////////////////////////////////

    //默认不超过一天//
        if(online->tm_hour > 23||online->tm_hour < 6){
            if(offline->tm_hour > 23||offline->tm_hour < 6)
                cost = 15;
            else{
                if(offline->tm_min == 0&&offline->tm_sec == 0)
                    cost = 15 + (offline->tm_hour - 6)*time_price;
                else
                    cost = 15 +(offline->tm_hour - 5)*time_price;
            }
        }
        else if(offline->tm_hour > 23||offline->tm_hour < 6){
                cost = 15+(23 - online->tm_hour) * time_price;
        }
        else if(online->tm_hour < 23 &&  offline->tm_hour > 6){
            if(offline->tm_min == 0 && offline->tm_sec == 0)
                cost = 15 + (offline->tm_hour - 6)*time_price + (23 - online->tm_hour)*time_price;
            else
                cost = 15 +(offline->tm_hour - 5)*time_price + (23 - online->tm_hour)*time_price;
        }
        else{
            time_t temp = offline_time.member_offline - online_time.member_online;
            tm *temp_time = localtime(&temp);
            if(temp_time -> tm_hour == 0)
                cost = time_price;
            else if(temp_time->tm_sec != 0||temp_time->tm_hour != 0)
                cost = time_price*(temp_time->tm_hour+1);
            else
                cost = time_price * temp_time->tm_hour;
        }
        //返回结算//

                
}
























