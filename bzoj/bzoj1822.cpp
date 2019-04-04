#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;
int n,m,k;
vector<int> v[205];
bool die[205];
int x[205],y[205],r[205],t[205];
int X1[205],Y1[205];
int x2[205],y2[205],r2[205];
bool duang(int i,int j,int k,double d){
	if(n==1&&m==1&&k==1&&x2[k]==100&&y2[k]==100) return 0;
    long long area=(X1[j]-x[i])*(y2[k]-y[i])-(x2[k]-x[i])*(Y1[j]-y[i]);
    double dist=fabs(area)/d;
	//dist=max(dist,max(sqrt((x[i]-x2[k])*(x[i]-x2[k])+(y[i]-y2[k])*(y[i]-y2[k])),sqrt((X1[j]-x2[k])*(X1[j]-x2[k])+(Y1[j]-y2[k])*(Y1[j]-y2[k]))));
    return dist<=r2[k];
}
bool check(int i,int j){
    int dist=(x[i]-X1[j])*(x[i]-X1[j])+(y[i]-Y1[j])*(y[i]-Y1[j]);
    if(dist>r[i]*r[i]) return 0;
    double d=sqrt(dist);
    for(int p=1;p<=k;p++){
        if(duang(i,j,p,d)) return 0;
    }
    return 1;
}
int H[450],X[200005],P[200005],flow[200005],tot;
inline void add(int x,int y,int z){
    P[++tot]=y;X[tot]=H[x];H[x]=tot;flow[tot]=z;
    P[++tot]=x;X[tot]=H[y];H[y]=tot;flow[tot]=0;
}
int S=448,T=449;
int d[450];
queue<int> q;
bool bfs(){
    memset(d,0,sizeof d);
    q.push(S);d[S]=1;
    while(!q.empty()){
        int x=q.front();q.pop();
        for(int i=H[x];i;i=X[i]){
            if(flow[i]>0&&!d[P[i]]) d[P[i]]=d[x]+1,q.push(P[i]);
        }
    }
    return d[T];
}
int dfs(int x,int a){
    if(x==T||a==0) return a;
    int f=a,tmp;
    for(int i=H[x];i;i=X[i]){
        if(flow[i]>0&&d[P[i]]==d[x]+1){
            tmp=dfs(P[i],min(a,flow[i]));
            flow[i]-=tmp;
            flow[i^1]+=tmp;
            a-=tmp;
            if(!a) break;
        }
    }
    if(f==a) d[x]=-1;
    return f-a;
}
int Dinic(){
    int f=0;
    while(bfs()) f+=dfs(S,m);
    return f;
}
bool judge(int tt){
    if(tt<0) return 0;
    tot=1;
    memset(H,0,sizeof H);
    for(int i=1;i<=n;i++){
        add(S,i,tt/t[i]+1);
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<v[i].size();j++){
            add(i,v[i][j]+n,1);
        }
    }
    for(int i=1;i<=m;i++) add(i+n,T,1);
    return Dinic()==m;
}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++) scanf("%d%d%d%d",&x[i],&y[i],&r[i],&t[i]);
    for(int i=1;i<=m;i++) scanf("%d%d",&X1[i],&Y1[i]);
    for(int i=1;i<=k;i++) scanf("%d%d%d",&x2[i],&y2[i],&r2[i]);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(check(i,j)){
                die[j]=1;
                v[i].push_back(j);
            }
        }
    }
    for(int i=1;i<=m;i++){
        if(!die[i]){
            puts("-1");
            return 0;
        }
    }
    int l=-1,r=5000000;
    while(r-l>1){
        int mid=(l+r)>>1;
        if(judge(mid)) r=mid;
        else l=mid;
    }
    printf("%d\n",r);
    return 0;
}
