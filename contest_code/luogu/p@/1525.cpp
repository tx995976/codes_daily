#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;
const int node_int = 101000;
int n,m;
int node_tree[node_int],node_enemy[node_int];

struct node{
    int num;
    int num1;
    int score;
    bool operator < (const node other) {
        return this->score > other.score;
    } 
}   node_num[node_int];

int node_find(int num){
    if(node_tree[num] == num)
        return num;
    node_tree[num] = node_find(node_tree[num]);
    return node_tree[num];
}

void node_add(int num,int num1){
    num = node_find(num);
    num1 = node_find(num1);
    node_tree[num] = num1;
}

bool node_check(int num,int num1){
    if(node_find(num) == node_find(num1))
        return 1;
    else
        return 0;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i = 1;i <= m;i++)
        cin>>node_num[i].num>>node_num[i].num1>>node_num[i].score;
    sort(node_num+1,node_num+1+m);
    for(int i = 1;i <= n;i++)
        node_tree[i] = i;           //初始化
    for(int i = 1;i <= m+1;i++){
        if(node_check(node_num[i].num,node_num[i].num1)){
            cout<<node_num[i].score;
            break;
        }           
        else{                   //node_enemy互相标记为敌人
            if(!node_enemy[node_num[i].num])
                node_enemy[node_num[i].num] = node_num[i].num1;
            else
                node_add(node_enemy[node_num[i].num],node_num[i].num1);

            if(!node_enemy[node_num[i].num1])
                node_enemy[node_num[i].num1] = node_num[i].num;
            else
                node_add(node_enemy[node_num[i].num1],node_num[i].num);
        }
    }
    return 0;
}