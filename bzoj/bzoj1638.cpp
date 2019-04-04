#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
//by zrt
//problem:
using namespace std;
typedef long long LL;
const int inf(0x3f3f3f3f);
const double eps(1e-9);
int in[5005];
int H[5005],X[50005],P[50005],tot;
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
int n,m;
int sum[5005],sum2[5005];
queue<int> q;
int x[50005],y[50005];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d",&x[i],&y[i]);
		in[y[i]]++;
		add(x[i],y[i]);
	}
	for(int i=1;i<=n;i++){
		if(!in[i]) sum[i]=1,q.push(i);
	}
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=H[x];i;i=X[i]){
			sum[P[i]]+=sum[x];
			in[P[i]]--;
			if(!in[P[i]]) q.push(P[i]);
		}
	}
	memset(in,0,sizeof in);
	tot=0;
	memset(H,0,sizeof H);
	for(int i=0;i<m;i++) add(y[i],x[i]),in[x[i]]++;
	sum2[n]=1;
	for(int i=1;i<=n;i++){
		if(!in[i]) q.push(i);
	}
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=H[x];i;i=X[i]){
			sum2[P[i]]+=sum2[x];
			in[P[i]]--;
			if(!in[P[i]]) q.push(P[i]);
		}
	}
	long long  maxx=0;
	for(int i=0;i<m;i++){
		maxx=max(maxx,sum[x[i]]*1LL*sum2[y[i]]);
	}
	printf("%lld\n",maxx);
	return 0;
}
