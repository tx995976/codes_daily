#include<time.h>
#include<iostream>
#include<string>

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
    double cost;
    bool paid_it;
};


class info_online{
    public:
    string id;
    time_t member_online;
    int id_seat;
};

class info_offline{
    public:
    string id;
    time_t member_offline;
    int id_seat;
};

class info_money_add{
    public:
    string id;
    double add_money;
    string way_paid;
};

