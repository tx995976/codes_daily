#include<iostream>
#include<string>
#include<chrono>
#include<fstream>
#include<sstream>
#include<map>
#include<vector>
#include<iomanip>
#include<algorithm>

using namespace std;

class info_member{
    public:
        string id = "non";
        string name = "non";
        time_t card_start = 0;
        time_t card_end = 0;
        double money_all = 0;
        bool status = 1;
    public:
        info_member(){}
        ~info_member(){}        
        void show();
};

class info_cost {
    public:
    time_t online = 0;
    time_t offline = 0;
    double cost = 0;
    public:
    void show();
    
};

class info_money_add{
    public:
    time_t time = 0;
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

class total_income{
    protected:
        time_t time;
        double income;
    public:
        ~total_income(){}        
        total_income(){}
        void income_add(double money){
            this->income += money;
        }
    friend void income_data_load();
    friend void admin_search_month();
    friend void admin_search_timepoint();
};

/////////////////////////////////////////////
extern void income_data_write(time_t time,double income);
extern void map_load();
extern void map_write();
extern void user_load();
extern void income_data_load();
///////////////////////////////////////////////
extern void user_info_member_load();
extern void user_new_member(string id,string name);
extern void user_info_cost_load();
extern void user_info_member_write();
extern void user_info_cost_write();
extern void user_info_money_add_load();
extern void user_info_money_add_write();
extern void user_logout();
//////////////////////////////////////////
extern void record_online(time_t time);
extern void record_add_money(time_t time,double money);
extern void send_Key(string id);
extern double record_offline(time_t time);
extern double once_cost();
//////////////////////////////////////////////////////
extern void user_info_welcome();
extern void user_record_cost();
extern void user_card_info();
extern void user_info_add_money();
extern void user_card_remove();
///////////////////////////////////////////////////////
extern void admin_info_welcome();
extern void admin_search_id();
extern void admin_search_non();
extern void admin_list_users();
extern void admin_view_user();
extern void admin_total_money();
extern void admin_search_month();
extern void admin_search_timepoint();
//////////////////////////////////////////////////////
