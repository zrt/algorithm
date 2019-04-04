#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int n,m,T;
struct N{
	int u,v,val,;
}p[200005];
vector<int> ins[100005],del[100005];
const int MAXN=100005+200005;//LCT size
int v[MAXN],mn[MAXN],ls[MAXN],rs[MAXN],fa[MAXN];
int siz[MAXN];
bool rev[MAXN];
void upd(int x){
	mn[x]=x;
	if(ls[x]){
		if(v[mn[ls[x]]]<v[mn[x]]) mn[x]=mn[ls[x]];
	}
	if(rs[x]){
		if(v[mn[rs[x]]]<v[mn[x]]) mn[x]=mn[rs[x]];
	}
	siz[x]=siz[ls[x]]+siz[rs[x]]+(x<=n);
}
void zig(int x){
	int y=fa[x];
	if(rs[x]) ls[y]=rs[x],fa[rs[x]]=y;else ls[y]=0;
	fa[x]=fa[y];
	if(ls[fa[y]]==y) ls[fa[y]]=x;else if(rs[fa[y]]==y) rs[fa[y]]=x;
	fa[y]=x;rs[x]=y;
	upd(y);
}
void zag(int x){
	int y=fa[x];
	if(ls[x]) rs[y]=ls[x],fa[ls[x]]=y;else rs[y]=0;
	fa[x]=fa[y];
	if(ls[fa[y]]==y) ls[fa[y]]=x;else if(rs[fa[y]]==y) rs[fa[y]]=x;
	fa[y]=x;ls[x]=y;
	upd(y);
}
bool notroot(int x){
	return ls[fa[x]]==x||rs[fa[x]]==x;
}
void do_rev(int x){
	if(!x) return;
	rev[x]^=1;
	swap(ls[x],rs[x]);
}
void down(int x){
	if(rev[x]){
		do_rev(ls[x]);
		do_rev(rs[x]);
		rev[x]=0;
	}
}
int lis[MAXN];
void splay(int x){
	int t=0,p=x;
	while(notroot(p)){
		lis[t++]=p;
		p=fa[p];
	}
	down(p);
	for(int i=t-1;i>=0;i--) down(lis[i]);
	while(notroot(x)){
		int y=fa[x];
		if(!notroot(y)){
			if(ls[y]==x) zig(x);else zag(x);
		}else{
			if(ls[fa[y]]==y){
				if(ls[y]==x) zig(y),zig(x);
				else zag(x),zig(x);
			}else{
				if(ls[y]==x) zig(x),zag(x);
				else zag(y),zag(x);
			}
		}
	}
	upd(x);
}
void access(int x){
	int y=0;
	while(x){
		splay(x);
		rs[x]=y;
		upd(x);
		y=x;
		x=fa[x];
	}
}
void mkroot(int x){
	access(x);
	splay(x);
	do_rev(x);
	down(x);
}
int findroot(int x){
	access(x);
	splay(x);
	down(x);
	while(ls[x]){
		x=ls[x];
		down(x);
	}
	return x;
}
void link(int x,int y){
	mkroot(x);
	fa[x]=y;
}
void cut(int x,int y){
	mkroot(x);
	access(y);
	splay(x);
	rs[x]=fa[y]=0;
	upd(x);
}
int tot;
int where[MAXN];
int id[MAXN];
bool ontree[MAXN];
int main(){
	scanf("%d%d%d",&n,&m,&T);
	for(int i=1,x;i<=m;i++){
		scanf("%d%d%d%d",&p[i].u,&p[i].v,&x,&p[i].val);
		ins[x].push_back(i);
		del[p[i].val].push_back(i);
	}
	for(int i=1;i<=n;i++) mn[i]=i,siz[i]=1,v[i]=T+1;
	tot=n;
	int MX=-1;
	for(int t=0;t<T;t++){
		for(int i=0;i<ins[t].size();i++){
			N now=p[ins[t][i]];
			if(findroot(now.u)!=findroot(now.v)){
				v[++tot]=now.val;
				mn[tot]=tot;
				link(now.u,tot);
				link(now.v,tot);
				where[ins[t][i]]=tot;
				id[tot]=ins[t][i];
				ontree[tot]=1;
			}else{
				mkroot(now.u);
				access(now.v);
				splay(now.u);
				if(siz[now.u]%2==1){
					MX=max(MX,min(now.val,v[mn[now.u]]));
				}else{
					if(now.val > v[mn[now.u]]){
						int num=mn[now.u];
						ontree[num]=0;
						cut(num,p[id[num]].u);
						cut(num,p[id[num]].v);
						v[++tot]=now.val;
						mn[tot]=tot;
						link(now.u,tot);
						link(now.v,tot);
						where[ins[t][i]]=tot;
						id[tot]=ins[t][i];
						ontree[tot]=1;
					}
				}
				
			}
		}
		for(int i=0;i<del[t].size();i++){
			int now=del[t][i];
			if(where[now]==0) continue;
			if(!ontree[where[now]]) continue;
			ontree[where[now]]=0;
			cut(p[now].u,where[now]);
			cut(p[now].v,where[now]);
		}
		if(t>=MX) puts("Yes");else puts("No");
	}
	
	//system("pause");
	return 0;
}
 
