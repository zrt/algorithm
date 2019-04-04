#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
//by zrt
//problem:
using namespace std;
typedef long long LL;
struct N{
	int x,y;LL z;int id;bool mark;bool chose;
	LL w;
	N(int a=0,int b=0,LL c=0,int d=0){
		x=a,y=b,z=c,id=d;mark=0;chose=0;
	}
}a[50005];
struct Q{
	int k;LL d;
}Q[50005];
int n,m,q;
bool cmp(N a,N b){
	return a.w<b.w;
}
//int num[50005];
int f[50005];
int get(int x){
	return f[x]==x?x:f[x]=get(f[x]);
}
int to[50005];
LL inf=1LL<<60;
vector<N> e;
void solve(int l,int r,vector<N> a,LL ans,int n){
	if(l==r){
		int m=a.size();
		for(int i=0;i<m;i++){
			a[i].w=a[i].z;
			if(a[i].id==Q[l].k){
				a[i].w=Q[l].d;
			}
		}
		sort(a.begin(),a.end(),cmp);
		for(int i=1;i<=n;i++) f[i]=i;
		for(int i=0;i<m;i++){
			if(get(a[i].x)!=get(a[i].y)){
				f[get(a[i].x)]=get(a[i].y);
				ans+=a[i].w;
			}
		}
		printf("%lld\n",ans);
	}else{
		int mid=(l+r)>>1;
		int m=a.size();
		
		for(int i=0;i<m;i++) {
			a[i].mark=0;to[a[i].id]=i;a[i].chose=0;
		}
		for(int i=l;i<=r;i++){
			a[to[Q[i].k]].mark=1;
		}
		for(int i=0;i<m;i++) if(!a[i].mark) a[i].w=a[i].z;else a[i].w=0;
		for(int i=1;i<=n;i++)to[i]=0;
		sort(a.begin(),a.end(),cmp);
		for(int i=1;i<=n;i++) f[i]=i;
		for(int i=0;i<m;i++){
			if(get(a[i].x)!=get(a[i].y)){
				f[get(a[i].x)]=get(a[i].y);
				ans+=a[i].w;
				a[i].chose=1;
			}
		}
		for(int i=1;i<=n;i++) f[i]=i;
		for(int i=0;i<m;i++){
			if(a[i].chose&&!a[i].mark){
				f[get(a[i].x)]=get(a[i].y);
			}
		}
		int cc=0;
		for(int i=1;i<=n;i++){
			if(!to[get(i)]) to[get(i)]=++cc;
			to[i]=to[get(i)];
		}
		n=cc;
		for(int i=0;i<m;i++){
			a[i].x=to[a[i].x];
			a[i].y=to[a[i].y];
			if(a[i].mark) a[i].w=inf;
			a[i].chose=0;
		}
		sort(a.begin(),a.end(),cmp);
		for(int i=1;i<=n;i++) f[i]=i;
		for(int i=0;i<m;i++){
			if(get(a[i].x)!=get(a[i].y)){
				f[get(a[i].x)]=get(a[i].y);
				a[i].chose=1;
			}
		}
		vector<N> e;
		for(int i=0;i<m;i++){
			if((a[i].mark)||(a[i].chose)) e.push_back(a[i]);
		}
		solve(l,mid,e,ans,n);
		e.clear();
		for(int i=0;i<m;i++){
			if((a[i].mark)||(a[i].chose)) e.push_back(a[i]);
		}
		for(int i=0;i<e.size();i++){
			to[e[i].id]=i;
		}
		for(int i=l;i<=mid;i++) e[to[Q[i].k]].z=Q[i].d;
		solve(mid+1,r,e,ans,n);
	}
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=m;i++){
		a[i].id=i;
		scanf("%d%d%lld",&a[i].x,&a[i].y,&a[i].z);
	}
	for(int i=1;i<=q;i++){
		scanf("%d%lld",&Q[i].k,&Q[i].d);
		a[Q[i].k].mark=1;
	}
	for(int i=1;i<=m;i++) if(!a[i].mark) a[i].w=a[i].z;
	sort(a+1,a+m+1,cmp);
	LL ans=0;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++){
		if(get(a[i].x)!=get(a[i].y)){
			f[get(a[i].x)]=get(a[i].y);
			ans+=a[i].w;
			a[i].chose=1;
		}
	}
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++){
		if(a[i].chose&&!a[i].mark){
			f[get(a[i].x)]=get(a[i].y);
		}
	}
	int cc=0;
	for(int i=1;i<=n;i++){
		if(!to[get(i)]) to[get(i)]=++cc;
		to[i]=to[get(i)];
	}
	n=cc;
	for(int i=1;i<=m;i++){
		a[i].x=to[a[i].x];
		a[i].y=to[a[i].y];
		if(a[i].mark) a[i].w=inf;
		a[i].chose=0;
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++){
		if(get(a[i].x)!=get(a[i].y)){
			f[get(a[i].x)]=get(a[i].y);
			a[i].chose=1;
		}
	}
	for(int i=1;i<=m;i++){
		if((a[i].mark)||(a[i].chose)) e.push_back(a[i]);
	}
	solve(1,q,e,ans,n);
	return 0;
}
