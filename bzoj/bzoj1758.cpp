#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;
typedef double ld;
typedef long long LL;
int n;
int L,U;
int H[100005],X[200005],E[200005],P[200005],tot;
int siz[100005],mx[100005];
bool vis[100005];
ld w[200005];
inline void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;E[tot]=z;
}
int list[200005],t;
void dfs(int x,int fa){
	siz[x]=1;mx[x]=0;
	list[t++]=x;
	for(int i=H[x];i;i=X[i]){
		if(fa!=P[i]&&!vis[P[i]]){
			dfs(P[i],x);
			siz[x]+=siz[P[i]];
			mx[x]=max(mx[x],siz[P[i]]);
		}
	}
}
int getroot(int x){
	t=0;
	dfs(x,0);
	int mn=n,pos;
	int sum=siz[x];
	for(int i=0;i<t;i++){
		if(max(mx[list[i]],sum-siz[list[i]])<mn){
			mn=max(mx[list[i]],sum-siz[list[i]]);
			pos=list[i];
		}
	}
	return pos;
}
ld ans;
int mxdp,mxdpp;
ld now[200005];
struct N{
	int dep;
	ld val;
	N(int a=0,ld b=0){
		dep=a,val=b;
	}
	friend bool operator < (const N&a,const N&b){
		return a.dep<b.dep;
	}
};
void dfs2(int x,int fa,ld sum,int dep){
	mxdpp=max(mxdpp,dep);
	now[dep]=max(now[dep],sum);
	for(int i=H[x];i;i=X[i]){
		if(P[i]!=fa&&!vis[P[i]]){
			dfs2(P[i],x,sum+w[i],dep+1);
		}
	}
}
struct dddl{
	N q[200005];
	int h,t;
	void pop(int x){
		while(h<t&&q[h].dep>=x) h++;
	}
	void insert(N a){
		while(h<t&&q[t-1].val<=a.val) t--;
		q[t++]=a;
	}
	ld ask(){
		if(h==t) return -1e100;
		return q[h].val;
	}
	void clear(){
		h=t=0;
	}
}q;
ld MX[200005];
bool ok=0;
void calc(){
	int j=L;
	q.clear();
	for(int i=0;i<=mxdpp;i++){
		if(i>U) break;
		if(j>=0&&j+i>=L) q.insert(N(j,MX[j])),j--;
		q.pop(U-i+1);
		ans=max(ans,q.ask()+now[i]);
		if(ans>0) ok=1;
	}
}
void solve(int x,int fa){
	vis[x]=1;
	mxdpp=mxdp=0;
	MX[0]=0;
	for(int i=H[x];i;i=X[i]){
		if(P[i]!=fa&&!vis[P[i]]){
			dfs2(P[i],x,w[i],1);
			calc();
			mxdp=max(mxdp,mxdpp);
			for(int i=1;i<=mxdpp;i++){
				MX[i]=max(MX[i],now[i]);
				now[i]=-1e100;
			}
			if(ok) break;
		}
	}
	for(int i=1;i<=mxdp;i++) MX[i]=-1e100;
	if(ok) return;
	for(int i=H[x];i;i=X[i]){
		if(P[i]!=fa&&!vis[P[i]]){
			int root=getroot(P[i]);
			solve(root,x);
			if(ok)return;
		}
	}
}
ld Judge(){
	ans=-1e200;
	memset(vis,0,sizeof vis);
	int root=getroot(1);
	solve(root,0);
	return ans;
}
bool judge(ld x){
	ok=0;
	for(int i=1;i<=tot;i++) w[i]=E[i]-x;
	if(Judge()>0) return 1;
	else return 0;
}
int main(){
//	freopen("in","r",stdin);
//	double begin=clock();
	scanf("%d%d%d",&n,&L,&U);
	for(int i=1;i<=n;i++) now[i]=MX[i]=-1e100;
	for(int i=1,x,y,z;i<n;i++) scanf("%d%d%d",&x,&y,&z),add(x,y,z),add(y,x,z);
	ld l=1,r=1000001;
	for(int i=0;i<=35;i++){
		ld mid=(l+r)/2;
//		printf("%.10f\n",(double)mid);
		if(judge(mid)) l=mid;
		else r=mid;
	}
	printf("%.3f\n",(double)l);	
//	printf("%.3f\n",(clock()-begin)/CLOCKS_PER_SEC);
	return 0;
}
