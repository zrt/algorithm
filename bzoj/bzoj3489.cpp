#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
int ans;
int a[100005],last[100005],p[100005],q[100005];
struct Point{
	int x[3],w;
}P[100005];
int D;
int root;
int ls[100005],rs[100005];
int mn[100005][3],mx[100005][3];
int w[100005];
bool cmp(Point a,Point b){
	return a.x[D]<b.x[D];
}
int mk(int l,int r){
	if(l>r) return 0;
	int mid=(l+r)>>1;
	int dd=(D+1)%3;
	nth_element(P+l,P+mid,P+r+1,cmp);
	for(int i=0;i<3;i++) mn[mid][i]=mx[mid][i]=P[mid].x[i];
	w[mid]=P[mid].w;
	D=dd;
	ls[mid]=mk(l,mid-1);
	D=dd;
	rs[mid]=mk(mid+1,r);
	if(ls[mid]){
		for(int i=0;i<3;i++){
			mn[mid][i]=min(mn[mid][i],mn[ls[mid]][i]);
			mx[mid][i]=max(mx[mid][i],mx[ls[mid]][i]);
		}
		w[mid]=max(w[mid],w[ls[mid]]);
	}
	if(rs[mid]){
		for(int i=0;i<3;i++){
			mn[mid][i]=min(mn[mid][i],mn[rs[mid]][i]);
			mx[mid][i]=max(mx[mid][i],mx[rs[mid]][i]);
		}
		w[mid]=max(w[mid],w[rs[mid]]);
	}
	return mid;
}
int pos[3][2];//0 mn 1 mx
bool judge(int o){
	for(int i=0;i<3;i++){
		if(pos[i][0]>mx[o][i]) return 0;
		if(pos[i][1]<mn[o][i]) return 0;
	}
	return 1;
}
void ask(int o){
	bool ok=1;
	for(int i=0;i<3&&ok;i++){
		if(mn[o][i]<pos[i][0]) ok=0;
		if(mx[o][i]>pos[i][1]) ok=0;
	}
	if(ok){
		ans=max(ans,w[o]);
	}else{
		ok=1;
		for(int i=0;i<3&&ok;i++){
			if(P[o].x[i]<pos[i][0]) ok=0;
			if(P[o].x[i]>pos[i][1]) ok=0;
		}
		if(ok) ans=max(ans,P[o].w);
		if(ls[o]&&judge(ls[o])){
			ask(ls[o]);
		}
		if(rs[o]&&judge(rs[o])){
			ask(rs[o]);
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) p[i]=last[a[i]],last[a[i]]=i;
	for(int i=1;i<=n;i++) last[i]=n+1;
	for(int i=n;i>=1;i--) q[i]=last[a[i]],last[a[i]]=i;
	for(int i=1;i<=n;i++) P[i].x[0]=i,P[i].x[1]=p[i],P[i].x[2]=q[i],P[i].w=a[i];
	D=0;
	root=mk(1,n);
	int l,r;
	while(m--){
		scanf("%d%d",&l,&r);
		l=(l+ans)%n+1;
		r=(r+ans)%n+1;
		if(l>r) swap(l,r);
		ans=0;
		pos[0][0]=l;pos[0][1]=r;
		pos[1][0]=0;pos[1][1]=l-1;
		pos[2][0]=r+1;pos[2][1]=n+1;
		D=0;
		ask(root);
		printf("%d\n",ans);
	}
	return 0;
}
