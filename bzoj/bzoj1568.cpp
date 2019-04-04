#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n=50000;
char s[10];
int best[50005<<2];
struct N{
	double s,p;
	double get(int x){
		return p*(x-1)+s;
	}
}a[100005];
double mx;
int tot;
void ask(int o,int l,int r,int pos){
	mx=max(mx,a[best[o]].get(pos));
	if(l==r){
		;
	}else{
		int mid=(l+r)>>1;
		if(pos<=mid) ask(o<<1,l,mid,pos);
		else ask(o<<1|1,mid+1,r,pos);
	}
}
void insert(int o,int l,int r,int x){
	if(x==0) return;
	if(l==r){
		if(a[x].get(l)>a[best[o]].get(l)) best[o]=x;
	}else{
		int mid=(l+r)>>1;
		if(a[x].get(mid)>a[best[o]].get(mid)){
			if(a[x].get(l)>a[best[o]].get(l)){
				insert(o<<1|1,mid+1,r,best[o]);
			}else{
				insert(o<<1,l,mid,best[o]);
			}
			best[o]=x;
		}else{
			if(a[x].get(l)>a[best[o]].get(l)){
				insert(o<<1,l,mid,x);
			}else{
				insert(o<<1|1,mid+1,r,x);
			}
		}
	}
}
int main(){
	scanf("%*d");
	while(~scanf("%s",s)){
		if(s[0]=='Q'){
			int x;
			mx=-1e10;
			scanf("%d",&x);
			ask(1,1,n,x);
			int ans=mx/100;
			printf("%d\n",ans);
		}else{
			int x=++tot;
			scanf("%lf%lf",&a[x].s,&a[x].p);
			insert(1,1,n,x);
		}
	}
	return 0;
}
