#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

//by zrt
//problem:
using namespace std;
typedef long long LL;
const int inf(0x3f3f3f3f);
const double eps(1e-9);
int n,m;
int a[1000005];
int H[1000005];
int X[1000005];
int num[1000005];
int to[1000005];
int ans;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	for(int i=1;i<1000005;i++) to[i]=i;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),num[a[i]]++;
	for(int i=1;i<=n;i++) if(a[i]!=a[i-1]) ans++;
	for(int i=1;i<=n;i++){
		X[i]=H[a[i]];H[a[i]]=i;
	}
	int x,y;
	while(m--){
		scanf("%d",&x);
		if(x&1){
			scanf("%d%d",&x,&y);
			if(x==y) continue;
			if(num[to[x]]>num[to[y]]) swap(to[x],to[y]);
			x=to[x];y=to[y];
			if(!num[x]) continue;
			for(int i=H[x];i;i=X[i]){
				if(a[i]!=a[i-1]) ans--;
				if(i!=n&&a[i]!=a[i+1]) ans--;
			}
			for(int i=H[x];i;i=X[i]) a[i]=y;
			int head;
			for(int i=H[x];i;i=X[i]){
				if(a[i]!=a[i-1]) ans++;
				if(i!=n&&a[i]!=a[i+1]) ans++;
				head=i;
			}
			num[y]+=num[x];num[x]=0;
			X[head]=H[y];H[y]=H[x];H[x]=0;
			
		}else{
			printf("%d\n",ans);
		}
	}
	
	return 0;
}
