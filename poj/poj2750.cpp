#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
using namespace std;
typedef long long LL;
typedef long double ld;
void read(int&x){scanf("%d",&x);}
void read(long double&x){double xx;scanf("%lf",&xx);x=xx;}
void read(LL&x){scanf("%lld",&x);}
void read(char*s){scanf("%s",s);}

int n;
int a[100005];
int Sum;
struct Segment_Tree{
	int sum[100005*4],mxl[100005*4],mxr[100005*4],mx[100005*4],t;
	void up(int o){
		sum[o]=sum[o<<1]+sum[o<<1|1];
		mxl[o]=max(mxl[o<<1],sum[o<<1]+mxl[o<<1|1]);
		mxr[o]=max(mxr[o<<1|1],sum[o<<1|1]+mxr[o<<1]);
		mx[o]=max(max(mx[o<<1],mx[o<<1|1]),mxl[o<<1|1]+mxr[o<<1]);
	}
	void bd(int o,int l,int r){
		if(l==r){
			sum[o]=mxl[o]=mxr[o]=mx[o]=a[l]*t;
		}else{
			int mid=(l+r)>>1;
			bd(o<<1,l,mid);bd(o<<1|1,mid+1,r);
			up(o);
		}
	}
	void change(int o,int l,int r,int pos){
		if(l==r){
			sum[o]=mxl[o]=mxr[o]=mx[o]=a[l]*t;
		}else{
			int mid=(l+r)>>1;
			if(pos<=mid) change(o<<1,l,mid,pos);else change(o<<1|1,mid+1,r,pos);
			up(o);	
		}
	}
	
}Tmn,Tmx;
int m;
int main(){
	Tmn.t=-1;Tmx.t=1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) read(a[i]);
	Tmn.bd(1,1,n);
	Tmx.bd(1,1,n);
	for(int i=1;i<=n;i++) Sum+=a[i];
	read(m);
	for(int i=1,x,y;i<=m;i++){
		read(x);read(y);
		Sum-=a[x];Sum+=y;
		a[x]=y;
		Tmx.change(1,1,n,x);
		Tmn.change(1,1,n,x);
		int ans=0x7fffffff;
		ans++;
		if(Tmx.mx[1]!=Sum) ans=max(ans,Tmx.mx[1]);
		if(Tmn.mx[1]!=-Sum) ans=max(ans,Sum+Tmn.mx[1]);
		printf("%d\n",ans);
	}
	return 0;
}
