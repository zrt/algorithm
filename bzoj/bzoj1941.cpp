#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int n;
struct Point{
	int x[2];
	void read(){
		scanf("%d%d",&x[0],&x[1]);
	}
}p[500005],mn[500005],mx[500005],x;
int D;
int ls[500005],rs[500005];
bool cmp(const Point&a,const Point&b){
	return a.x[D]<b.x[D];
}
int root;
void upd(int x,int y){
	for(int i=0;i<2;i++){
		mn[x].x[i]=min(mn[x].x[i],mn[y].x[i]);
		mx[x].x[i]=max(mx[x].x[i],mx[y].x[i]);
	}
}
int bd(int l,int r){
	if(l>r) return 0;
	int mid=(l+r)>>1;
	nth_element(p+l,p+mid,p+r+1,cmp);
	mn[mid]=mx[mid]=p[mid];
	int dd=D^1;
	D=dd;
	ls[mid]=bd(l,mid-1);
	D=dd;
	rs[mid]=bd(mid+1,r);
	if(ls[mid]) upd(mid,ls[mid]);
	if(rs[mid]) upd(mid,rs[mid]);
	return mid;
}
int ans;
int _far,_near;
int dis(Point x,Point y){
	return abs(x.x[0]-y.x[0])+abs(x.x[1]-y.x[1]);
}
int judge2(int o){
	int ret=0;
	for(int i=0;i<2;i++){
		if(x.x[i]<mx[o].x[i]) ret+=mx[o].x[i]-x.x[i];
		if(x.x[i]>mn[o].x[i]) ret+=x.x[i]-mn[o].x[i];
	}
	return ret;
}
void far(int o){
	_far=max(_far,dis(p[o],x));
	//if(ls[o]) far(ls[o]);
	//if(rs[o]) far(rs[o]);
	
	if(ls[o]&&rs[o]){
		int a=judge2(ls[o]),b=judge2(rs[o]);
		if(a>b){
			if(a>_far) far(ls[o]);
			if(b>_far) far(rs[o]);
		}else{
			if(b>_far) far(rs[o]);
			if(a>_far) far(ls[o]);
		}
	}else if(ls[o]){
		if(judge2(ls[o])>_far){
			far(ls[o]);
		}
	}else if(rs[o]){
		if(judge2(rs[o])>_far){
			far(rs[o]);
		}
	}
	
}
int judge(int o){
	int ret=0;
	for(int i=0;i<2;i++){
		if(x.x[i]<mn[o].x[i]) ret+=mn[o].x[i]-x.x[i];
		if(x.x[i]>mx[o].x[i]) ret+=x.x[i]-mx[o].x[i];
	}
	return ret;
}
void near(int o){
	int tmp=dis(p[o],x);
	if(tmp)_near=min(_near,tmp);
	//if(ls[o]) near(ls[o]);
	//if(rs[o]) near(rs[o]);
	
	if(ls[o]&&rs[o]){
		int a=judge(ls[o]),b=judge(rs[o]);
		if(a<b){
			if(a<_near) near(ls[o]);
			if(b<_near) near(rs[o]);
		}else{
			if(b<_near) near(rs[o]);
			if(a<_near) near(ls[o]);
		}
	}else if(ls[o]){
		if(judge(ls[o])<_near){
			near(ls[o]);
		}
	}else if(rs[o]){
		if(judge(rs[o])<_near){
			near(rs[o]);
		}
	}
	
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) p[i].read();
	D=0;
	root=bd(1,n);
	ans=3e8;
	for(int i=1;i<=n;i++){
		x=p[i];
		_far=0,_near=3e8;
		far(root),near(root);
	//	printf("%d %d\n",_far,_near);
		ans=min(ans,_far-_near);
	}
	printf("%d\n",ans);
	return 0;
}
