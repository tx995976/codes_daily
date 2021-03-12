#include"test.hpp"

    bool member:: match_password(string password_in){
        if(this->password == password_in)
            return 1;
        else
            return 0;
    }

    void member:: money_add(double a){
        this->money += a;
        return;
    }

    void member:: new_card(string a,string b,string c,double d){
        this->id = a;
        this->password = b;
        this->name = c;
        this->money = d;
        return;
    }
    
    void member:: money_refund(){
        return;
    }

    string member:: show_id(){
        return this->id;
    }

    string member:: show_password(){
        return this->password;
    }

    double member:: show_money(){
        return this->money;
    }

    string member:: show_name(){
        return this->name;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

     void add_card(){

         return;
     }
     void query_card(){
         return;
     }
     void start_up(){
         return;
     }
     void shut_down(){
         return;
     }
     void add_money(){
         return;
     }
     void return_money(){
         return;
     }
     void count_sys(){
         return;
     }
     void delete_card(){
         return;
     }
     




