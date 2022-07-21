#include "graph.hpp"
#include <iostream>
#include <algorithm>
#include <cstdio>

my_graph::non_dgraph graph;

void city_add(){
    my_graph::Vex temp;
    printf("输入城市序号(整数) 和城市名称:\n");
    std::cin>>temp.code>>temp.name;
    if(!graph.insert_vex(temp)){
        printf("已存在相同的节点\n");
    }
    return;
}

void road_add(){
    int c1,c2,c3;
    my_graph::Vex v1,v2;
    printf("输入城市号和值(code1,code2,length):\n");

    std::cin>>c1>>c2>>c3;
    v1 = graph.get_vex(c1);
    v2 = graph.get_vex(c2);
    my_graph::Edge temp(v1,v2,c3);

    if(!graph.insert_edge(temp)){
        printf("已存在相同的路线\n");
    }
    return;
}

void city_update(){
    int code;
    printf("输入城市编号:\n");
    std::cin>>code;
    my_graph::Vex temp;
    temp = graph.get_vex(code);
    if(temp.code != code){
        printf("无该城市\n");
        return;
    }
    printf("找到数据:\ncode:%d\nname:%s\n",temp.code,temp.name.c_str());
    printf("输入选项:\n1.删除\n2.修改\n");
    std::cin>>code;
    switch(code){
        case 1:
            graph.delete_vex(temp);
            break;
        case 2 :
            printf("输入新数据(name):\n");
            std::cin>>temp.name;
            graph.update_vex(temp);
            break;
        default:
            printf("无效输入\n");
            break;
    }
}

void road_update(){
    int c1,c2;
    printf("输入城市编号(code1,code2):\n");
    std::cin>>c1>>c2;
    my_graph::Edge temp = graph.get_edge(c1,c2);
    if(temp.vex1.code != c1 || temp.vex2.code != c2){
        printf("无该路线\n");
        return;
    }

    printf("找到数据:\ncode:%d name:%s\ncode:%d name:%s\nlength:%d\n",
            temp.vex1.code,
            temp.vex1.name.c_str(),
            temp.vex2.code,
            temp.vex2.name.c_str(),
            temp.length
        );
    printf("输入选项:\n1.删除\n2.修改\n");
    std::cin>>c1;
    switch(c1){
        case 1:
            graph.delete_edge(temp);
            break;
        case 2 :
            printf("输入新数据(length):\n");
            std::cin>>temp.length;
            graph.update_edge(temp);
            break;
        default:
            printf("无效输入\n");
            break;
    }
}

void build_net(){
    int i;
    printf("选择建立方法\n1.prim算法\n2.kruskal算法\n:");
    std::cin>>i;
    switch(i){
        case 1:
            graph.print_prim();
            break;
        case 2:
            graph.print_kruskal();
            break;
        default:
            printf("无效输入\n");
            break;
    }
}


void menu(){
    while(1){
        printf("1.添加城市\n");
        printf("2.添加路线\n");
        printf("3.城市数据改动\n");
        printf("4.路线数据改动\n");
        printf("5.建立联络网\n");
        printf("0.退出\n");
        int i = 6;
        scanf("%d",&i);
        switch(i){
            case 1:
                city_add();
                break;
            case 2:
                road_add();
                break;
            case 3:
                city_update();
                break;
            case 4:
                road_update();
                break;
            case 5:
                build_net();
                break;
            case 0:
                return;
            default:
                break;
        }
    }
    
}

int main(){
    menu();
    return 0;
}