#include<iostream>

class my_list{
    public:
        int value;
        my_list * next;
        my_list();
        my_list(int input){
            this->value = input;
        }
};

my_list * list_build(){
    auto L = new my_list(1);
    int temp;
    my_list * list_temp = L;
    my_list * list_temp2 = nullptr;
    while(1){
        std::cout<<"nums: "<<std::endl;
        if(std::cin>>temp){
            list_temp2 = new my_list(temp);
            list_temp->next = list_temp2;
            list_temp = list_temp2;
        }
        else{
            list_temp2->next = L;
            break;
        }
    }
    return L;
}

void list_delete(my_list * P){
    auto temp_ptr = P;
    auto temp_ptr2 = temp_ptr->next;
    while(temp_ptr2->next != P){
        temp_ptr2 = temp_ptr2->next;
        temp_ptr = temp_ptr->next;
    }
    temp_ptr->next = P;
    delete(temp_ptr2);
    return;
}

int main(){
    using namespace std;
    auto L = list_build(); 
    list_delete(L);   

    auto temp_ptr = L->next;
    cout<<L->value<<" ";
    while(temp_ptr != L){
        cout<<temp_ptr->value<<" ";
        temp_ptr = temp_ptr->next;
    } 
    cout<<endl;

    return 0;
}