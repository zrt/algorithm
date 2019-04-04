#include<cstdio>
#include<cstring>
#include<algorithm>
//by zrt
//problem:
using namespace std;
struct N{
	int f,c;
	friend bool operator < (N a,N b){
		return a.c<b.c;
	}
}a[105];
int k,e,n;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d%d",&k,&e,&n);
	for(int i=1,x,f,c;i<=n;i++){
		scanf("%d%d%d",&x,&f,&c);
		a[i].f=f;a[i].c=e-x+c;
	}
	sort(a+1,a+n+1);
	int num=0;
	int ans=0;
	for(int i=1;i<=n;i++){
		if(num==k) break;
		int tmp=min(k-num,a[i].f);
		ans+=tmp*a[i].c;
		num+=tmp;
	}
	printf("%d\n",ans);
	return 0;
}
