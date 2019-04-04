#include<cstdio>
#include<algorithm>
#include<cstring>
//by zrt

using namespace std;
typedef long long LL;
int n,m;
int f[40005],x[40005],y[40005];
struct N{
	int a,b,dx,dy;
}a[40005];
struct Q{
	int x,y,t,id,ans;
}q[10005];
char s[10];
int k;
bool cmp1(Q a,Q b){
	return a.t<b.t;
}
bool cmp2(Q a,Q b){
	return a.id<b.id;
}
int abs(int x){
	return x>0?x:(-x);
}
int get(int a){
	if(a==f[a]) return a;
	int fa=f[a];
	f[a]=get(f[a]);
	x[a]=x[fa]+x[a];
	y[a]=y[fa]+y[a];
	return f[a];
}
void solve(){
	int pos=1;
	for(int i=1;i<=k;i++){
		for(;pos<=q[i].t;pos++){
			int xx=get(a[pos].a);
			int yy=get(a[pos].b);
			if(xx==yy) continue;
			f[yy]=a[pos].a;
			x[yy]=a[pos].dx-x[a[pos].b];
			y[yy]=a[pos].dy-y[a[pos].b];
		}
		int xx=get(q[i].x);
		int yy=get(q[i].y);
		if(xx!=yy){
			q[i].ans=-1;
		}else{
			q[i].ans=abs(x[q[i].x]-x[q[i].y])+abs(y[q[i].x]-y[q[i].y]);
		}
	}
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&n,&m);
	for(int i=1,d;i<=m;i++){
		scanf("%d%d%d%s",&a[i].a,&a[i].b,&d,s);
		f[i]=i;
		if(s[0]=='E'){
			a[i].dx=d;
		}else if(s[0]=='N'){
			a[i].dy=d;
		}else if(s[0]=='W'){
			a[i].dx=-d;
		}else{
			a[i].dy=-d;
		}
	}
	scanf("%d",&k);
	for(int i=1;i<=k;i++){
		scanf("%d%d%d",&q[i].x,&q[i].y,&q[i].t);
		q[i].id=i;
	}
	sort(q+1,q+k+1,cmp1);
	solve();
	sort(q+1,q+k+1,cmp2);
	for(int i=1;i<=k;i++){
		printf("%d\n",q[i].ans);
	}
	return 0;
}
