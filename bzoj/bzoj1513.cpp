#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=705;
int yl,yr;
int n,m,q;
struct seg{
	int mx[maxn<<2],tag[maxn<<2];
	int q(int o,int l,int r,int x,int y){
		if(l==x&&r==y) return max(mx[o],tag[o]);
		int mid=(l+r)>>1;
		if(y<=mid) return max(tag[o],q(o<<1,l,mid,x,y));
		else if(x>mid) return max(tag[o],q(o<<1|1,mid+1,r,x,y));
		else{
			return max(tag[o],max(q(o<<1,l,mid,x,mid),q(o<<1|1,mid+1,r,mid+1,y)));
		}
	}
	void c(int o,int l,int r,int x,int y,int z){
		mx[o]=max(mx[o],z);
		if(l==x&&r==y) tag[o]=max(tag[o],z);
		else{
			int mid=(l+r)>>1;
			if(y<=mid) c(o<<1,l,mid,x,y,z);
			else if(x>mid) c(o<<1|1,mid+1,r,x,y,z);
			else{
				c(o<<1,l,mid,x,mid,z);
				c(o<<1|1,mid+1,r,mid+1,y,z);
			}
		}
	}
};
struct segg{
	seg mx[maxn<<2],tag[maxn<<2];
	int q(int o,int l,int r,int x,int y){
		if(l==x&&r==y){
			return max(mx[o].q(1,1,m,yl,yr),tag[o].q(1,1,m,yl,yr));
		}else{
			int ans=tag[o].q(1,1,m,yl,yr);
			int mid=(l+r)>>1;
			if(y<=mid) return max(ans,q(o<<1,l,mid,x,y));
			else if(x>mid) return max(ans,q(o<<1|1,mid+1,r,x,y));
			else{
				return max(ans,max(q(o<<1,l,mid,x,mid),q(o<<1|1,mid+1,r,mid+1,y)));
			}
		}
	}
	void c(int o,int l,int r,int x,int y,int z){
		mx[o].c(1,1,m,yl,yr,z);
		if(l==x&&r==y){
			tag[o].c(1,1,m,yl,yr,z);
		}else{
			int mid=(l+r)>>1;
			if(y<=mid) c(o<<1,l,mid,x,y,z);
			else if(x>mid) c(o<<1|1,mid+1,r,x,y,z);
			else{
				c(o<<1,l,mid,x,mid,z);
				c(o<<1|1,mid+1,r,mid+1,y,z);
			}
		}
		
	}
}a;
int d,s,w,x,y;
int main(){
	scanf("%d%d%d",&n,&m,&q);
	while(q--){
		scanf("%d%d%d%d%d",&d,&s,&w,&x,&y);
		yl=y+1;yr=y+s;
		int p=a.q(1,1,n,x+1,x+d);
		a.c(1,1,n,x+1,x+d,p+w);
	}
	yl=1,yr=m;
	printf("%d\n",a.q(1,1,n,1,n));
	return 0;
}
