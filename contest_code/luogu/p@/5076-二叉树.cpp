#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#pragma gcc optimize(2)
using namespace std;

const int node = 5e5+10;
class node_tree{
    public:
    int num,r_num,l_num,value,sum;
}tree[node];
int total_node;

void func_tree_add(int x,int i){
    tree[x].sum++;
    if(tree[x].num == i){
        tree[x].value++;
        return;
    }
    if(tree[x].num > i){
        if(tree[x].l_num != 0)
            func_tree_add(tree[x].l_num,i);
        else{
            total_node++;
            tree[total_node].num = i;
            tree[total_node].sum = tree[total_node].value = 1;
            tree[x].l_num = total_node;
        }
    }
    else{
        if(tree[x].r_num != 0)
            func_tree_add(tree[x].r_num,i);
        else{
            total_node++;
            tree[total_node].num = i;
            tree[total_node].value = tree[total_node].sum = 1;
            tree[x].r_num = total_node;
        }
    }
}

int func_tree_rank(int i,int x){
    if(i == 0)
        return 0;
    if(x == tree[i].num)
        return tree[tree[i].l_num].sum;
    if(x < tree[i].num)
        return func_tree_rank(tree[i].l_num,x);
    //else
    return func_tree_rank(tree[i].r_num,x)+tree[tree[i].l_num].sum+tree[i].value;
    //tree[tree[i].l_num].sum仅在节点1取得左树sum,其余取得0;
}

int func_tree_find(int i,int key){
    if(i == 0)
        return INT32_MAX;
    if(tree[tree[i].l_num].sum >= key)
        return func_tree_find(tree[i].l_num,key);
    if(tree[tree[i].l_num].sum+tree[i].value >= key)
        return tree[i].num;
    //else
    return func_tree_find(tree[i].r_num,key-tree[tree[i].l_num].sum-tree[i].value);
    //tree[tree[i].l_num].sum仅在节点1取得左树sum,其余取得0;
}

int func_tree_find_front(int i,int x,int ans){
    //无值情况
    if(tree[i].num >= x)
        if(tree[i].l_num == 0)
            return ans;
        else
            return func_tree_find_front(tree[i].l_num,x,ans);
    //极限逼近
    else{
        if(tree[i].r_num == 0)
            return tree[i].num > x ? ans : tree[i].num;
        if(tree[i].sum != 0)
            return func_tree_find_front(tree[i].r_num,x,tree[i].num);
        else
            return func_tree_find_front(tree[i].r_num,x,ans);
    }
}

int func_tree_find_back(int i,int x,int ans){
    //无值情况
    if(tree[i].num <= x)
        if(tree[i].r_num == 0)
            return ans;
        else
            return func_tree_find_back(tree[i].r_num,x,ans);
    //极限逼近
    else{
        if(tree[i].l_num == 0)
            return tree[i].num > x ? tree[i].num : ans;
        if(tree[i].sum != 0)
            return func_tree_find_back(tree[i].l_num,x,tree[i].num);
        else
            return func_tree_find_back(tree[i].l_num,x,ans);
    }
}

/*void func_tree_delete(int i,int x){
    if(tree[i].num == x){
        tree[i].value--;
        return;
    }
    if(tree[i].num < x)
        func_tree_delete(tree[i].r_num,x);
    else
        func_tree_delete(tree[i].l_num,x);
}*/

int main(){
    int k,n,x;
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>k;
    while(k--){
        cin>>n>>x;
        switch(n){
        case 1:
            cout<<func_tree_rank(1,x)+1<<endl;
            break;
        case 2:
            cout<<func_tree_find(1,x)<<endl;
            break;
        case 3:
            cout<<func_tree_find_front(1,x,INT32_MIN)<<endl;
            break;
        case 4:
            cout<<func_tree_find_back(1,x,INT32_MAX)<<endl;
            break;
        case 5:
            //第一值插入
            if(total_node == 0){
                total_node++;
                tree[total_node].value = tree[total_node].sum = 1;
                tree[total_node].num = x;
                break;
            }
            func_tree_add(1,x);
            break;
        }
    }   
    return 0;
}