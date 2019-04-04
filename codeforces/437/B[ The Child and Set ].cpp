#include<cstdio>
#include<cstring>
#include<algorithm>
//by zrt
//problem:
using namespace std;
typedef long long ll;
const double eps(1e-10);
int sum,limit;
int lowbit[30];
bool vis[100050];
int stk[100050],top;
bool solve(int pos){
    if(pos<0) return false;
    int p=1<<pos,k;
    bool ok=1;
    for(int i=0;;i++){
        k=p+(i<<(pos+1));
        if(k>limit){
            ok=0;break;
        }
        if(!vis[k]){
            vis[k]=1;stk[top++]=k;
            break;
        }
        
    }
    if(ok){
        return 1;
    }else{
        if(solve(pos-1)) if(solve(pos-1)) return 1;
        return 0;
    }
}
int main(){
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    scanf("%d%d",&sum,&limit);
    for(int i=0;i<30;i++) if(sum&(1<<i)) lowbit[i]=1;
    for(int i=0;i<30;i++){
        if(lowbit[i]){
            if(!solve(i)){
                puts("-1");
                return 0;
            }
        }
    }
    printf("%d\n",top);
    for(int i=0;i<top;i++) printf("%d ",stk[i]);
    return 0;
}
