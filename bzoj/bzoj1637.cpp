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
struct Q{
	int a,b;
}q[50005];
int n;
bool cmp(Q a,Q b){
	return a.b<b.b;
}
int sum[50005];
int pos[100005];
int zero;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&q[i].a,&q[i].b);
	}
	zero=50000;
	sort(q+1,q+n+1,cmp);
	memset(pos,-1,sizeof pos);
	pos[zero]=0;
	int ans=0;
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+(q[i].a?1:-1);
		if(pos[sum[i]+zero]!=-1){
			ans=max(ans,q[i].b-q[pos[sum[i]+zero]+1].b);
		}else{
			pos[sum[i]+zero]=i;
		}
	}
	printf("%d\n",ans);
	return 0;
}
