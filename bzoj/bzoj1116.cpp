#include<cstdio>
#include<cstring>
#include<algorithm>
//by zrt
//problem:
using namespace std;
typedef long long ll;
const double eps(1e-10);
//dian >=3 liantong fenliang bixu you huan
int H[100005],P[400005],X[400005],tot;
int out[100005];
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
int cnt,siz[100005],belong[100005],bian[100005];
bool vis[100005];
void find(int x){
	vis[x]=1;siz[cnt]++;
	belong[x]=cnt;
	for(int i=H[x];i;i=X[i]){
		if(!vis[P[i]]){
			find(P[i]);
		}
	}
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0,x,y;i<m;i++){
		scanf("%d%d",&x,&y);
		out[x]++;out[y]++;
		add(x,y);add(y,x);
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			cnt++;
			find(i);
		}
	}
	for(int i=1;i<=n;i++){
		bian[belong[i]]+=out[i];
	}
	bool ok=1;
	for(int i=1;i<=cnt&&ok;i++){
		if(siz[i]<3) ok=0;
		if(bian[i]<siz[i]*2) ok=0;
	}
	if(ok) puts("TAK");
	else puts("NIE");
	return 0;
}
