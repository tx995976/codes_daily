# ABC_237

## D LR insertion
要求将**i**插入在**i-1**的**L** 或 **R**  
将插入位置输入后,直接模拟即可操作  
使用std::list::emplace来防止迭代器非法化  
```cpp
const int max_n = 5e5+10;
std::list<int> nums;
bool pos[max_n];

int main(){
    int n;
    char temp;
    scanf(" %d",&n);
    for(int i = 1;i <= n;i++){
        scanf(" %c",&temp);
        pos[i] = temp == 'L' ? 0 : 1;
    }
    nums.push_back(0);
    auto it = nums.begin();
    for(int i = 1;i <= n;i++){
        if(pos[i]){
            it++;
            nums.emplace(it,i);
            it--;
        }
        else{
            nums.emplace(it,i);
            it--;
        }
    }
    for(auto it : nums)
        printf("%d ",it);
    printf("\n");
    return 0;
}
```