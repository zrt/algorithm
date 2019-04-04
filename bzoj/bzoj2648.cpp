#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,D,root,x,y;
struct N{
	int d[2];
	int l,r;
	int min[2];
	int max[2];
}a[1000005];
bool cmp(const N&a,const N&b){
	if(a.d[D]!=b.d[D]) return a.d[D]<b.d[D];
	return a.d[D^1]<b.d[D^1];
}
inline void up(int k,int s){
	a[k].min[0]=min(a[k].min[0],a[s].min[0]);
	a[k].min[1]=min(a[k].min[1],a[s].min[1]);
	a[k].max[0]=max(a[k].max[0],a[s].max[0]);
	a[k].max[1]=max(a[k].max[1],a[s].max[1]);
}
int bd(int l,int r,int d){
	D=d;
	int mid=(l+r)>>1;
	nth_element(a+l,a+mid+1,a+r+1,cmp);
	a[mid].min[0]=a[mid].max[0]=a[mid].d[0];
	a[mid].min[1]=a[mid].max[1]=a[mid].d[1];
	if(l!=mid) a[mid].l=bd(l,mid-1,d^1);
	if(r!=mid) a[mid].r=bd(mid+1,r,d^1);
	if(a[mid].l) up(mid,a[mid].l);
	if(a[mid].r) up(mid,a[mid].r);
	return mid;
}
const int inf=0x7fffffff;
int ans;
int getdis(int k){
	int ret=0;
	if(x<a[k].min[0]) ret+=a[k].min[0]-x;
	if(x>a[k].max[0]) ret+=x-a[k].max[0];
	if(y<a[k].min[1]) ret+=a[k].min[1]-y;
	if(y>a[k].max[1]) ret+=y-a[k].max[1];
	return ret;
}
void ask(int k){
	int d0=abs(a[k].d[0]-x)+abs(a[k].d[1]-y);
	if(d0<ans) ans=d0;
	int d1=(a[k].l)?getdis(a[k].l):inf;
	int d2=(a[k].r)?getdis(a[k].r):inf;
	if(d1<d2){
		if(d1<ans) ask(a[k].l);
		if(d2<ans) ask(a[k].r);
	}else{
		if(d2<ans) ask(a[k].r);
		if(d1<ans) ask(a[k].l);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i].d[0],&a[i].d[1]);
	}
	root=bd(1,n,0);
	for(int i=0,t;i<m;i++){
		scanf("%d%d%d",&t,&x,&y);
		if(t==1){
			n++;
			a[n].min[0]=a[n].max[0]=a[n].d[0]=x;
			a[n].min[1]=a[n].max[1]=a[n].d[1]=y;
			int p=root,D=0;
			while(1){
				up(p,n);
				if(a[n].d[D]<a[p].d[D]){
					if(!a[p].l) {
						a[p].l=n;
						break;
					}else{
						p=a[p].l;
					}
				}else{
					if(!a[p].r) {
						a[p].r=n;
						break;
					}else{
						p=a[p].r;
					}
				}
				D^=1;
			}
		}else{
			ans=inf;
			ask(root);
			printf("%d\n",ans);
		}
	}
	return 0;
}
