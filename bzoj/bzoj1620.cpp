#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
//by zrt
//problem:
using namespace std;
int n;
struct N{
	int t,s;
	friend bool operator < (N a,N b){
		return a.s<b.s;
	}
}a[1005];
int minn=1<<30;
bool judge(int start){
	int t=start;
	for(int i=1;i<=n;i++){
		if(t+a[i].t>a[i].s) return 0;
		else t+=a[i].t;
	}
	return 1;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i].t,&a[i].s);
		minn=min(minn,a[i].s);
	}
	sort(a+1,a+n+1);
	int l=0,r=minn;
	if(!judge(0)){
		puts("-1");
		goto ed;
	}
	while(r-l>1){
		int m=(l+r)>>1;
		if(judge(m)){
			l=m;
		}else r=m;
	}
	printf("%d\n",l);
	ed:;return 0;
}
