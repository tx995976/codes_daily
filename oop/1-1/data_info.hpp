#include<iostream>
#include<string>
#include<chrono>
#include<fstream>
#include<map>
#include<vector>

using namespace std;

class info_member{
    public:
    time_t card_start;
    time_t card_end;
    double money_all;
    int item_use;
};

class info_cost{
    public:
    string id;
    time_t online;
    time_t offline;
    string type;
    double cost;
    bool paid_if;
};


class info_online{
    public:
    string id;
    time_t member_online;
};

class info_offline{
    public:
    string id;
    time_t member_offline;
};

class info_money_add{
    public:
    string id;
    double add_money;
    string way_paid;
};

class all_member_info{
    public:
    info_member member;
    vector<info_cost> cost;
    vector<info_online> online;
    vector<info_offline> offline;
    vector<info_money_add> money_add;
};

extern void record_offline(time_t time);
extern void record_online(time_t time);
extern void once_cost();
extern void send_Key(string id);














