#include<cstdio>
#include<algorithm>
#include<cstring>
//by zrt
//problem:
using namespace std;
const int inf=(1<<30);
typedef long long LL;
const double eps=1e-8;
#define lowbit(x) ((x)&-(x))
struct N{
	int l,r,id,ans;
	friend bool operator < (N a,N b){
		return a.r<b.r;
	}
}q[1000005];
int n,c,m;
int a[1000005];
int pre[1000005];
int last[1000005];
int bst[1000005];
void add(int pos,int k){
	while(pos>0){
		bst[pos]+=k;
		pos-=lowbit(pos);
	}
}
int ask(int pos){
	int ret=0;
	while(pos<=n){
		ret+=bst[pos];
		pos+=lowbit(pos);
	}
	return ret;
}
bool cmp(N a,N b){
	return a.id<b.id;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	
	scanf("%d%d%d",&n,&c,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		pre[i]=last[a[i]];
		last[a[i]]=i;
	}
	for(int i=0;i<m;i++){
		scanf("%d%d",&q[i].l,&q[i].r);q[i].id=i;
	}
	sort(q,q+m);
	int p=1;
	for(int i=0;i<m;i++){
		for(;p<=q[i].r;p++){
			add(pre[pre[p]],-1);
			add(pre[p],1);
		}
		q[i].ans=ask(q[i].l);
	}
	sort(q,q+m,cmp);
	for(int i=0;i<m;i++) printf("%d\n",q[i].ans);
	return 0;
}
