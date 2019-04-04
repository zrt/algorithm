#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
typedef long long LL;
typedef double ld;
const ld eps=1e-4;
int n,m;
ld last_res=0.1;
struct Point{
	ld x[3];
	int id;
}p[65537*2],in,mn[65537*2],mx[65537*2];
int ls[65537*2],rs[65537*2];
int fa[65537*2];
int tot;
ld a,b;
ld f(ld x){
	return a*x-b*sin(x);
}
ld t;
ld r;
int type;
bool ok=0;
int root;
int D;
int pos[65537];
int INT(ld x){
	return (int)(x+0.4999999);
}
bool del[65537*2];
ld F(ld x){
	ld l=-360,r=65536;
	for(int i=0;i<=42;i++){
		ld mid=(l+r)/2;
		if(f(mid*last_res+1)>x) r=mid;
		else l=mid;
	}
	return l;
}
bool cmp(const Point&a,const Point&b){
	return a.x[D]<b.x[D];
}
void upd(int x,int y){
	if(!y) return;
	for(int i=0;i<3;i++){
		mn[x].x[i]=min(mn[x].x[i],mn[y].x[i]);
		mx[x].x[i]=max(mx[x].x[i],mx[y].x[i]);
	}
}
int bd(int l,int r){
	if(l>r) return 0;
	int mid=(l+r)/2;
	nth_element(p+l,p+mid,p+r+1,cmp);
	int dd=(D+1)%3;
	D=dd;ls[mid]=bd(l,mid-1);
	D=dd;rs[mid]=bd(mid+1,r);
	mn[mid]=mx[mid]=p[mid];
	if(ls[mid]){
		fa[ls[mid]]=mid;
		upd(mid,ls[mid]);
	}
	if(rs[mid]){
		fa[rs[mid]]=mid;
		upd(mid,rs[mid]);
	}
	return mid;
}
void Del(int x){
	del[x]=1;
	for(int i=0;i<3;i++) mn[x].x[i]=100,mx[x].x[i]=-100;
	while(x){
		upd(x,ls[x]);upd(x,rs[x]);
		x=fa[x];
	}
}
void insert(int&x,int y){
	if(!x){
		x=y;
		mn[x]=mx[x]=p[x];
	}else{
		int dd=(D+1)%3;
		if(p[y].x[D]<p[x].x[D]){
			D=dd;
			insert(ls[x],y);
			fa[ls[x]]=x;
			upd(x,ls[x]);
		}else{
			D=dd;
			insert(rs[x],y);
			fa[rs[x]]=x;
			upd(x,rs[x]);
		}
	}
}
ld dismx(int x){
	ld ret=0;
	for(int i=0;i<3;i++){
		ret+=max((in.x[i]-mn[x].x[i])*(in.x[i]-mn[x].x[i]),(in.x[i]-mx[x].x[i])*(in.x[i]-mx[x].x[i]));
	}
	return ret;
}
ld dismn(int x){
	ld ret=0;
	for(int i=0;i<3;i++){
		if(mn[x].x[i]<in.x[i]&&in.x[i]<mx[x].x[i]) continue;
		ret+=min((in.x[i]-mn[x].x[i])*(in.x[i]-mn[x].x[i]),(in.x[i]-mx[x].x[i])*(in.x[i]-mx[x].x[i]));
	}
	return ret;
}
ld dis(const Point&a,const Point&b){
	ld ret=0;
	for(int i=0;i<3;i++) ret+=(a.x[i]-b.x[i])*(a.x[i]-b.x[i]);
	return ret;
}
void ask(int x){
	if(!x) return;
	// 都在内部
	// 都在外部
	ld MX=dismx(x);
	ld MN=dismn(x);
	if(MX<r-eps) return;
	if(MN>r+eps) return;
	if(ok) return;
	if(!del[x]){
		// SOLVE NOW
		if(fabs(dis(in,p[x])-r)<eps){
			last_res=p[x].id;
			ok=1;
			return;
		}
	}
	// DIGUI
	ask(ls[x]);
	if(ok) return;
	ask(rs[x]);
}

int main(){
//	freopen("in.txt","r",stdin);
//	freopen("my.txt","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%lf%lf",&a,&b);
	for(int i=1;i<=n;i++){
		for(int j=0;j<3;j++){
			scanf("%lf",&p[i].x[j]);
		}
		p[i].id=i;
	}
	D=0;
	root=bd(1,n);
	tot=n;
	for(int i=1;i<=n;i++) pos[p[i].id]=i;
	while(m--){
		scanf("%d",&type);
		if(type==0){
			scanf("%lf%lf%lf%lf",&t,&in.x[0],&in.x[1],&in.x[2]);
			t=F(t);
			for(int i=0;i<3;i++) in.x[i]=F(in.x[i]);
			Del(pos[INT(t)]);
			p[++tot]=in;
			pos[INT(t)]=tot;
			p[tot].id=INT(t);
			D=0;
			insert(root,tot);
		}else{
			scanf("%lf%lf%lf%lf",&in.x[0],&in.x[1],&in.x[2],&r);
			r=F(r);
			for(int i=0;i<3;i++) in.x[i]=F(in.x[i]);
			r=r*r;
			ok=0;
			ask(root);
			printf("%.0f\n",last_res);
		}
	}
	
	return 0;
}
