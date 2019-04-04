#include<cstdio>
#include<cstring>
#include<algorithm>
//by zrt
//problem:
using namespace std;
int n,m,k,x,y;
int H[15005],X[30005],P[30005],tot,E[30005];
inline void add(int x,int y,int z){
    P[++tot]=y;X[tot]=H[x];H[x]=tot;E[tot]=z;
}
struct e{
    int x,y,z;
    friend bool operator < (e a,e b){
        return a.z<b.z;
    }
}a[30005];
int f[15005];
int fa[15005][15];
int mx[15005][15];
int dep[15005];
int get(int x){
    return f[x]==x?x:f[x]=get(f[x]);
}
int lg;
void dfs(int x){
    for(int i=H[x];i;i=X[i]){
        if(P[i]!=fa[x][0]){
            fa[P[i]][0]=x;
            mx[P[i]][0]=E[i];
            dep[P[i]]=dep[x]+1;
            dfs(P[i]);
        }
    }
}
int ask(int x,int y){
    if(dep[x]>dep[y]) swap(x,y);
    int ret=0;
    for(int i=lg;i>=0;i--){
        if(dep[fa[y][i]]>=dep[x]){
            ret=max(ret,mx[y][i]);
            y=fa[y][i];
        }
    }
    if(y==x) return ret;
    for(int i=lg;i>=0;i--){
        if(fa[y][i]!=fa[x][i]){
            ret=max(ret,max(mx[x][i],mx[y][i]));            
            y=fa[y][i];
            x=fa[x][i];
        }
    }
    return max(ret,max(mx[x][0],mx[y][0]));
}
int main(){
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
    }
    sort(a,a+m);
    for(int i=1;i<=n;i++) f[i]=i;
    for(int i=0;i<m;i++){
        if(get(a[i].x)!=get(a[i].y)){
            f[get(a[i].x)]=get(a[i].y);
            add(a[i].x,a[i].y,a[i].z);
            add(a[i].y,a[i].x,a[i].z);
        }
    }
    for(lg=0;(1<<lg)<=n;lg++);lg--;
    dep[1]=1;
    dfs(1);
    for(int i=0;i<=lg;i++){
        for(int j=1;j<=n;j++){
            if(fa[j][i-1]){
                fa[j][i]=fa[fa[j][i-1]][i-1];
                mx[j][i]=max(mx[j][i-1],mx[fa[j][i-1]][i-1]);
            }
        }
    }
    while(k--){
        scanf("%d%d",&x,&y);
        printf("%d\n",ask(x,y));
    }
     
    return 0;
}
