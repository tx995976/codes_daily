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
        
        bool operator > (const Student &value_r) const{
            if(this->GMP != value_r.GMP)
                return this->GMP > value_r.GMP;
            else
                return this->name > value_r.name;;
        }

        bool sort_id(const Student &value_l,const Student &value_r){
                    

            return 1;
        }


        friend std::ostream & operator<< (std::ostream &out,const Student &data){
            out<<data.id<<"      "<<data.name<<"       "<<data.GMP<<std::endl;
            return out;
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
