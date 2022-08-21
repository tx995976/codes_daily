#  arc142
  
  
##  c. [Tree Queries](https://atcoder.jp/contests/arc142/tasks/arc142_c )
  
  
假设令<img src="https://latex.codecogs.com/gif.latex?D_{i}"/>为<img src="https://latex.codecogs.com/gif.latex?1,2"/>到<img src="https://latex.codecogs.com/gif.latex?i"/>距离之和,那么对于大部分情况<img src="https://latex.codecogs.com/gif.latex?&#x5C;min{D_{i}}"/>即为所求  
当出现<img src="https://latex.codecogs.com/gif.latex?&#x5C;min{D_{i}}%20=%203"/>时,有以下情况  

```
Error: mermaid CLI is required to be installed.
Check https://github.com/mermaid-js/mermaid-cli for more information.

Error: Command failed: npx -p @mermaid-js/mermaid-cli mmdc --theme default --input C:\Users\tx995976\AppData\Local\Temp\mume-mermaid2022714-23576-cqqqgx.4f63v.mmd --output F:\vscodes\assets\1ec1e36d7472786789e27447f97e58ba0.png
npm ERR! code ECONNRESET
npm ERR! errno ECONNRESET
npm ERR! network request to https://registry.npmjs.org/@mermaid-js%2fmermaid-cli failed, reason: read ECONNRESET
npm ERR! network This is a problem related to network connectivity.
npm ERR! network In most cases you are behind a proxy or have bad network settings.
npm ERR! network 
npm ERR! network If you are behind a proxy, please make sure that the
npm ERR! network 'proxy' config is set properly.  See: 'npm help config'

npm ERR! A complete log of this run can be found in:
npm ERR!     C:\Users\tx995976\AppData\Roaming\npm-cache\_logs\2022-08-14T05_34_48_376Z-debug.log
Install for [ '@mermaid-js/mermaid-cli@latest' ] failed with code 1

```  


```
Error: mermaid CLI is required to be installed.
Check https://github.com/mermaid-js/mermaid-cli for more information.

Error: Command failed: npx -p @mermaid-js/mermaid-cli mmdc --theme default --input C:\Users\tx995976\AppData\Local\Temp\mume-mermaid2022714-23576-1v3f2ay.uige.mmd --output F:\vscodes\assets\1ec1e36d7472786789e27447f97e58ba1.png
npm ERR! code ECONNRESET
npm ERR! errno ECONNRESET
npm ERR! network request to https://registry.npmjs.org/@mermaid-js%2fmermaid-cli failed, reason: read ECONNRESET
npm ERR! network This is a problem related to network connectivity.
npm ERR! network In most cases you are behind a proxy or have bad network settings.
npm ERR! network 
npm ERR! network If you are behind a proxy, please make sure that the
npm ERR! network 'proxy' config is set properly.  See: 'npm help config'

npm ERR! A complete log of this run can be found in:
npm ERR!     C:\Users\tx995976\AppData\Roaming\npm-cache\_logs\2022-08-14T05_36_02_723Z-debug.log
Install for [ '@mermaid-js/mermaid-cli@latest' ] failed with code 1

```  


```
Error: mermaid CLI is required to be installed.
Check https://github.com/mermaid-js/mermaid-cli for more information.

Error: Command failed: npx -p @mermaid-js/mermaid-cli mmdc --theme default --input C:\Users\tx995976\AppData\Local\Temp\mume-mermaid2022714-23576-1l9vyf9.bpvg.mmd --output F:\vscodes\assets\1ec1e36d7472786789e27447f97e58ba2.png
npm ERR! code ECONNRESET
npm ERR! errno ECONNRESET
npm ERR! network request to https://registry.npmjs.org/@mermaid-js%2fmermaid-cli failed, reason: read ECONNRESET
npm ERR! network This is a problem related to network connectivity.
npm ERR! network In most cases you are behind a proxy or have bad network settings.
npm ERR! network 
npm ERR! network If you are behind a proxy, please make sure that the
npm ERR! network 'proxy' config is set properly.  See: 'npm help config'

npm ERR! A complete log of this run can be found in:
npm ERR!     C:\Users\tx995976\AppData\Roaming\npm-cache\_logs\2022-08-14T05_37_17_037Z-debug.log
Install for [ '@mermaid-js/mermaid-cli@latest' ] failed with code 1

```  


```
Error: mermaid CLI is required to be installed.
Check https://github.com/mermaid-js/mermaid-cli for more information.

Error: Command failed: npx -p @mermaid-js/mermaid-cli mmdc --theme default --input C:\Users\tx995976\AppData\Local\Temp\mume-mermaid2022714-23576-vhcp3d.pyqcq.mmd --output F:\vscodes\assets\1ec1e36d7472786789e27447f97e58ba3.png
npm ERR! code ECONNRESET
npm ERR! errno ECONNRESET
npm ERR! network request to https://registry.npmjs.org/@mermaid-js%2fmermaid-cli failed, reason: read ECONNRESET
npm ERR! network This is a problem related to network connectivity.
npm ERR! network In most cases you are behind a proxy or have bad network settings.
npm ERR! network 
npm ERR! network If you are behind a proxy, please make sure that the
npm ERR! network 'proxy' config is set properly.  See: 'npm help config'

npm ERR! A complete log of this run can be found in:
npm ERR!     C:\Users\tx995976\AppData\Roaming\npm-cache\_logs\2022-08-14T05_38_30_258Z-debug.log
Install for [ '@mermaid-js/mermaid-cli@latest' ] failed with code 1

```  

  
在询问中记录<img src="https://latex.codecogs.com/gif.latex?D_{i}"/>的数量,当有两个点满足时再对其两点询问一次,<img src="https://latex.codecogs.com/gif.latex?D_{i,j}%20=%203|2"/>时答案为1  
仅一点满足答案也为1  
  
```cpp
int c1[3],cnt1=0;
  
int ask(int p){
    int d1,d2;
    printf("? 1 %d\n", p); fflush(stdout);
    scanf("%d", &d1);
    printf("? 2 %d\n", p); fflush(stdout);
    scanf("%d", &d2);
    if(d1+d2 == 3)
        c1[++cnt1] = p;
    return d1+d2;
}
  
int ask(int c,int d){
    int res;
    printf("? %d %d\n",c,d); fflush(stdout);
    scanf("%d", &res);
    return res;
}
  
int main(){
    int n;
    scanf("%d",&n);
    int ans = INT32_MAX;
    for(int i=3;i <= n;i++)
        ans = std::min(ans,ask(i));
  
    if(cnt1 == 1 && ans == 3)
        ans = 1;
    else if(cnt1 == 2 && ans == 3){
        int as = ask(c1[1],c1[2]);
        if(as == 2 || as == 3)
            ans = 1;
        else
            ans = 3;
    }
    printf("! %d\n", ans);fflush(stdout);
    return 0;
}
```
  
[记录](https://atcoder.jp/contests/arc143/submissions/me?f.Task=&f.LanguageName=&f.Status=&f.User=tx995976 )
  