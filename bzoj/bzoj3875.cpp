#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

typedef long long LL;
#define int LL
int n;
vector<int> v[200005];
bool inq[200005];
int d[200005];
//int sum[200005];
int s[200005],k[200005];
int H[200005],X[1000005],P[1000005],tot;
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
queue<int> q;
#undef int
int main(){
	#define int LL
	scanf("%lld",&n);
	for(int i=1,r;i<=n;i++){
		scanf("%lld%lld%lld",&s[i],&k[i],&r);
		for(int j=0,x;j<r;j++){
			scanf("%lld",&x);
			add(x,i);v[i].push_back(x);
		}
		d[i]=k[i];
	}
	for(int i=1;i<=n;i++) inq[i]=1,q.push(i);
	while(!q.empty()){
		int x=q.front();q.pop();
		inq[x]=0;
		int tmp=0;
		for(int j=0;j<v[x].size();j++) tmp+=d[v[x][j]];
		tmp+=s[x];
		if(tmp<d[x]){
			d[x]=tmp;
			for(int i=H[x];i;i=X[i]){
				if(!inq[P[i]]) q.push(P[i]),inq[P[i]]=1;
			}
		}
	}
	printf("%lld\n",d[1]);
	return 0;
}
