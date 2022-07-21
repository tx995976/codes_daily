#include<bits/stdc++.h>
using namespace std;

namespace tree{
    const int node = 101000;
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
}

int main(){
    int k;      
    cin>>k;          
    cout<<k/2<<endl;
    return 0;
}
