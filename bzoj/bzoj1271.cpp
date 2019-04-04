#include<cstdio>
#include<algorithm>
#include<cstring>
//by zrt

using namespace std;
typedef long long LL;
int tt;
int n;
int s[200005],e[200005],d[200005];
int sum(int pos){
	int ret=0;
	for(int i=1;i<=n;i++){
		if(s[i]>pos) continue;
		ret+=(min(pos,e[i])-s[i])/d[i]+1;
	}
	return ret;
}
bool judge(int pos){//odd true
	return sum(pos)&1;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&tt);
	while(tt--){
		scanf("%d",&n);
		int l,r;
		for(int i=1;i<=n;i++) scanf("%d%d%d",&s[i],&e[i],&d[i]);
		if(!judge(0x7fffffff)) {
			puts("Poor QIN Teng:(");
			goto ed;
		}
		l=-1;r=0x7fffffff;
		while(r-l*1LL>1){
			int mid=(l+1LL*r)/2;
			if(judge(mid)){
				r=mid;
			}else{
				l=mid;
			}
		}
		printf("%d %d\n",r,sum(r)-sum(r-1));
		ed:;
	}
	
	
	return 0;
}
