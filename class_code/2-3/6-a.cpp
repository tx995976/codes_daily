#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>
#include<vector>
#include<fstream>
#include<unordered_map>

const int max_word = 3600;
const int w_len = 20;
const unsigned int NHASH = 3001;
const unsigned int MULT = 37;

struct hash_word{
    std::string *word;
    hash_word *next = nullptr;
    hash_word(std::string value){
        word = new std::string(value);
    }
};

std::vector<std::string> dic(max_word);//顺序表
std::unordered_map<char,std::pair<int,int>> t_search;//索引
hash_word *hash_table[NHASH]={nullptr};//哈希表

unsigned hash(std::string &str){
    unsigned int h = 0;
    for(auto it : str){
        h = h*MULT + (unsigned int)it;
    }
    return h % NHASH;
}

void step_search(std::string &key,int stat=0,int time=0){
    for(auto it : dic){
        time++;
        if(it < key)
            continue;
        else{
            if(it > key)
                break;
            else{
                stat = 1;
                break;
            }
        }
    }
    printf("%d %d\n",stat,time);
    return;
}

void binary_search(int pos_l,int pos_r,std::string &key,int stat=0,int time=0){
    while(pos_l <= pos_r){
        int mid = (pos_r + pos_l)>>1;
        time++;
        if(dic[mid] < key)
            pos_l = mid+1;
        else if(dic[mid] > key)
            pos_r = mid-1;
        else{
            stat = 1;
            break;
        }
    }
    printf("%d %d\n",stat,time);
    return;
}

void hash_search(std::string &key,int stat=0,int time=0){
    unsigned hash_v = hash(key);
    auto ptr_p = hash_table[hash_v];
    while(ptr_p != nullptr){
        time++;
        //std::cout<<*ptr_p->word<<std::endl;
        if(key > *ptr_p->word)
            ptr_p = ptr_p->next;
        else{
            if(key == *ptr_p->word){
                stat = 1;
                break;
            }
            else
                break;
        }
    }
    printf("%d %d\n",stat,time);
    return;
}

int main(){
    int pos_d = 0,pos_pre = 0;
    std::ifstream in("dictionary3000.txt",std::ios::in);
    std::string temp_s;
    char t_st = in.peek();

    while(in>>temp_s){
        dic[pos_d++] = temp_s;
        //t_search
        if(temp_s.front() != t_st){
            t_search[t_st] = {pos_pre,pos_d-1};
            pos_pre = pos_d-1;
            t_st = temp_s.front();
        }
        //hash
        unsigned pos_hash = hash(temp_s);
        if(hash_table[pos_hash] != nullptr){
            auto ptr_p = hash_table[pos_hash];
            while(ptr_p->next != nullptr)
                ptr_p = ptr_p->next;
            ptr_p->next = new hash_word(temp_s);
        }
        else
            hash_table[pos_hash] = new hash_word(temp_s);
    }
    //t_search
    t_search[t_st] = {pos_pre,pos_d};
    
    int time = 0,stat,func;
    while(std::cin>>temp_s>>func){
        switch(func){
            case 1 :    
                step_search(temp_s);
                break;
            case 2 :
                binary_search(0,pos_d-1,temp_s);
                break;
            case 3 :
                t_st = temp_s.front();
                binary_search(t_search[t_st].first,t_search[t_st].second-1,temp_s);
                break;
            case 4 :
                hash_search(temp_s);
                break;
        }
    }
    return 0;
}