#include<iostream>
#include<fstream>
#include<algorithm>
#include<time.h>
#include<vector>
#include<map>
using namespace std;
    class member{
            string id;
            string password;
            string name;
            double money;
        public:
            bool match_password(string password_in);
            void money_add(double a);
            void new_card(string a,string b,string c,double d);
            void money_refund();
            string show_id();
            string show_password();
            string show_name();
            double show_money();

    };
    //
    extern bool login();
    //
    extern void add_card();         
    extern void query_card();
    extern void start_up();
    extern void shut_down();
    extern void add_money();
    extern void return_money();
    extern void count_sys();
    extern void delete_card();
    //
    extern void data_read();
    extern void data_write();
    //



































