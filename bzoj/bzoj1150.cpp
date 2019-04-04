#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
//by zrt
//problem:
using namespace std;
typedef long long LL;
const int inf(0x3f3f3f3f);
const double eps(1e-9);
int n,k;
int pos[100005];
int b[100005];
int l[100005],r[100005];
struct N{
	int x,w;
	friend bool operator < (N a,N b){
		if(a.w!=b.w) return a.w<b.w;
		return a.x<b.x;
	}
	N(int a=0,int b=0){
		x=a,w=b;
	}
};
set<N> heap;
set<N>::iterator it;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&n,&k);
	LL ans=0;
	for(int i=1;i<=n;i++) scanf("%d",&pos[i]),l[i]=i-1,r[i]=i+1;
	for(int i=1;i<n;i++) b[i]=pos[i+1]-pos[i],heap.insert(N(i,b[i]));
	b[0]=inf,b[n]=inf;
	heap.insert(N(0,b[0]));
	heap.insert(N(n,b[n]));
	while(k--){
		it=heap.begin();
		ans+=it->w;
		int now=it->x;
		heap.erase(*it);
		int pl=l[now],pr=r[now];
		l[now]=l[pl];r[now]=r[pr];
		r[l[now]]=now;l[r[now]]=now;
		b[now]=b[pl]+b[pr]-b[now];
		heap.insert(N(now,b[now]));
		heap.erase(N(pl,b[pl]));
		heap.erase(N(pr,b[pr]));
	}
	printf("%lld\n",ans);
	return 0;
}
