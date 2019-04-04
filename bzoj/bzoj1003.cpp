#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
//by zrt
//problem:
using namespace std;
typedef long long LL;
const int inf(0x3f3f3f3f);
const double eps(1e-9);
int t,n,k,m,c;
int F[105];
int H[25],X[805],P[805],tot,E[805];
bool no[805];
inline void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;E[tot]=z;
}
int d[25];
struct node{
	int x,a,b;
	node(int xx,int aa,int bb){
		x=xx,a=aa,b=bb;
	}
};
vector<node> v;
struct N{
	int x,w;
	N(int a=0,int b=0){
		x=a,w=b;
	}
	friend bool operator < (N a,N b){
		return a.w>b.w;
	}
};
priority_queue<N> q;
bool vis[25];
int cost(int i,int j){//from i to j
	memset(d,0x3f,sizeof d);
	int L=j-i+1;
	d[1]=0;
	memset(no,0,sizeof no);
	for(int a=0;a<c;a++){
		if(!(v[a].b<i||v[a].a>j)){
			no[v[a].x]=1;
		}
	}
	memset(vis,0,sizeof vis);
	q.push(N(1,0));
	int x;
	while(!q.empty()){
		x=q.top().x;q.pop();
		if(vis[x]) continue;else vis[x]=1;
		for(int i=H[x];i;i=X[i]){
			if(!no[P[i]]&&d[P[i]]>d[x]+E[i]){
				d[P[i]]=d[x]+E[i];
				q.push(N(P[i],d[P[i]]));
			}
		}
	}
	if(d[n]==inf) return inf/L;
	return d[n];
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d%d%d",&t,&n,&k,&m);
	for(int i=0,x,y,z;i<m;i++){
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
	scanf("%d",&c);
	v.reserve(c);
	for(int i=0,x,a,b;i<c;i++){
		scanf("%d%d%d",&x,&a,&b);
		v.push_back(node(x,a,b));
	}
	memset(F,0x3f,sizeof F);
	F[0]=-k;
	for(int i=1;i<=t;i++){
		for(int j=1;j<=i;j++){
			if(F[j-1]>=inf) continue;
			F[i]=min(F[i],F[j-1]+k+cost(j,i)*(i-j+1));
		}
	}
	printf("%d\n",F[t]);
	return 0;
}
