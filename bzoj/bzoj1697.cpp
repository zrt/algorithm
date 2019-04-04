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
int n;
int to[100005];
int a[10005];
int b[10005];
int mn;
bool vis[10005];
int solve(int x){
	int sum=a[x];
	vis[x]=1;
	int k=x;
	int minn=a[x];
	int l=1;
	for(k=to[b[k]];k!=x;k=to[b[k]]) minn=min(minn,a[k]),sum+=a[k],l++,vis[k]=1;
	return min(sum+(l-2)*minn,sum+minn+(l+1)*mn);
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&n);
	mn=inf;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		to[a[i]]=i;
		b[i]=a[i];
		mn=min(a[i],mn);
	}
	sort(b+1,b+n+1);
	int ans=0;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			ans+=solve(i);
		}
	}
	printf("%d\n",ans);
	return 0;
}
