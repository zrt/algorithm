#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
int n,load[50005],h[50005];
int stk[50005];int top;
int m[50005];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&h[i],&load[i]);
    }
    for(int i=1;i<=n;i++){
        while(top>0&&h[stk[top-1]]<h[i]){
            m[i]+=load[stk[top-1]];
            top--;
        }
        if(top) m[stk[top-1]]+=load[i];
        stk[top++]=i;
    }
    int maxx=0;
    for(int i=1;i<=n;i++) maxx=max(maxx,m[i]);
    printf("%d\n",maxx);
    return 0;
}
