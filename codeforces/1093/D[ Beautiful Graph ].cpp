#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n,m;
int H[300005],X[600005],P[600005], tot;
inline void add(int x,int y){
	P[++tot] = y;X[tot]=H[x];H[x]=tot;
}
int cnt[2];
int vis[300005];
bool gg = 0;
typedef long long LL;
void dfs(int x,int t){
	vis[x] = t+1;
	cnt[t] ++;
	for(int i=H[x];i;i=X[i]){
		if(!vis[P[i]]){
			dfs(P[i],1-t);
		}else{
			if(vis[P[i]]+vis[x] != 3){
				gg = 1;
				return;
			}
		}
	}
}
const LL mod = 998244353 ;
LL pow(LL a,LL b,LL p){
	LL ret=1%p;
	while(b){
		if(b&1) ret=ret*a%p;
		b>>=1;
		a=a*a%p;
	}
	return ret;
}
int main(){
	int tt;
	scanf("%d",&tt);
	while(tt--){
		tot = 0;
		gg = 0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) H[i] = 0;
		for(int i=1;i<=n;i++) vis[i] = 0;
		for(int i=0,x,y;i<m;i++){
			scanf("%d%d",&x,&y);
			add(x,y);add(y,x);
		}
		cnt[0] = cnt[1] = 0;
		LL ans=1;
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				cnt[0] = cnt[1] = 0;
				dfs(i,0);
				if(gg){
					break;
				}
				LL tmp = (pow(2,cnt[0],mod)+pow(2,cnt[1],mod))%mod;
				ans = ans*tmp%mod;
			}
		}
		if(gg){
			puts("0");
		}else printf("%d\n",(int)ans);
	}

	return 0;
}
