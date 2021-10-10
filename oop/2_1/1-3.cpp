#include<iostream>
#include<vector>

template<class t>
    class my_list{
        public:
            my_list * next = nullptr;
            t value;
            my_list();
            my_list(t t_input);
    };
template<class t>
my_list<t>::my_list(){}

template<class t>
my_list<t>::my_list(t t_input){
    this->value = t_input;
}


void list_build(my_list<int> &L){
    int temp;
    my_list<int> * list_back = &L;
    while(1){
        std::cout<<"nums: "<<std::endl;
        if(std::cin>>temp){
            my_list<int> * list_temp = new my_list<int>(temp);
            list_back->next = list_temp;
            list_back = list_temp;
        }
        else
            break;
    }
    return;
}

void list_reserve(my_list<int> &L){
    auto list_first_memebr = L.next;
    auto temp_ptr = list_first_memebr->next;
    list_first_memebr->next = nullptr;
    while(temp_ptr != nullptr){
        auto temp_ptr2 = temp_ptr->next;
        temp_ptr->next = list_first_memebr;
        list_first_memebr = temp_ptr;
        temp_ptr = temp_ptr2;
    }
    L.next = list_first_memebr;
    return;
}

int main(){
    using namespace std;
    my_list<int> L;
    list_build(L); 
    list_reserve(L);   
    auto temp = L.next;
    while(temp != nullptr){
        cout<<temp->value<<" ";
        temp = temp->next;
    }
    return 0;
}