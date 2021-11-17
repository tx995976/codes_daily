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
    std::string child;
    int i = 0;
    while(1){
        std::cout<<"1.建立家谱树\n"
                 <<"2.后序遍历\n"
                 <<"3.前序遍历\n"
                 <<"4.寻找长辈\n"
                 <<"5.销毁树\n"
                 <<"0.退出\n";
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
            case 4:
                std::cin>>child;
                name_tree.find_ancestor(child);
                break;
            case 5:
                name_tree.clear(name_tree.get_node());
                break;
            default:
                std::cout<<"非法输入";
                return;
        }
    }
}

int main(){
    menu();
    return 0;
}
