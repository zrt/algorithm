#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
int n,k;
int H[200005],P[400005],X[400005],E[400005],tot;
inline void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;E[tot]=z;
}
bool vis[200005];
int ans,siz[200005],mx[200005],list[200005],t;
void dfs(int x,int fa){
	siz[x]=1;mx[x]=-1;list[t++]=x;
	for(int i=H[x];i;i=X[i]){
		if(P[i]!=fa&&!vis[P[i]]){
			dfs(P[i],x);
			mx[x]=max(mx[x],siz[P[i]]);
			siz[x]+=siz[P[i]];
		}
	}
}
int getroot(int x){
	t=0;
	dfs(x,0);
	int sum=siz[x];
	int mn=n+1,pos;
	for(int i=0;i<t;i++){
		if(max(mx[list[i]],sum-siz[list[i]])<mn){
			mn=max(mx[list[i]],sum-siz[list[i]]);
			pos=list[i];
		}
	}
	return pos;
}
struct N{
	LL sum;int dep;
	N(LL a=0,int b=0){
		sum=a;dep=b;
	}
};
vector<N> v;
int mn[1000005],belong[1000005];
int get(LL pos,int x){
	if(pos<0||belong[pos]!=x) return n+2;
	else return mn[pos];
}
void change(int pos,int x,int dep){
	if(pos>k) return;
	if(belong[pos]!=x) belong[pos]=x,mn[pos]=dep;
	else{
		mn[pos]=min(mn[pos],dep);
	}
}
void dfs2(int x,int fa,LL sum,int dep){
	v.push_back(N(sum,dep));
	for(int i=H[x];i;i=X[i]){
		if(!vis[P[i]]&&P[i]!=fa){
			dfs2(P[i],x,sum+E[i],dep+1);
		}
	}
}
void solve(int x){
	vis[x]=1;
	change(0,x,0);
	for(int i=H[x];i;i=X[i]){
		if(!vis[P[i]]){
			v.clear();
			dfs2(P[i],x,E[i],1);
			for(int i=0;i<v.size();i++){
				ans=min(ans,get(k-v[i].sum,x)+v[i].dep);
			}
			for(int i=0;i<v.size();i++){
				change(v[i].sum,x,v[i].dep);
			}
		}
	}
	for(int i=H[x];i;i=X[i]){
		if(!vis[P[i]]){
			int root=getroot(P[i]);
			solve(root);
		}
	}
}
int main(){
	scanf("%d%d",&n,&k);
	ans=n+1;
	for(int i=1,x,y,z;i<n;i++) scanf("%d%d%d",&x,&y,&z),x++,y++,add(x,y,z),add(y,x,z);
	int root=getroot(1);
	solve(root);
	if(ans==n+1) puts("-1");
	else printf("%d\n",ans);
	return 0;
}
