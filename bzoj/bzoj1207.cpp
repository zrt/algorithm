#include<cstdio>
#include<cstring>
#include<algorithm>
#include<algorithm>
//by zrt
//problem:
using namespace std;
int m;
int t[10005],x[10005],y[10005];
int f[10005];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%*d%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&t[i],&x[i],&y[i]);
	}
	int ans=1;
	for(int i=1;i<=m;i++){
		f[i]=1;
		for(int j=1;j<i;j++){
			if(abs(x[i]-x[j])+abs(y[i]-y[j])<=t[i]-t[j]) f[i]=max(f[i],f[j]+1);
		}
		ans=max(ans,f[i]);
	}
	
	printf("%d\n",ans);
	return 0;
}
