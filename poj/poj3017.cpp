#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
//by zrt
//problem:
using namespace std;
typedef long long LL;
LL n,m;
LL x[100005];
const LL inf=1LL<<62;
int h,t;
int q[100005];
LL f[100005];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%lld%lld",&n,&m);
	int k=0,kk;
	LL cnt=0;
	for(int i=1;i<=n;i++){
		scanf("%lld",&x[i]);
		if(x[i]>m) {
			puts("-1");
			return 0;
		}
		cnt+=x[i];
		while(cnt>m) cnt-=x[++k];
		while(t>=h&&x[q[t]]<=x[i]) t--;
		q[++t]=i;
		while(t>=h&&q[h]<=k) h++;
		f[i]=inf;
		kk=k;
		for(int j=h;j<=t;j++){
			LL tmp=f[kk]+x[q[j]];
			if(tmp<f[i]) f[i]=tmp;
			kk=q[j];
		}
	}
	printf("%lld\n",f[n]);
	return 0;
}
