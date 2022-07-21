#include <iostream>
#include <istream>
#include <ostream>
#include <string>
#include<iomanip>

#pragma once

class Student{
    public:
        std::string name;
        std::string id;
        double GMP;
        Student(){
            this->name.clear();
            this->id.clear();
            this->GMP = 0;
        }
        Student(std::string &id_in,std::string &name_in,double GMP_in){
            this->id = id_in;
            this->name = name_in;
            this->GMP = GMP_in;
        }
        ~Student(){}
        friend std::ostream & operator<< (std::ostream &out,const Student &data){
            out<<data.id<<"      "<<data.name<<"       "<<data.GMP<<std::endl;
            return out;
        }
};

bool sort_GP(const Student &value_l,const Student &value_r){
    return value_l.GMP > value_r.GMP;
}
bool sort_id(const Student &value_l,const Student &value_r){
    auto strl = value_l.id.begin();
    auto strr = value_r.id.begin();
    for(;strl != value_l.id.end() && strr != value_r.id.end();strl++,strr++){
        if(*strl < *strr)
            return 1;
        else if(*strl > *strr)
            return 0;
        else
            continue;
    }
    return 1;
}
