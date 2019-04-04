#include<cstdio>
#include<cstring>
#include<algorithm>
//by zrt
//problem:
using namespace std;
int minn[100005*4];
int mark[100005*4];
int c[100005];
void pd(int o){
	if(mark[o]){
		minn[o<<1]-=mark[o];
		minn[o<<1|1]-=mark[o];
		mark[o<<1]+=mark[o];
		mark[o<<1|1]+=mark[o];
		mark[o]=0;
	}
}
void insert(int o,int l,int r,int L,int R){
	if(l==L&&r==R){
		mark[o]+=1;
		minn[o]-=1;
		return;
	}else{
		pd(o);
		int m=(L+R)>>1;
		if(r<=m) insert(o<<1,l,r,L,m);
		else if(l>m) insert(o<<1|1,l,r,m+1,R);
		else insert(o<<1,l,m,L,m),insert(o<<1|1,m+1,r,m+1,R);
		minn[o]=min(minn[o<<1],minn[o<<1|1]);
	}
}
void build(int o,int l,int r){
	if(l==r){
		minn[o]=c[l];
	}else{
		int m=(l+r)>>1;
		build(o<<1,l,m);
		build(o<<1|1,m+1,r);
		minn[o]=min(minn[o<<1],minn[o<<1|1]);
	}
}
bool ok;
void ask(int o,int l,int r,int L,int R){
	if(l==L&&r==R)  ok&=(minn[o]>0);
	else{
		pd(o);
		int m=(L+R)>>1;
		if(r<=m) ask(o<<1,l,r,L,m);
		else if(l>m) ask(o<<1|1,l,r,m+1,R);
		else ask(o<<1,l,m,L,m),ask(o<<1|1,m+1,r,m+1,R);
	}
}
struct node{
	int a,b;
}q[100005];
bool cmp(node a,node b){
	return a.b<b.b;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	for(int i=0;i<m;i++){
		scanf("%d%d",&q[i].a,&q[i].b);
	}
	sort(q,q+m,cmp);
	int ans=0;
	build(1,1,n);
	for(int i=0;i<m;i++){
		ok=1;ask(1,q[i].a,q[i].b,1,n);
		if(ok){
			ans++;
			insert(1,q[i].a,q[i].b,1,n);
		}
	}
	printf("%d\n",ans);
	return 0;
}
