#include<cstdio>
#include<cstring>
#include<algorithm>
//by zrt
//problem:
using namespace std;
typedef long long ll;
const double eps(1e-10);
int n,m;
int H[200005],P[1000005],X[1000005],tot;
int vis[200005];
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
bool ok(1);
int now;
void find(int x){
	vis[now]++;
	for(int i=H[x];i;i=X[i]){
		if(!vis[P[i]]){
			vis[P[i]]=1;
			find(P[i]);
		}
	}
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&n,&m);
	int x,y;
	while(m--){
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	for(int i=1;i<=n&&ok;i++){
		if(!vis[i]){
			vis[i]=1;
			now=i;
			find(i);
			if(vis[i]==2) ok=0;
		}
	}
	if(ok) puts("TAK");
	else puts("NIE");
	return 0;
}
