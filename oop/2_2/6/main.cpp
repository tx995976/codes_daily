#include "graph.hpp"

my_graph::AL_graph graph;

const double max_scope = 10;
const int n = 6;

void new_node(){
    my_graph::Vnode temp;
    printf("��������(���,�γ�����,ѧ��):\n");
    std::cin>>temp.data.number>>temp.data.name>>temp.data.scope;
    if(!graph.new_VNode(temp)){
        printf("�����ظ�!\n");
        return;
    }
    return;
}

void new_road(){
    my_graph::Arcinfo temp;
    temp.weight = 0;
    printf("��������(from,to):\n");
    std::cin>>temp.from>>temp.to;
    if(!graph.new_ArcInfo(temp)){
        printf("�����ظ�!\n");
        return;
    }
    return;
}

void node_update(){
    my_graph::Vnode temp;
    std::string name;
    printf("��������(name):\n");
    std::cin>>name;
    if(!graph.get_node(name,temp)){
        printf("�޸ýڵ�\n");
        return;
    }
    printf("�ҵ��ڵ�:\nno:%d\nname:%s\nscope:%.1f\n",
            temp.data.number,
            temp.data.name.c_str(),
            temp.data.scope
        );
    printf("����:\n1.ɾ��\n2.�޸�\n");
    int i;
    std::cin>>i;
    switch(i){
        case 1:
            graph.delete_VNode(temp);
            break;
        case 2:
            printf("��������(scope):\n");
            std::cin>>temp.data.scope;
            graph.update_Vnode(temp);
            break;
        default:
            printf("��Ч����\n");
            break;
    }
}

void road_update(){
    my_graph::Arcinfo temp;
    std::string from,to;
    printf("��������(from,to):\n");
    std::cin>>from>>to;
    if(!graph.get_arc(from,to,temp)){
        printf("�޸ýڵ�\n");
        return;
    }
    printf("�ҵ�·��:\nfrom:%s\nto:%s\nweight:%d\n",
        temp.from.c_str(),
        temp.to.c_str(),
        temp.weight
    );
     printf("����:\n1.ɾ��\n2.�޸�\n");
    int i;
    std::cin>>i;
    switch(i){
        case 1:
            graph.delete_ArcInfo(temp);
            break;
        case 2:
            printf("��������(weight):\n");
            std::cin>>temp.weight;
            graph.update_ArcInfo(temp);
        default:
            printf("��Ч����\n");
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
    printf("ѡ����Ʋ���:\n1.����\n2.����\n");
    int i,round = 1;
    std::cin>>i;
    graph.top_order();
    switch(i){
        case 1:{
            double sum = 0,average = graph.all_weight/(double)n;
            printf("f:%f\n",average);
            printf("��%dѧ��:\n",round++);
            while(!graph.result.empty()){
                if(sum + graph.result.front().data.scope < average){
                    sum += graph.result.front().data.scope;
                }
                else if(sum + graph.result.front().data.scope < max_scope){
                    sum = 0;
                    print_class();
                    printf("\n��%dѧ��:\n",round++);
                    continue;
                }
                else{
                    printf("\n��%dѧ��:\n",round++);
                    sum = graph.result.front().data.scope;
                }
                print_class();
            }
            if(round > 6)
                printf("δ�ܳɹ�����\n");
            printf("\n");
        }
            break;
        case 2:{
            double sum = 0;
            printf("\n��%dѧ��:\n",round++);
            while(!graph.result.empty()){
                if(sum + graph.result.front().data.scope <= max_scope){
                    sum += graph.result.front().data.scope;
                }
                else{
                    printf("\n��%dѧ��:\n",round++);
                    sum = graph.result.front().data.scope;
                }
                 print_class();
            }
            if(round > 6)
                printf("δ�ܳɹ�����\n");
            printf("\n");
        }
            break;
        default:
            printf("��Ч����\n");
            break;
    }
    return;
}


void menu(){
    while(1){
        printf("1.���ӿγ�\n");
        printf("2.�����޿�˳��\n");
        printf("3.�γ����ݸĶ�\n");
        printf("4.˳�����ݸĶ�\n");
        printf("5.���ɽ�ѧ�ƻ�\n");
        printf("0.�˳�\n");
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
                printf("��Ч����\n");
                break;
        }
    }
    
}

int main(){
    menu();
    return 0;
}

