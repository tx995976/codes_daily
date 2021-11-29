#include<iostream>
#include<algorithm>
#include<cstdio>

const int max_n = 1e6+10;
int T,n,m,num_awa,pos_awa,nums[max_n],ans;

int solve(){
    std::sort(nums+1,nums+n+1);
    pos_awa = std::find(nums+1,nums+n+1,num_awa) - nums;
    if(num_awa == 1 || num_awa == m || n == 1){
        ans = 1;
        return ans;
    }
    //1.
    ans = std::min(num_awa,m-num_awa+1);
    //2. n_now == 1
    if(pos_awa == 1){
        ans = std::min(ans,m-nums[2]+1+1);
    }
    else if(pos_awa == n){
        ans = std::min(ans,nums[n-1]+1);
    }
    else{
        ans = std::min(ans,std::max(nums[pos_awa-1],m-nums[pos_awa+1]+1)+1);
    }
    //3. r-l == n_now
    int pos_r = pos_awa,pos_l = pos_awa;
    while(pos_l > 1 && nums[pos_l-1] == nums[pos_l]-1)
        pos_l--;
    while(pos_r < n && nums[pos_r+1] == nums[pos_r]+1)
        pos_r++;
    ans = std::min(ans,std::max(nums[pos_l],m-nums[pos_r]+1));
    return ans;
}

int main(){
    scanf("%d",&T);
    while(T-- > 0){
        scanf("%d %d",&n,&m);
        for(int i = 1;i <= n;i++)
            scanf("%d",&nums[i]);
        num_awa = nums[1];
        printf("%d\n",solve());    
    }

    return 0;
}