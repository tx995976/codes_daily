#include<iostream>
#include<fstream>
#include<algorithm>
#include<chrono>
#include<vector>
#include<map>
#include<string>
#include<iomanip>

#ifndef member_hpp

using namespace std;

        class member{
            public:
                int status = 0;
            private:
                string id;
                string password;
                string name;
                double money;
            public:
                member(){}
                member(string a,string b,string c,double d);
                ~member(){}
                bool match_password(string password_in);
                void money_add(double a);
                void money_result(double a);
                void new_card(string a,string b,string c,double d);
                string show_id();
                string show_password();
                string show_name();
                double show_money();
                void cost_money(double cost);

                friend void user_data_read();
                friend void user_data_write();
        };

    //
    extern void login();
    extern void logout();
    extern void welcome();
    //
    extern void add_card();         
    extern void query_card();
    extern void start_up();
    extern void shut_down();
    extern void add_money();
    extern void return_money();
    extern void count_sys();
    extern bool delete_card();
    //
    extern void user_data_read();
    extern void user_data_write();
    //

#endif
































