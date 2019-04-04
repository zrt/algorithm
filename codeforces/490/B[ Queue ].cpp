#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct N{
    int x,y;
}a[200005];
int n;
int nxt[1000005],last[1000005];
int num[1000005];
int q1[200005],q2[200005];
bool start[1000005];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&a[i].x,&a[i].y);
        nxt[a[i].x]=a[i].y;
        last[a[i].y]=a[i].x;
        num[a[i].x]++;
        num[a[i].y]++;
        start[a[i].x]=1;
    }
    int tot=0;
    int now=nxt[0];
    while(now){
        q1[tot++]=now;
        now=nxt[now];
    }
    now=last[0];
    if(n&1){
        for(int i=1;i<=1000000;i++){
            if(num[i]==1&&!start[i]){
                now=i;break;
            }
        }
    }
    int cc=0;
    while(now){
        q2[tot++]=now;
        now=last[now];
    }
    now=0;
    int c1(0),c2(tot-1);
    for(int i=1;i<=n;i++){
        if(now){
            printf("%d ",q1[c1++]);
            now=0;
        }else{
            printf("%d ",q2[c2--]);
            now=1;
        }
    }
//  while(1);
    return 0;
}