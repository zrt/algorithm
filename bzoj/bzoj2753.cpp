#include<bits/stdc++.h>
using namespace std;
int n,m;
int h[100005];
typedef long long LL;
int H[100005],X[2000005],P[2000005],tot;
LL E[2000005];
inline void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;E[tot]=z;
}
struct edge{
	int x,y,z;
	friend bool operator < (const edge&a,const edge&b){
		if(h[a.y]!=h[b.y]) return h[a.y]>h[b.y];
		return a.z<b.z;
	}
}e[2000005];
bool vis[100005];
queue<int> q;
LL ans;
int fa[100005];
int get(int x){
	return fa[x]==x?x:fa[x]=get(fa[x]);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&h[i]);
	for(int i=0,x,y,z;i<m;i++){
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);add(y,x,z);
	}
	q.push(1);vis[1]=1;
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=H[x];i;i=X[i]){
			if(h[P[i]]<=h[x]&&!vis[P[i]]){
				q.push(P[i]);
				vis[P[i]]=1;
			}
		}
	}
	int num=0;
	for(int i=1;i<=n;i++) num+=vis[i];
	for(int i=1;i<=n;i++) fa[i]=i;
	tot=0;
	for(int i=1;i<=n;i++){
		if(!vis[i]) continue;
		for(int j=H[i];j;j=X[j]){
			if(!vis[P[j]]) continue;
			if(h[P[j]]<=h[i]){
				e[tot].x=i;
				e[tot].y=P[j];
				e[tot].z=E[j];
				tot++;
			}
		}
	}
	sort(e,e+tot);
	for(int i=0;i<tot;i++){
		if(get(e[i].x)!=get(e[i].y)){
			fa[get(e[i].x)]=get(e[i].y);
			ans+=e[i].z;
		}
	}
	printf("%d %lld\n",num,ans);
	return 0;
}
