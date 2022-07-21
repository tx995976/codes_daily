#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<set>

const int max_N = 1e6+10;
long long ans_max = 0,ans_min = 0;
std::set<int> ids,ids_;

struct int_bind_id{
    int val;
    int id;
    bool operator<(const int_bind_id &r)const{
        return val < r.val;
    }
};
int_bind_id nums[max_N];

int main(){
    int n;
    scanf(" %d",&n);
    for(int i = 1;i <= n;i++){
        scanf(" %d",&nums[i].val);
        nums[i].id = i;
    }
    std::sort(nums+1,nums+n+1);
    ids.insert(0);
    ids.insert(n+1);
    for(int i = 1;i <= n;i++){
        auto it_r = ids.upper_bound(nums[i].id);
        auto it_l = it_r; it_l--;
        ans_min += ((long long)(*it_r - nums[i].id)*(long long)(nums[i].id - *it_l)) * (long long)nums[i].val;
        ids.insert(nums[i].id);
    }
    ids_.insert(0);
    ids_.insert(n+1);
    for(int i = n;i >= 1;i--){
        auto it_r = ids_.upper_bound(nums[i].id);
        auto it_l = it_r; it_l--;
        ans_max += ((long long)(*it_r - nums[i].id)*(long long)(nums[i].id - *it_l)) * (long long)nums[i].val;
        ids_.insert(nums[i].id);
    }
    printf("%lld\n",ans_max-ans_min);
    return 0;
}