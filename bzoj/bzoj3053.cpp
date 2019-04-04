#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int k,n;
struct Point{
	int a[5];
}p[50005],t,ans[11];
int dis(Point a,Point b){
	int ret=0;
	for(int i=0;i<k;i++){
		ret+=(a.a[i]-b.a[i])*(a.a[i]-b.a[i]);
	}
	return ret;
}
int root;
int D,q,m;
int ls[50005],rs[50005],num;
Point mn[50005],mx[50005];
bool cmp(Point a,Point b){
	return a.a[D]<b.a[D];
}
void upd(int x,int y){
	for(int i=0;i<k;i++){
		mn[x].a[i]=min(mn[x].a[i],mn[y].a[i]);
		mx[x].a[i]=max(mx[x].a[i],mx[y].a[i]);
	}
}
int bd(int l,int r){
	if(l>r) return 0;
	int mid=(l+r)>>1;
	nth_element(p+l,p+mid,p+r+1,cmp);
	mn[mid]=mx[mid]=p[mid];
	int dd=(D+1)%k;
	D=dd;
	ls[mid]=bd(l,mid-1);
	D=dd;
	rs[mid]=bd(mid+1,r);
	if(ls[mid]) upd(mid,ls[mid]);
	if(rs[mid]) upd(mid,rs[mid]);
	return mid;
}
void add(Point x){
	int pos=0;
	for(pos=num-1;pos>=0&&dis(ans[pos],t)>=dis(x,t);pos--);
	pos++;
	if(num<m){
		for(int i=num;i>pos;i--) ans[i]=ans[i-1];
		ans[pos]=x;
		num++;
	}else{
		for(int i=m-1;i>pos;i--) ans[i]=ans[i-1];
		ans[pos]=x;
	}
}
void check(Point x){
	if(num<m||dis(x,t)<dis(ans[m-1],t)){
		add(x);
	}
}
int mndis(int x){
	int ret=0;
	for(int i=0;i<k;i++){
		if(t.a[i]<mn[x].a[i]){
			ret+=(mn[x].a[i]-t.a[i])*(mn[x].a[i]-t.a[i]);
		}else if(t.a[i]>mx[x].a[i]){
			ret+=(t.a[i]-mx[x].a[i])*(t.a[i]-mx[x].a[i]);
		}
	}
	return ret;
}
bool ok(int x){
	if(num<m) return 1;
	if(mndis(x)<dis(ans[num-1],t)) return 1;
	return 0;
}
void ask(int x){
	int dd=D;
	check(p[x]);
	if(t.a[dd]<=p[x].a[dd]){
		D=(dd+1)%k;
		if(ls[x]) ask(ls[x]);
		D=(dd+1)%k;
		if(rs[x]&&ok(rs[x])) ask(rs[x]);
	}else{
		D=(dd+1)%k;
		if(rs[x]) ask(rs[x]);
		D=(dd+1)%k;
		if(ls[x]&&ok(ls[x])) ask(ls[x]);
	}
}
int main(){
	while(~scanf("%d%d",&n,&k)){
		for(int i=1;i<=n;i++){
			for(int j=0;j<k;j++){
				scanf("%d",&p[i].a[j]);
			}
		}
		D=0;
		root=bd(1,n);
		scanf("%d",&q);
		while(q--){
			for(int i=0;i<k;i++) scanf("%d",&t.a[i]);
			scanf("%d",&m);
			printf("the closest %d points are:\n",m);
			D=0;num=0;
			ask(root);
			for(int i=0;i<m;i++){
				for(int j=0;j<k-1;j++){
					printf("%d ",ans[i].a[j]);
				}
				printf("%d",ans[i].a[k-1]);
				puts("");
			}
		}
	}
	return 0;
}
