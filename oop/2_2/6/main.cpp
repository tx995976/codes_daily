#include "graph.hpp"

my_graph::AL_graph graph;

const double max_scope = 10;
const int n = 6;

void new_node(){
    my_graph::Vnode temp;
    printf("输入数据(序号,课程名称,学分):\n");
    std::cin>>temp.data.number>>temp.data.name>>temp.data.scope;
    if(!graph.new_VNode(temp)){
        printf("数据重复!\n");
        return;
    }
    return;
}

void new_road(){
    my_graph::Arcinfo temp;
    temp.weight = 0;
    printf("输入数据(from,to):\n");
    std::cin>>temp.from>>temp.to;
    if(!graph.new_ArcInfo(temp)){
        printf("数据重复!\n");
        return;
    }
    return;
}

void node_update(){
    my_graph::Vnode temp;
    std::string name;
    printf("输入数据(name):\n");
    std::cin>>name;
    if(!graph.get_node(name,temp)){
        printf("无该节点\n");
        return;
    }
    printf("找到节点:\nno:%d\nname:%s\nscope:%.1f\n",
            temp.data.number,
            temp.data.name.c_str(),
            temp.data.scope
        );
    printf("操作:\n1.删除\n2.修改\n");
    int i;
    std::cin>>i;
    switch(i){
        case 1:
            graph.delete_VNode(temp);
            break;
        case 2:
            printf("输入数据(scope):\n");
            std::cin>>temp.data.scope;
            graph.update_Vnode(temp);
            break;
        default:
            printf("无效输入\n");
            break;
    }
}

void road_update(){
    my_graph::Arcinfo temp;
    std::string from,to;
    printf("输入数据(from,to):\n");
    std::cin>>from>>to;
    if(!graph.get_arc(from,to,temp)){
        printf("无该节点\n");
        return;
    }
    printf("找到路线:\nfrom:%s\nto:%s\nweight:%d\n",
        temp.from.c_str(),
        temp.to.c_str(),
        temp.weight
    );
     printf("操作:\n1.删除\n2.修改\n");
    int i;
    std::cin>>i;
    switch(i){
        case 1:
            graph.delete_ArcInfo(temp);
            break;
        case 2:
            printf("输入数据(weight):\n");
            std::cin>>temp.weight;
            graph.update_ArcInfo(temp);
        default:
            printf("无效输入\n");
            break;
    }
}

void print_class(){
     printf("%d\t %-14s \t%.1f\n",
        graph.result.front().data.number,
        graph.result.front().data.name.c_str(),
        graph.result.front().data.scope
    );
     graph.result.erase(graph.result.begin());
}

void table_build(){
    printf("选择编制策略:\n1.均衡\n2.集中\n");
    int i,round = 1;
    std::cin>>i;
    graph.top_order();
    switch(i){
        case 1:{
            double sum = 0,average = graph.all_weight/(double)n;
            printf("f:%f\n",average);
            printf("第%d学期:\n",round++);
            while(!graph.result.empty()){
                if(sum + graph.result.front().data.scope < average){
                    sum += graph.result.front().data.scope;
                }
                else if(sum + graph.result.front().data.scope < max_scope){
                    sum = 0;
                    print_class();
                    printf("\n第%d学期:\n",round++);
                    continue;
                }
                else{
                    printf("\n第%d学期:\n",round++);
                    sum = graph.result.front().data.scope;
                }
                print_class();
            }
            if(round > 6)
                printf("未能成功编制\n");
            printf("\n");
        }
            break;
        case 2:{
            double sum = 0;
            printf("\n第%d学期:\n",round++);
            while(!graph.result.empty()){
                if(sum + graph.result.front().data.scope <= max_scope){
                    sum += graph.result.front().data.scope;
                }
                else{
                    printf("\n第%d学期:\n",round++);
                    sum = graph.result.front().data.scope;
                }
                 print_class();
            }
            if(round > 6)
                printf("未能成功编制\n");
            printf("\n");
        }
            break;
        default:
            printf("无效输入\n");
            break;
    }
    return;
}


void menu(){
    while(1){
        printf("1.添加课程\n");
        printf("2.添加修课顺序\n");
        printf("3.课程数据改动\n");
        printf("4.顺序数据改动\n");
        printf("5.生成教学计划\n");
        printf("0.退出\n");
        int i = 6;
        scanf("%d",&i);
        switch(i){
            case 1:
                new_node();
                break;
            case 2:
                new_road();
                break;
            case 3:
                node_update();
                break;
            case 4:
                road_update();
                break;
            case 5:
                table_build();
                break;
            case 0:
                return;
            default:
                printf("无效输入\n");
                break;
        }
    }
    
}

int main(){
    menu();
    return 0;
}