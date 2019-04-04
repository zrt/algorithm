#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

//by zrt
//problem:
using namespace std;
typedef long long LL;
const int inf(0x3f3f3f3f);
const double eps(1e-9);
int lastans;
int n;
int debug;
struct solve{
	int tot;
	double k[100005],b[100005];
	int num[400000];
	double get(int num,int pos){
		return k[num]*pos+b[num];
	}
	void add(int o,int l,int r,int L,int R,int tot){
		if(num[o]){
			if(get(num[o],L)>get(tot,L)&&get(num[o],R)>get(tot,R)) return;
		}
		if(L==l&&R==r){
			if(num[o]){
				int m=(l+r)>>1;
				double oldl,oldr,oldm,nowl,nowr,nowm;
				oldl=get(num[o],l);oldr=get(num[o],r);oldm=get(num[o],m);
				nowl=get(tot,l);nowr=get(tot,r);nowm=get(tot,m);
				if(nowl>=oldl&&nowr>=oldr){
					num[o]=tot;return;
				}else{
					if(nowm>oldm) {swap(tot,num[o]);swap(oldl,nowl);swap(oldr,nowr);}
					if(nowl>=oldl){
						add(o<<1,l,m,l,m,tot);
					}else add(o<<1|1,m+1,r,m+1,r,tot);
				}
			}else{
				num[o]=tot;
			}
		}else{
			int m=(l+r)>>1;
			if(R<=m){
				add(o<<1,l,m,L,R,tot);
			}else if(L>m){
				add(o<<1|1,m+1,r,L,R,tot);
			}else{
				add(o<<1  ,l  ,m,L  ,m,tot);
				add(o<<1|1,m+1,r,m+1,R,tot);
			}
		}
	}
	
	void insert(int x0,int y0,int x1,int y1){
//		printf("%d %d %d %d\n",x0,y0,x1,y1);
		tot++;
		if(x0>x1){
			swap(x0,x1);swap(y0,y1);
		}
		if(x0!=x1) k[tot]=(y1-y0)/(double)(x1-x0);
		else k[tot]=0;
		b[tot]=y0-k[tot]*x0;
		add(1,1,40000,x0,x1,tot);
	}
	double ans;int anspos;
	int ask(int x){
//		printf("Ask %d\n",x);
		
		ans=0;anspos=0;
		int o=1,l=1,r=40000,m;
		while(l!=r){
			m=(l+r)>>1;
			if(num[o]){
				double now=get(num[o],x);
				if(now>ans) ans=now,anspos=num[o];
			}
			if(x<=m){
				o<<=1;
				r=m;
			}else{
				o=o<<1|1;
				l=m+1;
			}
		}
		if(num[o]){
			double now=get(num[o],x);
			if(now>ans) ans=now,anspos=num[o];
		}
		return anspos;
	}
}solve;
int e9=1000000000;

int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&n);
//	solve.init();
	int k;
	for(int i=0,x;i<n;i++){
		scanf("%d",&x);
		if(x){
			int x0,y0,x1,y1;
			scanf("%d%d%d%d",&x0,&y0,&x1,&y1);
			solve.insert((x0+lastans-1)%39989+1,(y0+lastans-1)%e9+1,(x1+lastans-1)%39989+1,(y1+lastans-1)%e9+1);
		}else{
			scanf("%d",&k);
			x=(k+lastans-1)%39989+1;
			lastans=solve.ask(x);
			printf("%d\n",lastans);
		}
	}
//	printf("%f\n%f\n",solve.get(30500,33613),solve.get(30501,33613));
	return 0;
}
