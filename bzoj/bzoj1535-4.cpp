#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
//by zrt
//problem:
using namespace std;
typedef long long LL;
const int inf(0x3f3f3f3f);
const double eps(1e-9);
char s[500005];
int l;
struct list{
    int a[500005][2];
    int head,tail;
    int maxx;
    void init(int L){
        head=0;tail=L-1;maxx=1;
        for(int i=head;i<=tail;i++) a[i][0]=i-1,a[i][1]=i+1;
        a[head][0]=a[tail][1]=-1;
    }
    void del(int pos){
        int pre=a[pos][0],nxt=a[pos][1];
        if(nxt==-1){
            maxx=max(maxx,l-pre);
        }else maxx=max(maxx,nxt-pre);
        a[pre][1]=nxt;
        if(~nxt) a[nxt][0]=pre;
    }
}list;
int p[500005];
int nxt[500005];
int now[500005];
int main(){
    scanf("%s",s);l=strlen(s);
    memset(now,-1,sizeof now);
    list.init(l);
    int id,mx=0;
    p[0]=l;
    for(int i=1;i<l;i++){
        if(mx>i){
            p[i]=min(mx-i+1,p[i-id]);
        }
        while(i+p[i]<l&&s[i+p[i]]==s[p[i]]) p[i]++;
        if(i+p[i]-1>=mx&&i){
            mx=i+p[i]-1;
            id=i;
        }
    }
    for(int i=0;i<l;i++){
        nxt[i]=now[p[i]];
        now[p[i]]=i;
    }
    for(int i=0;i<=l;i++){
        if(list.maxx<=i&&list.tail>=l-i){
            printf("%d\n",i);break;
        }
        for(int j=now[i];j>=0;j=nxt[j]){
            list.del(j);
        }
    }
    return 0;
}
