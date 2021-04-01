#include"data_info.hpp"

map<string,all_member_info> data_info;
using itor_info = map<string,all_member_info>::iterator;

itor_info user;
string id;
const double time_price = 5;



///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

void send_key(string id){
    user = data_info.find(id);
    ::id = id;
}

void record_online(time_t time){
    info_online temp;
    temp.id = ::id;
    temp.member_online = time;
    user->second.online.push_back(temp);
    return;
}   
void record_offline(time_t time){
    info_offline temp;
    temp.id = ::id;
    temp.member_offline = time;
    user->second.offline.push_back(temp);
    
    once_cost();
}

void once_cost(){
    info_cost temp;
    temp.id = ::id;
    double cost;
    info_online online_time = user->second.online.back();
    info_offline offline_time = user->second.offline.back(); 
    //////////  23-6为包夜时间 15元 ///////////////////////////////
    tm *online = localtime(&online_time.member_online),
        *offline = localtime(&offline_time.member_offline);
    ////////////////////////////////////////////////////////////
    ///////////////默认不超过一天/////////////////////////////////
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
                cost = 15+(23 - online->tm_hour)*time_price;
        }
        else if(online->tm_hour < 23 &&  offline->tm_hour > 6){
            if(offline->tm_min == 0&&offline->tm_sec == 0)
                    cost = 15 + (offline->tm_hour - 6)*time_price+(23 - online->tm_hour)*time_price;
                else
                    cost = 15 +(offline->tm_hour - 5)*time_price+(23 - online->tm_hour)*time_price;
        }
        else{

        }
            




        
}
























