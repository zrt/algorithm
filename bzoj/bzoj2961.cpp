#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int n;
struct N{
	int t;
	double x,y;
	friend N operator - (const N&a,const N&b){
		N r;
		r.x=a.x-b.x;
		r.y=a.y-b.y;
		return r;
	}
}q[500005],t1[500005],t2[500005],top[500005],bot[500005];
bool ans[500005];
bool met[500005];
bool cmp(const N&a,const N&b){
	if(a.x!=b.x) return a.x<b.x;
	return a.y<b.y;
}
int num1,num2;
int _1,_2;
bool judge(const N&a,const N&b,const N&c){
	return (a.x-b.x)*(c.y-b.y)-(c.x-b.x)*(a.y-b.y)>=0;
}
void mk(){
	_1=_2=0;
	sort(t1+1,t1+num1+1,cmp);
	for(int i=1;i<=num1;i++){//
		while(_2>1&&judge(bot[_2-2],bot[_2-1],t1[i])) _2--;
		bot[_2++]=t1[i];
		
	}
	for(int i=num1;i>=1;i--){//
		while(_1>1&&judge(top[_1-2],top[_1-1],t1[i])) _1--;
		top[_1++]=t1[i];
	}
}
double calc_k(N x){
	if(fabs(x.x)<1e-10){
		if(fabs(x.y)<1e-10) return 0;
		if(x.y>=0) return 1e140;
		else return -1e140;
	}
	return x.y/x.x;
}
void askdown(N x){// bot
	met[x.t]=1;
	double k;
	if(fabs(x.y)<1e-10){
		if(fabs(x.x)<1e-10){
			ans[x.t]=0;
			return;
		}
		if(x.x>0) k=-1e150;
		else k=1e150;
	}else k=-x.x/x.y;
	int l=0,r=_2;
	while(r-l>1){
		int mid=l+((r-l)>>1);
		if(mid+1>=_2){
			r=mid;continue;
		}
		N tmp=bot[mid+1]-bot[mid];
		if(tmp.y*x.y<=-x.x*tmp.x) l=mid;
		else r=mid;
	}
	N tt=x;
	tt.x/=2;
	tt.y/=2;
	double b=-k*tt.x+tt.y;
	if(bot[l].x*k+b>bot[l].y+1e-10) ans[x.t]=0;
	if(r<_2&&bot[r].x*k+b>bot[r].y+1e-10) ans[x.t]=0;
}
void askup(N x){// top
	met[x.t]=1;
	double k;
	if(fabs(x.y)<1e-10){
		if(fabs(x.x)<1e-10){
			ans[x.t]=0;
			return;
		}
		if(x.x>0) k=-1e150;
		else k=1e150;
	}else k=-x.x/x.y;
	int l=0,r=_1;
	while(r-l>1){
		int mid=l+((r-l)>>1);
		if(mid+1>=_1){
			r=mid;continue;
		}
		N tmp=top[mid+1]-top[mid];
		if(tmp.y*x.y>=-x.x*tmp.x) l=mid;
		else r=mid;
	}
	N tt=x;
	tt.x/=2;
	tt.y/=2;
	double b=-k*tt.x+tt.y;
	if(top[l].x*k+b<top[l].y-1e-10) ans[x.t]=0;
	if(r<_1&&top[r].x*k+b<top[r].y-1e-10) ans[x.t]=0;
}
void solve(int l,int r){
	if(l==r) return;
	int mid=(l+r)>>1;
	solve(l,mid);solve(mid+1,r);
	num1=0,num2=0;
	for(int i=l;i<=mid;i++) if(q[i].t==0) t1[++num1]=q[i];
	if(!num1) return;
	for(int i=mid+1;i<=r;i++) if(q[i].t) t2[++num2]=q[i],t2[num2].t=i;
	if(!num2) return;
	mk();
	for(int i=1;i<=num2;i++){
		if(t2[i].y>=0) askdown(t2[i]);
		else askup(t2[i]);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%lf%lf",&q[i].t,&q[i].x,&q[i].y);
	}
	memset(ans,1,sizeof ans);
	solve(1,n);
	for(int i=1;i<=n;i++){
		if(q[i].t){
			if(ans[i]&&met[i]) puts("Yes");
			else puts("No");
		}
	}	
	return 0;
}
