#include<cstdio>
#include<algorithm>
#include<cstring>
//by zrt
//problem:
using namespace std;
const int inf=(1<<30);
typedef long long LL;
const double eps=1e-8;
int trie[500005][2];
int end[500005];
int tot;
int sum[500005];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		int id=0;
		for(int j=0,k;j<x;j++){
			sum[id]++;
			scanf("%d",&k);
			if(trie[id][k]) id=trie[id][k];
			else id=trie[id][k]=++tot;
		}
		end[id]++;
	}
	for(int i=0;i<m;i++){
		int ans=0;
		int x;
		scanf("%d",&x);
		int id=0;
		for(int j=0,k;j<x;j++){
			ans+=end[id];
			scanf("%d",&k);
			if(trie[id][k]) id=trie[id][k];
			else{
				id=tot+1;
				for(j++;j<x;j++) scanf("%*d");
				break;
			}
		}
		printf("%d\n",ans+end[id]+sum[id]);
	}
	
	return 0;
}
