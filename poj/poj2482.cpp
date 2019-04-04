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
int n,W,H;
struct N{
	LL x,y,c;
	friend bool operator < (const N&a,const N&b){
		return a.x<b.x;
	}
}a[20005];
LL to[20005];int cc;
int get(LL x){
	return lower_bound(to+1,to+cc+1,x)-to;
}
int lazy[20005*4],mx[20005*4];

void do_add(int o,int d){
	mx[o]+=d;
	lazy[o]+=d;
}
void down(int o){
	if(lazy[o]){
		do_add(o<<1,lazy[o]);
		do_add(o<<1|1,lazy[o]);
		lazy[o]=0;
	}
}
void upd(int o){
	mx[o]=max(mx[o<<1],mx[o<<1|1]);
}
void add(int o,int l,int r,int L,int R,int d){
	if(l==L&&r==R){
		do_add(o,d);
	}else{
		int mid=(l+r)>>1;
		down(o);
		if(R<=mid) add(o<<1,l,mid,L,R,d);
		else if(L>mid) add(o<<1|1,mid+1,r,L,R,d);
		else add(o<<1,l,mid,L,mid,d),add(o<<1|1,mid+1,r,mid+1,R,d);
		upd(o);
	}
}
int main(){
	while(~scanf("%d%d%d",&n,&W,&H)){
		memset(mx,0,sizeof mx);
		memset(lazy,0,sizeof lazy);
		cc=0;
		for(int i=0;i<n;i++){
			read(a[i<<1].x);read(a[i<<1].y);read(a[i<<1].c);
			a[i<<1|1]=a[i<<1];
			a[i<<1|1].c*=-1;
			a[i<<1|1].x+=W;
			to[++cc]=a[i<<1].y;
			to[++cc]=a[i<<1].y+H-1;
		}
		sort(to+1,to+cc+1);
		cc=unique(to+1,to+cc+1)-(to+1);
		sort(a,a+2*n);
		int ans=0;
		for(int i=0;i<n*2;i++){
			int j=i;
			while(j<n*2-1&&a[j+1].x==a[i].x) j++;
			for(int k=i;k<=j;k++){
				add(1,1,cc,get(a[k].y),get(a[k].y+H-1),a[k].c);
			}
			ans=max(ans,mx[1]);
			i=j;
		}
		printf("%d\n",ans);
	}
	return 0;
}
