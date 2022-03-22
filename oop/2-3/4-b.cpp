#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>

// 0-l 1-r
class tree{
    public:
        char *value = nullptr;
        tree *l_c = nullptr,*r_c = nullptr;
        int cnt = 0;
    tree(){}
    ~tree(){
        delete value;
        delete l_c,r_c;
    }
};

tree root;
std::string encode,ans;    

void build(std::string &enc,char temp){
    auto r = &root;
    for(auto it : enc){
        auto next = it == '0' ? r->l_c : r->r_c;
        if(next == nullptr)
            next = new tree();
        r = it == '0' ? r->l_c=next : r->r_c=next;
    }
    r->value = new char(temp);
}

void get_cnt(tree *now){
    if(now->r_c != nullptr)
        get_cnt(now->r_c);
    if(now->l_c != nullptr)
        get_cnt(now->l_c);
    printf("%d ",now->cnt);
}

int main(){
    int n;
    char temp;
    scanf(" %d",&n);
    while(n--){
        scanf(" %c:",&temp);
        std::cin>>encode;
        build(encode,temp);
    }

    //freopen("in.txt","r",stdin);
    auto now = &root;
    root.cnt++;
    while(~scanf(" %c",&temp)){
        now = temp == '0' ? now->l_c : now->r_c;
        if(now != nullptr && now->value != nullptr){
            ans.push_back(*now->value);
            now->cnt++;
            now = &root;
        }
        now->cnt++;
    }
    printf("%s\n",ans.c_str());
    get_cnt(&root);

    return 0;
}