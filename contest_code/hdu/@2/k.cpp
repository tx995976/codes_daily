#include<cstdio>
#include<algorithm>
#include<deque>
#include<string>
#include<vector>

using ll = long long;

const int max_n = 1e5+10;
int n,m,arr[max_n];


struct node{
    int len;
    //  bt_max,max,
    //  max_pair1,max_pair2,
    //  psum_max,psub_max,
    //  bt_min,min;
    ll  max[6],min[2];
    node (int i = 0){
        len = i;
        for(ll &it : max)
            it = INT64_MIN;
        for(ll &it : min)
            it = INT64_MAX;
    }
    void u_max (ll a){
        if(a > max[0])
            max[1] = max[0],max[0] = a;
        else if(a > max[1])
            max[1] = a;
    }
    void u_min (ll a){
        if(a < min[0])
            min[1] = min[0],min[0] = a;
        else if(a < min[1])
            min[1] = a;
    }
    node operator + (const node &r)const{
        if(len == 0)
            return r;
        if(r.len == 0)
            return *this;

        node temp(len + r.len);

        for(int i = 0; i < 2;i++){
            temp.u_max(max[i]);
            temp.u_min(min[i]);
            temp.u_max(r.max[i]);
            temp.u_min(r.min[i]);
        }

        temp.max[2] = std::max(temp.max[2],max[2]);
        temp.max[2] = std::max(temp.max[2],r.max[2]);
        temp.max[2] = std::max(temp.max[2],max[0]-r.min[0]);

        temp.max[3] = std::max(temp.max[3],max[3]);
        temp.max[3] = std::max(temp.max[3],r.max[3]);
        temp.max[3] = std::max(temp.max[3],max[2]+r.max[2]);
        temp.max[3] = std::max(temp.max[3],max[0]+max[1]-r.min[0]-r.min[1]);
        temp.max[3] = std::max(temp.max[3],max[4]-r.min[0]);
        temp.max[3] = std::max(temp.max[3],max[0]+r.max[4]);

        temp.max[4] = std::max(temp.max[4],max[4]);
        temp.max[4] = std::max(temp.max[4],r.max[4]);
        temp.max[4] = std::max(temp.max[4],max[2]+r.max[0]);
        temp.max[4] = std::max(temp.max[4],r.max[2]+max[0]);
        if(r.len >= 2)
            temp.max[4] = std::max(temp.max[4],max[0]-r.min[0]+r.max[0]);
        if(len >= 2)
            temp.max[4] = std::max(temp.max[4],max[0]-r.min[0]+max[1]);

        temp.max[5] = std::max(temp.max[5],max[5]);
        temp.max[5] = std::max(temp.max[5],r.max[5]);
        temp.max[5] = std::max(temp.max[5],max[2]-r.min[0]);
        temp.max[5] = std::max(temp.max[5],r.max[2]-min[0]);
        if(r.len >= 2)
            temp.max[5] = std::max(temp.max[5],max[0]-r.min[0]-r.min[1]);
        if(len >= 2)
            temp.max[5] = std::max(temp.max[5],max[0]-r.min[0]-min[0]);
        return temp;
    }
};

node tree[max_n << 2];

void build(int l = 1,int r = n,int tp = 1){
    if(l == r){
        tree[tp] = node(1);
        tree[tp].max[0] = tree[tp].min[0] = 1ll*arr[l]*arr[l];
        return;
    }
    int mid = (l+r) >> 1;
    build(l,mid,tp<<1);
    build(mid+1,r,(tp<<1)|1);
    tree[tp] = tree[tp<<1]+tree[tp<<1|1];
}

node query(int l,int r,int tl = 1,int tr = n,int tp = 1){
    if(tl > r || tr < l)
        return node(0);
    if(tl >= l && tr <= r)
        return tree[tp];
    int mid = l + r >> 1;
    return query(l,r,tl,mid,tp<<1)+query(l,r,mid+1,tr,tp<<1|1);
}


int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        for(int i = 1; i <= n; i++)
            scanf("%d",&arr[i]);
        build();
        int ql,qr;
        for(int i = 1;i <= m;i++){
            scanf("%d %d",&ql,&qr);
            printf("%lld\n",query(ql,qr).max[3]);
        }
    }
    return 0;
}