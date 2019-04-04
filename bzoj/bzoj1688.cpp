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
int n,m,k;
int d[1005];
inline bool judge(int x){
	int c=0;
	while(x){
		c++;
		x&=(x-1);
	}
	return c<=k;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0,c;i<n;i++){
		scanf("%d",&c);
		for(int j=0,x;j<c;j++){
			scanf("%d",&x);
			d[i]|=1<<(x-1);
		}
	}
	int ans=0;
	for(int i=0;i<(1<<m);i++){
		
		if(judge(i)){
			int tot=0;
			for(int j=0;j<n;j++){
				if((d[j]|i)==i) tot++;
			}
			ans=max(ans,tot);
		}
	}
	printf("%d\n",ans);
	return 0;
}
