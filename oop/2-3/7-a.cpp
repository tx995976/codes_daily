#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>

int array[110],size_arr,func,cnt;
int temp[110];

void sort_sele(){
    cnt = 0;
    for(int i = 0;i < size_arr-1;i++){
        int pos = i;
        for(int j = i+1;j < size_arr;j++){
            if(array[j] < array[pos])
                pos = j;
            cnt++;
        }
        std::swap(array[pos],array[i]);
    }
}

void sort_bub(){
    cnt = 0;
    bool flag = 0;
        for(int i = size_arr-1; i > 0;i--){
            flag = 0;
            for(int j = 0;j < i;j++){
                cnt++;
                if(array[j] > array[j+1]){
                    flag = 1;
                    std::swap(array[j],array[j+1]);
                }
            }
            if(!flag)
                break;
        }
}

void head_down(int st,int ed){
    int father = st;
    int root = array[father];
    int child = father * 2 + 1;
    while(child <= ed){
        if(child+1 < ed && array[child] < array[child+1])
            child++;
        cnt++;
        if(root >= array[child])
            break;
        else{
            array[father] = array[child];
            father = child;
            child = child * 2 + 1;
        }
    }
    array[father] = root;
}
void sort_heap(){
    cnt = 0;   
    for(int i = (size_arr-2)/2 ;i >= 0;i--)
        head_down(i,size_arr-1);
    for(int i = size_arr-1;i > 0;i--){
        std::swap(array[0],array[i]);
        head_down(0,i-1);
    }
}

void sort_merge(int l ,int r){
    if (r - l < 1) 
        return;
    int mid = l + ((r - l) >> 1);
    sort_merge(l, mid);
    sort_merge(mid+1, r);

    int ls = l , rs = mid+1, t_s = l;
    while(ls <= mid && rs <= r){
        cnt++;
        if(array[ls] <= array[rs])
            temp[t_s++] = array[ls++];
        else
            temp[t_s++] = array[rs++];
    }
    while(ls <= mid)
        temp[t_s++] = array[ls++];
    while(rs <= r)
            temp[t_s++] = array[rs++];
    for(int i = l; i <= r; i++)
        array[i] = temp[i];
}

void sort_fast(int l,int r){
    int last;
    if(l < r){
        last = l;
        for(int i = l+1;i <= r;i++){
            cnt++;
            if(array[i] < array[l])
                std::swap(array[++last],array[i]);
        }
            std::swap(array[l],array[last]);
            sort_fast(l,last-1);
            sort_fast(last+1,r);
    }
}

void print_ans(){
    for(int i = 0;i < size_arr;i++)
        printf("%d%c",array[i],i < size_arr-1 ? ' ' : '\n');
    printf("%d\n",cnt);
}

int main(){
    scanf(" %d %d",&size_arr,&func);
    for(int i = 0;i < size_arr;i++)
        scanf(" %d",&array[i]);
    switch(func){
        case  1:
            sort_sele();
            break;
        case  2:
            sort_bub();
            break;
        case  3:
            sort_heap();
            break;
        case  4:
            cnt = 0;
            sort_merge(0,size_arr-1);
            break;
        case  5:
            cnt = 0;
            sort_fast(0,size_arr-1);
            break;
    }
    print_ans();
    return 0;
}