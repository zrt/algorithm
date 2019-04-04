#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
//  by zrt
//  problem:
//  无论你在什么时候开始，重要的是开始以后就不要停止。
using namespace std ;
typedef long long LL ;
const double eps(1e-10) ;
const int inf(0x3f3f3f3f) ;
int tt;
int m,n;
int h[205],l[25];
int S,T;
int sum1,sum2;
bool ff;
int H[305],X[90000],P[90000],tot,flow[90000];
inline void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;flow[tot]=z;
}
char s[10];
int minn[205][25],maxx[205][25];
int sum;
void addedge(int x,int y,int z,int k){//max min
	add(x,y,z-k);
	add(y,x,0);
	add(x,T,k);
	add(T,x,0);
	add(S,y,k);
	add(y,S,0);
	sum+=k;
}
int num[205][25];
int d[406];
queue<int> q;
bool bfs(){
	memset(d,0,sizeof d);
	d[S]=1;q.push(S);
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=H[x];i;i=X[i]){
			if(flow[i]>0&&!d[P[i]]){
				d[P[i]]=d[x]+1;
				q.push(P[i]);
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
//	printf("%d\n",f-a);
	return f-a;
}
int Dinic(){
	int f=0;
	while(bfs()) f+=dfs(S,inf);
	return f;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin) ;
	freopen("out.txt","w",stdout) ;
	#endif
	scanf("%d",&tt);ff=1;
	while(tt--){
		if(ff) ff=0;else puts("");
		scanf("%d%d",&m,&n);
		tot=1;memset(H,0,sizeof H);
		memset(maxx,0x3f,sizeof maxx);
		memset(minn,0,sizeof minn);
		sum1=sum2=0;
		for(int i=1;i<=m;i++){
			scanf("%d",&h[i]);sum1+=h[i];
		}
		for(int i=1;i<=n;i++){
			scanf("%d",&l[i]);sum2+=l[i];
		}
		int ppp;
		scanf("%d",&ppp);
		while(ppp--){
			int x,y,z;
			scanf("%d%d%s%d",&x,&y,s,&z);
			if(s[0]=='='){
				if(x!=0&&y!=0){
					minn[x][y]=max(minn[x][y],z);
					maxx[x][y]=min(maxx[x][y],z);
				}else if(y!=0&&x==0){
					for(int i=1;i<=m;i++) minn[i][y]=max(minn[i][y],z),maxx[i][y]=min(maxx[i][y],z);
				}else if(x!=0&&y==0){
					for(int i=1;i<=n;i++) minn[x][i]=max(minn[x][i],z),maxx[x][i]=min(maxx[x][i],z);
				}else{
					for(int i=1;i<=m;i++) for(int j=1;j<=n;j++){
						minn[i][j]=max(minn[i][j],z);
						maxx[i][j]=min(maxx[i][j],z);
					}
				}
			}else if(s[0]=='>'){
				if(x!=0&&y!=0){
					minn[x][y]=max(minn[x][y],1+z);
				}else if(y!=0&&x==0){
					for(int i=1;i<=m;i++) minn[i][y]=max(minn[i][y],1+z);
				}else if(x!=0&&y==0){
					for(int i=1;i<=n;i++) minn[x][i]=max(minn[x][i],1+z);
				}else{
					for(int i=1;i<=m;i++) for(int j=1;j<=n;j++){
						minn[i][j]=max(minn[i][j],1+z);
					}
				}
			}else if(s[0]=='<'){
				if(x!=0&&y!=0){
					maxx[x][y]=max(maxx[x][y],z-1);
				}else if(y!=0&&x==0){
					for(int i=1;i<=m;i++) maxx[i][y]=min(maxx[i][y],z-1);
				}else if(x!=0&&y==0){
					for(int i=1;i<=n;i++) maxx[x][i]=min(maxx[x][i],z-1);
				}else{
					for(int i=1;i<=m;i++) for(int j=1;j<=n;j++){
						maxx[i][j]=min(maxx[i][j],z-1);
					}
				}
			}
		}
		if(sum1!=sum2) goto ed;
		S=n+m+2,T=n+m+3;sum=0;
		addedge(n+m+1,0,inf,0);
		for(int i=1;i<=m;i++) addedge(0,i,h[i],h[i]);
		for(int i=1;i<=n;i++) addedge(i+m,n+m+1,l[i],l[i]);
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				if(minn[i][j]>maxx[i][j]){
					goto ed;
				}
				addedge(i,j+m,maxx[i][j],minn[i][j]);
			}
		}
	//	Dinic();
		if(Dinic()!=sum) {
			goto ed;
		}
		
		for(int i=1;i<=m;i++){
			for(int j=H[i];j;j=X[j]){
	//			printf("$%d %d %d\n",i,P[j]-m,maxx[200][3]);
				if(P[j]-m<=n&&P[j]-m>0){
					num[i][P[j]-m]=maxx[i][P[j]-m]-flow[j];
				}
			}
		}
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++) printf("%d ",num[i][j]);
			puts("");
		}
		if(0){
			ed: puts("IMPOSSIBLE");
		}
	}
	return 0 ;
}
