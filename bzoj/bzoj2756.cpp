#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
//  by zrt
//  problem:
//  无论你在什么时候开始，重要的是开始以后就不要停止。
using namespace std ;
typedef  long long LL ;
const double eps(1e-10) ;
const int inf(0x3f3f3f3f) ;
LL INF=123456789876LL;
bool f[45][45];
LL map[45][45];
int tt;
int n,m;LL sum;
inline int get(int x,int y){
	return (x-1)*m+y;
}
inline LL g(LL x){
	return (x*n*m-sum)>>1;
}
int H[2045],X[122250],P[122250],tot;LL flow[122250];
inline void add(int x,int y,LL z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;flow[tot]=z;
}
int S,T;
int d[2045];
queue<int> q;
bool bfs(){
	memset(d,0,sizeof d);
	d[S]=1;q.push(S);int x;
	while(!q.empty()){
		x=q.front();q.pop();
		for(int i=H[x];i;i=X[i]){
			if(flow[i]>0&&!d[P[i]]){
				d[P[i]]=d[x]+1;
				q.push(P[i]);
			}
		}
	}
	return d[T];
}
LL dfs(int x,LL a){
	if(x==T||a==0) return a;
	LL f=a,tmp;
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
LL Dinic(){
	LL f(0);
	while(bfs()) f+=dfs(S,INF);
	return f;
}
bool judge(LL x){
	tot=1;
	memset(H,0,sizeof H);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(f[i][j]){
				add(S,get(i,j),x-map[i][j]);
				add(get(i,j),S,0);
				//this 边要从白连向黑 
				if(i<n){
					add(get(i,j),get(i+1,j),INF);
					add(get(i+1,j),get(i,j),0);
				}
				if(j<m){
					add(get(i,j),get(i,j+1),INF);
					add(get(i,j+1),get(i,j),0);
				}
				if(i>1){
					add(get(i,j),get(i-1,j),INF);
					add(get(i-1,j),get(i,j),0);
				}
				if(j>1){
					add(get(i,j),get(i,j-1),INF);
					add(get(i,j-1),get(i,j),0);
				}
			}else{
				add(get(i,j),T,x-map[i][j]);
				add(T,get(i,j),0);
			}
			
		}
	}
	if(Dinic()==g(x)) return true;
	return false;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin) ;
	freopen("out.txt","w",stdout) ;
	#endif
	scanf("%d",&tt);S=0,T=2044;
	while(tt--){
		scanf("%d%d",&n,&m);
		LL maxx=0;sum=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				scanf("%lld",&map[i][j]);
			}
		}
		f[1][1]=1;
		for(int i=2;i<=n;i++){
			f[i][1]=f[i-1][1]^1;
		}
		for(int i=1;i<=n;i++){
			for(int j=2;j<=m;j++){
				f[i][j]=f[i][j-1]^1;
			}
		}
		LL cnt1=0,cnt2=0,sum1=0,sum2=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(map[i][j]>maxx) maxx=map[i][j];
				sum+=map[i][j];
				if(f[i][j]){
					cnt1++;
					sum1+=map[i][j];
				}else{
					cnt2++;
					sum2+=map[i][j];
				}
			}
		}
		if(cnt1!=cnt2){
			LL x=abs(sum1-sum2);
			if(x<maxx){
				puts("-1");continue;
			}
			if(judge(x)){
				printf("%lld\n",g(x));
			}else{
				puts("-1");continue;
			}
		}else{
			LL l=maxx-1,r=INF-10,M;
			bool ok=0;
			while(l+1<r){
				M=(l+r)>>1;
			//	printf("%lld\n",M);
				if(judge(M)){
					ok=1;
					r=M;
				}else l=M;
			}
			if(ok){
				printf("%lld\n",g(r));
			}else{
				puts("-1");
			}
		}
	}
	return 0 ;
}
