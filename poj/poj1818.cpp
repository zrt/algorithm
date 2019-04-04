#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,k;
bool vis[5005];
int tot;
int a[5005];
bool judge(int x){
    memset(vis,0,sizeof vis);
    tot=0;
    a[tot++]=x;vis[x]=1;
    while(tot<n){
        for(int i=tot-1;i>=0;i--){
            int minn=max(1,a[i]-k);
            bool flag=0;
            for(int j=minn;j<=n;j++){
                if(!vis[j]){
                    vis[j]=1;flag=1;a[tot++]=j;break;
                }
            }
            if(!flag){
                return 0;
            }
        }
    }
    return 1;
}
int main(){
    scanf("%d%d",&n,&k);
    int l=0,r=n,m;
    while(l<r-1){
        m=(l+r)>>1;
        if(judge(m)){
            l=m;
        }else r=m;
    }
    printf("%d\n",l);
    return 0;
}
