#include<cstdio>
#include<algorithm>
#include<cstring>
//by zrt
//problem:
using namespace std;
const int inf=(1<<30);
typedef long long LL;
const double eps=1e-8;
int mod=1000000000+9;
#define lowbit(x) ((x)&-(x))
int sum[100005],n;
int to[100005],tot;
int f[100005];
int c[100005];
void add(int pos,int k){
	while(pos<=n){
		c[pos]+=k;
		c[pos]%=mod;
		pos+=lowbit(pos);
	}
}
int ask(int pos){
	int ret=0;
	while(pos>0){
		ret+=c[pos];
		ret%=mod;
		pos-=lowbit(pos);
	}
	return ret;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&sum[i]);
		sum[i]+=sum[i-1];
		to[++tot]=sum[i];
	}
	sort(to+1,to+tot+1);
	tot=unique(to+1,to+tot+1)-(to+1);
	for(int i=1;i<=n;i++){
		int pos=lower_bound(to+1,to+tot+1,sum[i])-to;
		f[i]=((sum[i]>=0)+ask(pos))%mod;
		add(pos,f[i]);
	}
	printf("%d\n",f[n]);
	return 0;
}

