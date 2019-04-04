#include<cstdio>
#include<cstring>
#include<algorithm>
//by zrt
//problem:
using namespace std;
typedef long long ll;
const double eps(1e-10);
int n,m;
int H[20005],X[110005],P[110005],flow[110005],d[20005],tot;
int q[20005],h,t;
int a[10005],b[10005];
int S,T;
inline void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;flow[tot]=z;
}
bool bfs(){
	memset(d,0,sizeof d);h=t=0;
	d[S]=1;q[t++]=S;
	int k;
	while(h!=t){
		k=q[h++];
		for(int i=H[k];i;i=X[i]){
			if(flow[i]>0&&(!d[P[i]])){
				q[t++]=P[i];
				d[P[i]]=d[k]+1;
			}
		}
	}
	return d[T];
}
int dfs(int x,int a){
	if(a==0||x==T) return a;
	int f=a,tmp;
	for(int i=H[x];i&&a;i=X[i]){
		if(d[P[i]]==d[x]+1&&flow[i]>0){
			tmp=dfs(P[i],min(a,flow[i]));
			a-=tmp;
			flow[i]-=tmp;
			flow[i^1]+=tmp;
		}
	}
	if(f==a) d[x]=-1;
	return f-a;
}
int dinic(){
	int f(0);
	while(bfs()){
		f+=dfs(S,1<<30);
	}
	return f;
}
bool judge(int x){
	memset(H,0,sizeof H);tot=1;
	for(int i=0;i<m;i++){
		add(S,i,1);add(i,S,0);
		add(i,a[i]+m,1);add(a[i]+m,i,0);
		add(i,b[i]+m,1);add(b[i]+m,i,0);
	}
	for(int i=1;i<=n;i++) add(i+m,T,x),add(T,i+m,0);
	if(dinic()>=m) return true;
	else return false;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d",&a[i],&b[i]);
	}
	int L(0),R(m),M;
	S=20003,T=20004;
	while(R-L>1){
		M=(L+R)>>1;
		if(judge(M)){
			R=M;
		}else L=M;
	}
	printf("%d\n",R);
	return 0;
}
