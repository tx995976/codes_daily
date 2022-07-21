#include<iostream>
#include<fstream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>

class TNode{
        public:
            std::string *data = nullptr;
            TNode *l_node = nullptr,*r_node = nullptr,*pat=nullptr;
            int deep = 0;
        public:
            ~TNode(){}
            TNode(){}
            TNode(std::string in,int d,TNode *pa){
                data = new std::string(in);
                deep = d;
                pat = pa;
            }
    };

const std::string null_c = "NULL";

TNode root,*c_r,*l,*r;
std::string rot,lc,rc;
std::deque<TNode*> ptr;

void build(){
    //根节点构造
    if(ptr.empty()){
        root.data = new std::string(rot);
        if(lc != null_c){
            root.l_node = new TNode(lc,root.deep+1,&root);
            ptr.push_back(root.l_node);
        }
        if(rc != null_c){
            root.r_node = new TNode(rc,root.deep+1,&root);
            ptr.push_back(root.r_node);
        }
        return;
    }
    //
    while(*ptr.front()->data != rot)
        ptr.pop_front();
    //
    c_r = ptr.front();
    ptr.pop_front();
    
    if(lc != null_c){
        c_r->l_node = new TNode(lc,c_r->deep+1,c_r);
        ptr.push_back(c_r->l_node);
    }
    if(rc != null_c){
        c_r->r_node = new TNode(rc,c_r->deep+1,c_r);
        ptr.push_back(c_r->r_node);
    }
}

TNode* get_pat(TNode *n1,TNode *n2){
    while(n1 != n2){
        n1 = n1->pat;
        n2 = n2->pat;
    }
    return n1;
}

void search(std::string q1,std::string q2){
    std::deque<TNode*> que;
    que.push_back(&root);

    bool find_1 = 1,find_2 = 1;
    TNode *n1 = nullptr,*n2 = nullptr;
    //bfs
    while(!que.empty() &&(find_1 || find_2)){
        auto it = que.front();
        que.pop_front();

        if(find_1 && *it->data == q1){
            find_1 = 0;
            n1 = it;
        }
        else if(find_2 && *it->data == q2){
            find_2 = 0;
            n2 = it;
        }
        if(it->l_node != nullptr)
            que.push_back(it->l_node);
        if(it->r_node != nullptr)
            que.push_back(it->r_node);
    }
    //
    if(n1->deep != n2->deep){
        if(n1->deep < n2->deep)
            std::swap(n1,n2);
        printf("%s %s %d\n",n1->data->c_str(),n2->data->c_str(),n1->deep-n2->deep);
    }
    else{
        TNode *pa = get_pat(n1,n2);
        printf("%s %s %d\n",pa->data->c_str(),n1->data->c_str(),n1->deep-pa->deep);
        printf("%s %s %d\n",pa->data->c_str(),n2->data->c_str(),n2->deep-pa->deep);
    }
}

int main(){
    int n;
    std::ifstream in;
    in.open("in.txt",std::ios::in);
    in>>n;
    for(int i = 1;i <= n;i++){
        in>>rot>>lc>>rc;
        build();
    }
    std::string quey1,quey2;
    std::cin>>quey1>>quey2;
    search(quey1,quey2);
    return 0;
}