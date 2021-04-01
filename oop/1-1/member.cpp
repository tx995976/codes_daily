#include"member.hpp"

    member::member(string a,string b,string c,double d){
        this->id = a;    
        this->password = b;
        this->name = c;
        this->money = d;
        this->status = 0;
    }

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

    void member::money_result(double a){
        this->money -= a;
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


     
     void add_money(){
         return;
     }
     void return_money(){
         return;
     }
     void count_sys(){
         return;
     }
     
     




