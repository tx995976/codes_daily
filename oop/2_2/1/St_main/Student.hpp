#pragma once
#include <iostream>
#include <istream>
#include <ostream>
#include <string>
#include<iomanip>


class Student{
    protected:
        std::string name;
        std::string id;
        double GMP;
    public:
        Student(){
            this->name.clear();
            this->id.clear();
            this->GMP = 0;
        }
        Student(std::string &name_in,std::string &id_in,double GMP_in){
            this->name = name_in;
            this->id = id_in;
            this->GMP = GMP_in;
        }
        ~Student();
        bool operator > (const Student &value_r) const{
            if(this->GMP != value_r.GMP)
                return this->GMP > value_r.GMP;
            else
                return this->name > value_r.name;;
        }
        bool sort_id(const Student &value_l,const Student &value_r){
            


        }


        bool operator << (std::ostream &out){
            if(this->id.empty()){
                std::cerr<<"no data"<<std::endl;
                return 0;
            }
             out<<this->id<<" "<<std::setw(6)<<this->name<<std::setw(6)<<this->GMP<<std::endl;
             return 1;
        }

        bool is_match(std::string input){
            if(this->name == input)
                return 1;
            else if(this->id == input)
                return 1;
            else
                return 0;
        }




};
