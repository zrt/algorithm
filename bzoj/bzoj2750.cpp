#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
int n,m;
const int mod=1000000007;
int H[1505],X[5005],P[5005],tot,E[5005];
int x[5005],y[5005],z[5005];
int d[1505];
int b[1505],c[1505];
int ans[5005];
inline void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;E[tot]=z;
}

struct N{
	int x,w;
	N(int a=0,int b=0){
		x=a,w=b;
	}
	friend bool operator < (const N&a,const N&b){
		return a.w>b.w;
	}
};
vector<N> v[1505];
priority_queue<N> q;
int list[1505],t;
bool vis[1505];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&x[i],&y[i],&z[i]);
		add(x[i],y[i],z[i]);
		v[y[i]].push_back(N(x[i],z[i]));
	}
	for(int i=1;i<=n;i++){
		memset(d,0x3f,sizeof d);
		memset(vis,0,sizeof vis);
		d[i]=0;t=0;
		q.push(N(i,0));
		while(!q.empty()){
			int x=q.top().x;q.pop();
			if(vis[x]) continue;else vis[x]=1;
			list[t++]=x;
			for(int i=H[x];i;i=X[i]){
				if(d[P[i]]>d[x]+E[i]){
					d[P[i]]=d[x]+E[i];
					q.push(N(P[i],d[P[i]]));
				}
			}
		}
		memset(b,0,sizeof b);
		memset(c,0,sizeof c);
		b[i]=1;
		for(int j=0;j<t;j++){
			//b[list[j]]++;
			int x=list[j];
			for(int i=H[x];i;i=X[i]){
				if(d[P[i]]==d[x]+E[i]){
					b[P[i]]+=b[x];
					b[P[i]]%=mod;
				}
			}
		}
		for(int j=t-1;j>=0;j--){
			int x=list[j];
			c[x]++;
			for(int i=0;i<v[x].size();i++){
				if(d[v[x][i].x]+v[x][i].w==d[x]){
					c[v[x][i].x]+=c[x];
					c[v[x][i].x]%=mod;
				}
			}
		}
		for(int i=0;i<m;i++){
			if(d[x[i]]+z[i]==d[y[i]]){
				ans[i]+=b[x[i]]*1LL*c[y[i]]%mod;
				ans[i]%=mod;
			}
		}
	}
	for(int i=0;i<m;i++) printf("%d\n",ans[i]);
	return 0;
}
