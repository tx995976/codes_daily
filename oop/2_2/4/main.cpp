#include "tree.hpp"
#include <iostream>

my_tree::Btree<std::string> name_tree;

void tree_init(){
    std::cout<<" ";
    std::string str_input;
    std::cin>>str_input;
    name_tree.setting_up(str_input);
}

void menu(){
    int i = 0;
    while(1){
        std::cout<<" "
                <<" "
                <<" ";
        std::cin>>i;
        switch(i){
            case 1:
                tree_init();
                break;
            case 2:
                name_tree.post_order_re(name_tree.get_node());
                break;
            case 3:
                name_tree.pre_order();
                break;
            default:
                std::cout<<" ";
                return;
        }
    }
}

int main(){
    menu();
    return 0;
}
