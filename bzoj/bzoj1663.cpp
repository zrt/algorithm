#include<cstdio>
#include<algorithm>
#include<cstring>
//by zrt
//problem:
using namespace std;
const int inf=(1<<30);
typedef long long LL;
const double eps=1e-8;
int n;
int p[405];
int f[405];
int map[405][405];
int a[405];
bool cmp(int a,int b){
	return p[a]<p[b];
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&p[i]);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) scanf("%d",&map[i][j]);
	}
	for(int i=1;i<=n;i++) a[i]=i;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++) if(map[1][i]<=p[i]) f[i]=1;
	f[1]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			if(map[a[j]][a[i]]<=p[a[i]]-p[a[j]]){
				f[a[i]]=max(f[a[i]],f[a[j]]+1);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++) ans=max(ans,f[i]);
	printf("%d\n",ans);
	return 0;
}
