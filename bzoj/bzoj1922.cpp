#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int n,m;
typedef long long LL;
int H[3005],X[70005],P[70005],tot;
LL E[70005];
LL d[70005],d2[70005],in[70005];
//d daoda / d2 ke jin ru
inline void add(int x,int y,LL z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;E[tot]=z;
}
vector<int> v[3005];
bool vis[3005];
struct N{
	int x;
	LL w;
	N(int a=0,LL b=0){
		x=a,w=b;
	}
	friend bool operator < (const N&a,const N&b){
		return a.w>b.w;
	}
};
priority_queue<N> q;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0,x,y,z;i<m;i++){
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
	}
	for(int i=1,t;i<=n;i++){
		scanf("%d",&t);
		for(int j=0,x;j<t;j++){
			scanf("%d",&x);
			v[x].push_back(i);
			in[i]++;
		}
	}
	memset(d,0x3f,sizeof d);
	d[1]=d2[1]=0;
	q.push(N(1,0));
	while(!q.empty()){
		int x=q.top().x;q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		d[x]=max(d[x],d2[x]);
	//	printf("%d %lld\n",x,d[x]);
		for(int i=0;i<v[x].size();i++){
			in[v[x][i]]--;
			d2[v[x][i]]=max(d2[v[x][i]],d[x]);
			if(!in[v[x][i]]) q.push(N(v[x][i],max(d[v[x][i]],d2[v[x][i]])));
		}
		for(int i=H[x];i;i=X[i]){
			if(d[P[i]]>d[x]+E[i]){
				d[P[i]]=d[x]+E[i];
				if(in[P[i]]==0) q.push(N(P[i],max(d2[P[i]],d[P[i]])));
			}
		}
	}
	printf("%lld\n",d[n]);
	return 0;
}
