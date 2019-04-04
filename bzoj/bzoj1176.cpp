#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
int s,w;
LL ans[260000];
struct Q{
	int t;
	int x1,y1,x2,y2,id,a;
}q[260000],p[260000];
int tot,cc;
LL c[2000005];
bool cmp(const Q&a,const Q&b){
	if(a.x1!=b.x1) return a.x1<b.x1;
	return a.t<b.t;
}
#define lowbit(x) ((x)&-(x))
void add(int x,int k){
	while(x<=w){
		c[x]+=k;
		x+=lowbit(x);
	}
}
LL ask(int x){
	LL ret=0;
	while(x>0){
		ret+=c[x];
		x-=lowbit(x);
	}
	return ret;
}
void cdq(int l,int r){
	if(l==r) return;
	else{
		int mid=(l+r)>>1;
		cdq(l,mid);cdq(mid+1,r);
		cc=0;
		for(int i=l;i<=mid;i++){
			if(q[i].t==1){
				p[cc++]=q[i];
			}
		}
		for(int i=mid+1;i<=r;i++){
			if(q[i].t==2){
				p[cc].t=2,p[cc].x1=q[i].x1-1,p[cc].y1=q[i].y1,p[cc].y2=q[i].y2,p[cc].a=-1;p[cc].id=q[i].id;
				cc++;
				p[cc].t=2,p[cc].x1=q[i].x2,p[cc].y1=q[i].y1,p[cc].y2=q[i].y2,p[cc].a=1;p[cc].id=q[i].id;
				cc++;
			}
		}
		sort(p,p+cc,cmp);
		for(int i=0;i<cc;i++){
			if(p[i].t==1){
				add(p[i].y1,p[i].a);
			}else{
				ans[p[i].id]+=(ask(p[i].y2)-ask(p[i].y1-1))*p[i].a;
			}
		}
		for(int i=l;i<=mid;i++){
			if(q[i].t==1){
				add(q[i].y1,-p[i].a);
			}
		}
	}
}
int main(){
	scanf("%d%d",&s,&w);
	int t;
	while(scanf("%d",&t),t!=3){
		tot++;
		q[tot].t=t;
		q[tot].id=tot;
		if(t==1){
			scanf("%d%d%d",&q[tot].x1,&q[tot].y1,&q[tot].a);
		}else scanf("%d%d%d%d",&q[tot].x1,&q[tot].y1,&q[tot].x2,&q[tot].y2),ans[tot]=(q[tot].y2-q[tot].y1+1)*(q[tot].x2-q[tot].x1+1)*s;
	}
	cdq(1,tot);
	for(int i=1;i<=tot;i++){
		if(q[i].t==2)printf("%lld\n",ans[q[i].id]);
	}
	return 0;
}
