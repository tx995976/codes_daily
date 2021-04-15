#include<iostream>
#include<string>
#include<chrono>
#include<fstream>
#include<map>
#include<vector>

using namespace std;

class info_member{
    public:
        string id;
        string name;
        time_t card_start;
        time_t card_end;
        double money_all;
        bool status;
    public:
        info_member(){}
        ~info_member(){}        
        void show();
};

class info_cost {
    public:
    time_t online;
    time_t offline;
    double cost;
    public:
    void show_online();
    void show_offline();
};

class info_money_add{
    public:
    time_t time;
    double add_money;
    void show();
};

class all_member_info{
    public:
        all_member_info(){}
        ~all_member_info(){}        
        info_member member;
        vector<info_cost> cost;
        vector<info_money_add> money_add;

};
/////////////////////////////////////////////
extern void map_load();
extern void map_write();
///////////////////////////////////////////////
extern void user_info_member_load();
extern void user_info_cost_load();
extern void user_info_money_add_load();
extern void user_info_member_write();
extern void user_info_cost_write();
extern void user_info_money_add_write();
//////////////////////////////////////////
extern void record_online(time_t time);
extern double record_offline(time_t time);
extern void record_add_money(time_t time,double money);
extern double once_cost();
extern void send_Key(string id);
//////////////////////////////////////////////////////
extern void user_info_welcome();
extern void user_record_online();
extern void user_record_offline();
extern void user_card_info();
extern void user_record_cost();
///////////////////////////////////////////////////////
extern void admin_info_welcome();
extern void admin_search_id();
extern void admin_search_non();
extern void admin_list_users();
extern void admin_delete_card();
//////////////////////////////////////////////////////






