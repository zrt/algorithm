#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m;
int a[70005];
int Pos[110][70005];
int rt[110];
int cc;
const int inf=0x3f3f3f3f;
int ls[20000500],rs[20000500],mx[20000500];
void cg(int&o,int l,int r,int pos,int d){
	if(!o) o=++cc;
	if(l==r){
		mx[o]+=d;
	}else{
		int mid=(l+r)>>1;
		if(pos<=mid) cg(ls[o],l,mid,pos,d);
		else cg(rs[o],mid+1,r,pos,d);
		mx[o]=max(mx[ls[o]],mx[rs[o]]);
	}
}
int ask(int o,int l,int r,int L,int R){
	if(l==L&&r==R) return mx[o];
	else{
		int mid=(l+r)>>1;
		if(R<=mid) return ask(ls[o],l,mid,L,R);
		else if(L>mid) return ask(rs[o],mid+1,r,L,R);
		else return max(ask(ls[o],l,mid,L,mid),ask(rs[o],mid+1,r,mid+1,R));
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	int E=min(sqrt((double)n/log2(n)),4.0);
	mx[0]=-inf;
	for(int i=1;i<=E;i++){
		int cnt=0;
		for(int j=1;j<=i;j++){
			for(int k=0;j+k*i<=n;k++){
				Pos[i][j+k*i]=++cnt;
				cg(rt[i],1,n,cnt,a[j+k*i]);
			}
		}
	}
	scanf("%d",&m);
	while(m--){
		int t,x,y;
		scanf("%d%d%d",&t,&x,&y);
		if(!t){
			for(int i=1;i<=E;i++){
				cg(rt[i],1,n,Pos[i][x],y);
			}
			a[x]+=y;
		}else{
			if(y<=E){
				int l=Pos[y][x],r=Pos[y][x+(n-x)/y*y];
				int ret=ask(rt[y],1,n,l,r);
				printf("%d\n",ret);
			}else{
				int ret=-inf;
				for(;x<=n;x+=y) ret=max(ret,a[x]);
				printf("%d\n",ret);
			}
		}
	}
	return 0;
}
