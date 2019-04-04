#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n;
const int MAXN=100005;
int H[MAXN],X[MAXN*2],P[MAXN*2],tot;
inline void _add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
int w[MAXN];
int in[MAXN];
int l[MAXN*2*20],go[MAXN*2*20][10],fa[MAXN*2*20];
int root,last;
int cc;
int add(int p,int w){
	if(go[p][w]){
		int q=go[p][w];
		if(l[q]==l[p]+1){
			return q;
		}else{
			int nq=++cc;
			l[nq]=l[p]+1;
			fa[nq]=fa[q];
			memcpy(go[nq],go[q],sizeof go[q]);
			fa[q]=nq;
			while(go[p][w]==q) go[p][w]=nq,p=fa[p];
			return nq;
		}
	}else{
		int np=++cc;
		l[np]=l[p]+1;
		while(p&&!go[p][w]) go[p][w]=np,p=fa[p];
		if(!p) fa[np]=root;
		else{
			int q=go[p][w];
			if(l[q]==l[p]+1){
				fa[np]=q;
			}else{
				int nq=++cc;
				l[nq]=l[p]+1;
				fa[nq]=fa[q];
				memcpy(go[nq],go[q],sizeof go[q]);
				fa[q]=fa[np]=nq;
				while(go[p][w]==q) go[p][w]=nq,p=fa[p];
			}
		}
		return np;
	}
}
void dfs(int x,int fa,int p){
	p=add(p,w[x]);
	for(int i=H[x];i;i=X[i]){
		if(P[i]!=fa){
			dfs(P[i],x,p);
		}
	}
}
void solve(int x){
	dfs(x,0,1);
}
LL ans=0;
int main(){
	root=last=++cc;
	scanf("%d%*d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&w[i]);
	for(int i=1,x,y;i<n;i++){
		scanf("%d%d",&x,&y);
		_add(x,y);_add(y,x);in[x]++;in[y]++;
	}
	for(int i=1;i<=n;i++){
		if(in[i]==1){
			solve(i);
		}
	}
	//本质不同的子串数量=后缀树的节点数（未压缩时）
	for(int i=2;i<=cc;i++) ans+=(l[i]-l[fa[i]]);
	printf("%lld\n",ans);
	return 0;
}
