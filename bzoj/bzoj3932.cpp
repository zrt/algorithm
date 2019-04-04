//主席树
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
LL sum[10000000];
int ls[10000000],rs[10000000],tt,siz[10000000];
int rt[100005];
struct N{
	int x,w;
	friend bool operator < (const N&a,const N&b){
		return a.x<b.x;
	}
}a[100005*2];
int n,m,tot;
int to[100005],cc;
inline int add(int o,int l,int r,int p,int t){
	int now=++tt;
	if(l==r){
		siz[now]=siz[o]+t;
		sum[now]=sum[o]+t*to[p];
	}else{
		int mid=(l+r)>>1;
		if(p<=mid) ls[now]=add(ls[o],l,mid,p,t),rs[now]=rs[o];
		else rs[now]=add(rs[o],mid+1,r,p,t),ls[now]=ls[o];
		siz[now]=siz[ls[now]]+siz[rs[now]];
		sum[now]=sum[ls[now]]+sum[rs[now]];
	}
	return now;
}
LL ask(int o,int l,int r,int k){
	if(l==r){
		return min(k*1LL*to[l],sum[o]);
	}else{
		int mid=(l+r)>>1;
		if(siz[ls[o]]>=k) return ask(ls[o],l,mid,k);
		else return sum[ls[o]]+ask(rs[o],mid+1,r,k-siz[ls[o]]);
	}
}
int main(){
	scanf("%d%d",&m,&n);
	for(int i=0,s,e,p;i<m;i++){
		scanf("%d%d%d",&s,&e,&p);
		a[tot].x=s,a[tot].w=p;tot++;
		a[tot].x=e+1,a[tot].w=-p;tot++;
		to[i+1]=p;
	}
	sort(a,a+tot);
	sort(to+1,to+m+1);
	//for(int i=1;i<=m;i++) printf("%d\n",to[i]);
	cc=unique(to+1,to+m+1)-(to+1);
	int j=0;
	for(int i=1;i<=n;i++){
		int now=rt[i-1];
		while(j<tot&&a[j].x==i){
			if(a[j].w>0){
				now=add(now,1,cc,lower_bound(to+1,to+cc+1,a[j].w)-to,1);
			}else{
				now=add(now,1,cc,lower_bound(to+1,to+cc+1,-a[j].w)-to,-1);
			}
			j++;
		}
		rt[i]=now;
	}
	LL ans=1;
	for(int i=0,x,a,b,c;i<n;i++){
		scanf("%d%d%d%d",&x,&a,&b,&c);
		printf("%lld\n",ans=ask(rt[x],1,cc,(a*ans+b)%c+1));
	}
	return 0;
}
/*
4 3
1 2 6
2 3 3
1 3 2
3 3 4
3 1 3 2
1 1 3 4
2 2 4 3

*/
