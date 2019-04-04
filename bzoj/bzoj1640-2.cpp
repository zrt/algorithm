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
char s[60005];
int n,m;
const int MAXN=60005;
int sa[MAXN],t[MAXN],t2[MAXN],c[MAXN],rank[MAXN];
void build_sa(int m){
    int *x=t,*y=t2;
    for(int i=0;i<m;i++) c[i]=0;
    for(int i=0;i<n;i++) c[x[i]=s[i]]++;
    for(int i=1;i<m;i++) c[i]+=c[i-1];
    for(int i=n-1;i>=0;i--) sa[--c[x[i]]]=i;
    for(int k=1;k<=n;k<<=1){
        int p=0;
        for(int i=n-k;i<n;i++) y[p++]=i;
        for(int i=0;i<n;i++) if(sa[i]>=k) y[p++]=sa[i]-k;
        for(int i=0;i<m;i++) c[i]=0;
        for(int i=0;i<n;i++) c[x[y[i]]]++;
        for(int i=1;i<m;i++) c[i]+=c[i-1];
        for(int i=n-1;i>=0;i--) sa[--c[x[y[i]]]]=y[i];
        swap(x,y);
        p=1;x[sa[0]]=0;
        for(int i=1;i<n;i++){
            x[sa[i]]=y[sa[i-1]]==y[sa[i]]&&y[sa[i-1]+k]==y[sa[i]+k]?p-1:p++;
        }
        if(p>=n) break;
        m=p;
    }
}
int main(){
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%s",&s[i]);
    s[n]='$';
    for(int i=0;i<n;i++) s[i+n+1]=s[n-i-1];
    m=n;n<<=1;
    n=n+1;
    s[n]='\0';
    build_sa(128);
    for(int i=0;i<n;i++) rank[sa[i]]=i;
    int cc=0;
    int l=0,r=m-1;
    for(int i=0;i<m;i++){
        int a=rank[l];
        int b=rank[(m-r)+m];
        cc++;
        if(a<b){
            putchar(s[l++]);
        }else putchar(s[r--]);
        if(cc==80) cc=0,putchar('\n');
    }
    return 0;
}
