#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int H[105],X[20000],P[20000],tot;
inline void add(int x,int y){
    P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
int n,m;
int a[105],b[105];
bool cover[105];
int link[105];
bool dfs(int x){
    for(int i=H[x];i;i=X[i]){
        if(!cover[P[i]]){
            cover[P[i]]=1;
            if(!link[P[i]]||dfs(link[P[i]])){
                link[P[i]]=x;
                return 1;
            }
        }
    }
    return 0;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        scanf("%d",&b[i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(abs(a[i]-b[j])<=1){
                add(i,j);
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++) {
        memset(cover,0,sizeof cover);
        if(dfs(i)) ans++;
    }
    printf("%d\n",ans);
//  while(1);
    return 0;
}