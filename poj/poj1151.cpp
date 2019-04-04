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
struct N{
	ld x;
	ld y1,y2;
	int t;
	friend bool operator< (N a,N b){
		return a.x<b.x;
	}
}a[205];
int tot;
ld to[205];
int cc;
int kase;
ld sum[205*4];
int num[205*4];
void add(int o,int l,int r,int L,int R,int t){
	if(L==R) return;
	if(l==L&&r==R){
		num[o]+=t;
		if(num[o]>0) sum[o]=to[r]-to[l];
		else sum[o]=sum[o<<1]+sum[o<<1|1];
	}else{
		int mid=(l+r)>>1;
		if(R<=mid) add(o<<1,l,mid,L,R,t);
		else if(L>mid) add(o<<1|1,mid,r,L,R,t);
		else add(o<<1,l,mid,L,mid,t),add(o<<1|1,mid,r,mid,R,t);
		if(num[o]>0) sum[o]=to[r]-to[l];
		else sum[o]=sum[o<<1]+sum[o<<1|1];
	}
}
int get(ld x){
	return lower_bound(to+1,to+cc+1,x)-to;
}
int main(){
	while(scanf("%d",&n),n){
		cc=0;tot=0;
		ld x1,y1,x2,y2;
		for(int i=0;i<n;i++){
			read(x1);read(y1);read(x2);read(y2);
			to[++cc]=y1;to[++cc]=y2;
			++tot;
			a[tot].x=x1;a[tot].t=1;
			a[tot].y1=y1;a[tot].y2=y2;
			++tot;
			a[tot].x=x2;a[tot].t=-1;
			a[tot].y1=y1;a[tot].y2=y2;
		}
		sort(to+1,to+cc+1);
		cc=unique(to+1,to+cc+1)-(to+1);
		sort(a+1,a+tot+1);
		memset(sum,0,sizeof sum);
		memset(num,0,sizeof num);
		ld last=a[1].x;
		ld ans=0;
		for(int i=1;i<=tot;i++){
			ans+=(a[i].x-last)*sum[1];
			add(1,1,cc,get(a[i].y1),get(a[i].y2),a[i].t);
			last=a[i].x;
		}
		printf("Test case #%d\nTotal explored area: %.2f \n\n",++kase,(double)ans);
		
	}
	return 0;
}
