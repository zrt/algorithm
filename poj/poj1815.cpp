#include <cstdio>
#include <algorithm>
#include <cctype>
//  by zrt
//  problem:
using namespace std ;
typedef long long LL ;
const double eps(1e-10) ;
const int inf(0x3f3f3f3f) ;
int n,S,T;
int map[205][205];
int H[405],X[160000],P[160000],tot,flow[160000];
int q[4050],h,t;
int floww[160000];
inline void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;flow[tot]=z;
}
int d[406];
bool bfs(){
	for(int i=2;i<=(n<<1|1);i++) d[i]=0;
	h=t=0;
	d[S]=1;q[t++]=S;
	while(h!=t){
		int x=q[h++];
		for(int i=H[x];i;i=X[i]){
			if(flow[i]>0&&!d[P[i]]){
				d[P[i]]=d[x]+1;
				q[t++]=P[i];
			}
		}
	}
	return d[T];
}
int dfs(int x,int a){
	int f=a,tmp;
	if(x==T||a==0) return a;
	for(int i=H[x];i;i=X[i]){
		if(flow[i]>0&&d[P[i]]==d[x]+1){
			tmp=dfs(P[i],min(a,flow[i]));
			a-=tmp;
			flow[i]-=tmp;
			flow[i^1]+=tmp;
			if(!a) break;
		}
	}
	if(f==a) d[x]=-1;
	return f-a;
}
int Dinic(){
	int f=0;
	while(bfs()) f+=dfs(S,inf);
	return f;
}
int scan(){
	static char x;
	static int n;
	while(x=getchar(),!isdigit(x));
	n=x-'0';
	while(x=getchar(),isdigit(x)){
		n=n*10+x-'0';
	}
	return n;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin) ;
	freopen("out.txt","w",stdout) ;
	#endif
	tot=1;
	n=scan();S=scan();T=scan();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			map[i][j]=scan();
		}
	}
	if(map[S][T]) {
		puts("NO ANSWER!");
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(i!=S&&i!=T){
			add(i<<1,i<<1|1,1);
			add(i<<1|1,i<<1,0);
		}else{
			add(i<<1,i<<1|1,inf);
			add(i<<1|1,i<<1,0);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=n;j>=1;j--){
			if(map[i][j]){
				add(i<<1|1,j<<1,inf);
				add(j<<1,i<<1|1,0);
			}
		}
	}
	for(int i=2;i<=tot;i++) floww[i]=flow[i];
	S=S<<1;T=T<<1|1;
	int ans=Dinic();
	printf("%d\n",ans);
	for(int i=1;i<=n;i++){
		if(i!=S>>1&&i!=T>>1&&flow[i<<1]==0){
			for(int j=2;j<=tot;j++) flow[j]=floww[j];
			flow[i<<1]=0;
			if(Dinic()!=ans){
				ans--;
				floww[i<<1]=0;
				printf("%d ",i);
			}
		}
	}
	return 0 ;
}
