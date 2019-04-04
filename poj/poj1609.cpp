#include<cstdio>
#include<algorithm>
using namespace std;
int l[10005];
int n;
struct N{
int l,r;
}a[10005];
bool cmp(N a,N b){
    if(a.l!=b.l) return a.l<b.l;
    else return a.r<b.r;
}
int main(){
    int n;
    while(scanf("%d",&n)&&n){
        for(int i=0;i<n;i++) scanf("%d%d",&a[i].l,&a[i].r);
        sort(a,a+n,cmp);
        for(int i=0;i<n;i++){
            l[i]=1;
            for(int j=0;j<i;j++){
                if(a[i].l>=a[j].l&&a[i].r>=a[j].r&&l[j]+1>l[i]){
                    l[i]=l[j]+1;
                }
            }
        }
        int mx=0;
        for(int i=0;i<n;i++){
            if(mx<l[i]) mx=l[i];
        }
        printf("%d\n",mx);
    }
    puts("*");
    return 0;
}
