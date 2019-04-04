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
int tt;
int n,m;
struct N{
	int t,id;
	int x1,y1,x2,y2;
}a[50050],b[100050];
char s[10];
int ans[50050];
bool cmp(N a,N b){
	if(a.x1!=b.x1) return a.x1<b.x1;
	else return abs(a.t)>abs(b.t);
}
int c[1005];
#define lowbit(x) ((x)&-(x))
void add(int pos,int d){
	while(pos<=n){
		c[pos]+=d;
		pos+=lowbit(pos);
	}
}
int ask(int pos){
	int ret=0;
	while(pos>0){
		ret+=c[pos];
		pos-=lowbit(pos);
	}
	return ret;
}
void cdq(int l,int r){
	if(l==r) return ;
	int mid=(l+r)>>1;
	cdq(l,mid);cdq(mid+1,r);
	int tot=0;
	for(int i=l;i<=mid;i++){
		if(!a[i].t){
			b[++tot]=a[i];
			b[tot].t=1;
			b[++tot]=a[i];
			b[tot].x1=b[tot].x2+1;
			b[tot].t=-1;
		}
	}
	for(int i=mid+1;i<=r;i++){
		if(a[i].t){
			b[++tot]=a[i];
			b[tot].t=0;
		}
	}
	sort(b+1,b+tot+1,cmp);
	for(int i=1;i<=tot;i++){
		if(b[i].t){
			add(b[i].y2+1,b[i].t*-1);
			add(b[i].y1,b[i].t);
		}else{
			ans[b[i].id]^=ask(b[i].y1)&1;
		}
	}
}
int main(){
	read(tt);
	while(tt--){
		read(n);read(m);
		for(int i=1;i<=m;i++){
			scanf("%s",s);
			a[i].id=i;
			if(s[0]=='Q'){
				ans[i]=0;
				a[i].t=1;
				read(a[i].x1);read(a[i].y1);
			}else{
				a[i].t=0;
				ans[i]=-1;
				read(a[i].x1);read(a[i].y1);read(a[i].x2);read(a[i].y2);
			}
		}
		cdq(1,m);
		for(int i=1;i<=m;i++){
			if(ans[i]!=-1) printf("%d\n",ans[i]);
		}
		puts("");
	}
	
	
	return 0;
}
