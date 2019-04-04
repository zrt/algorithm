#include<cstdio>
#include<algorithm>
#include<cstring>
//by zrt

using namespace std;
typedef long long LL;
int R,B,G,m,p,n;
int qpow(int a,int b,int p){
	int ret=1;
	while(b){
		if(b&1) ret=ret*1LL*a%p;
		a=a*1LL*a%p;
		b>>=1;
	}
	return ret;
}
int a[65];
int f[25][25][25];
int g[65],tot;
bool vis[65];
int calc(){
	memset(f,0,sizeof f);
	memset(vis,0,sizeof vis);
	f[0][0][0]=1;
	tot=0;int cnt=0;
	for(int i=1,x;i<=n;i++){
		if(!vis[i]){
			x=i;cnt=1;
			vis[x]=1;
			while(i!=a[x]){
				x=a[x];cnt++;
				vis[x]=1;
			}
			g[tot++]=cnt;
		}
	}
	for(int t=0;t<tot;t++){
		for(int i=R;i>=0;i--){
			for(int j=G;j>=0;j--){
				for(int k=B;k>=0;k--){
					if(i>=g[t]){
						f[i][j][k]+=f[i-g[t]][j][k];
						f[i][j][k]%=p;
					}
					if(j>=g[t]){
						f[i][j][k]+=f[i][j-g[t]][k];
						f[i][j][k]%=p;
					}
					if(k>=g[t]){
						f[i][j][k]+=f[i][j][k-g[t]];
						f[i][j][k]%=p;
					}
				}
			}
		}
	}
	return f[R][G][B];
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d%d%d%d",&R,&B,&G,&m,&p);
	n=R+B+G;
	int sum=0;
	for(int i=0;i<m;i++){
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		sum=(sum+calc())%p;
	}
	for(int i=1;i<=n;i++) a[i]=i;
	sum=(sum+calc())%p;
	printf("%lld\n",sum*1LL*qpow(m+1,p-2,p)%p);
	return 0;
}
