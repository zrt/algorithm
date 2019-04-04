#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
//by zrt
//problem:
using namespace std;
int c[2005];
int a[2005];
int cc;
int n;
int f[2005][2005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        c[i]=a[i];
    }
    sort(c+1,c+n+1);
    cc=unique(c+1,c+n+1)-(c+1);
    for(int i=1;i<=n;i++) f[i][0]=1<<30;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=cc;j++){
            f[i][j]=f[i-1][j]+abs(a[i]-c[j]);
            f[i][j]=min(f[i][j],f[i][j-1]);
        }
    }
    int ans=f[n][cc];
    sort(c+1,c+cc+1,cmp);
    for(int i=1;i<=n;i++) f[i][0]=1<<30;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=cc;j++){
            f[i][j]=f[i-1][j]+abs(a[i]-c[j]);
            f[i][j]=min(f[i][j],f[i][j-1]);
        }
    }
    ans=min(f[n][cc],ans);
    printf("%d\n",ans);
    return 0;
}
