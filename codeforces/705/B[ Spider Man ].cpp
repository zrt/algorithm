#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
bool vis[10005];
int sg[1005];
int main(){
    /*
    sg[1]=0;
    for(int i=2;i<=100;i++){
        memset(vis,0,sizeof vis);
        for(int p=1;p<i;p++){
            vis[sg[p]^sg[i-p]]=1;
        }
        while(vis[sg[i]]) sg[i]++;
        printf("%d %d\n",i,sg[i]);
    }
    */
    int n;
    scanf("%d",&n);
    int p=0;
    for(int i=1,x;i<=n;i++){
        scanf("%d",&x);
        if(~x&1) p^=1;
        if(p) printf("1\n");
        else printf("2\n");
    }

    return 0;
}