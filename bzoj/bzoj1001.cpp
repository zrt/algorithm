#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
//  by zrt
//  problem:
//  无论你在什么时候开始，重要的是开始以后就不要停止。
using namespace std ;
typedef long long ll ;
const double eps(1e-10) ;
const int inf(0x3f3f3f3f) ;
int b1[1005][1005],b2[1005][1005],b3[1005][1005];
int dian[3030075];
int n,m;
int H[3030075],P[14030075],X[14030075],tot;
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
int d[3030075];
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
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin) ;
	freopen("out.txt","w",stdout) ;
	#endif
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<m;j++){
			scanf("%d",&b1[i][j]);
		}
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&b2[i][j]);
		}
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<m;j++){
			scanf("%d",&b3[i][j]);
		}
	}
	int now(0);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(j<m){
				now=(i-1)*m*3+j;
				dian[now]=b1[i][j];
				if(i>1){
					add(now,now-m);
					add(now,now-2*m);
				}
				if(i<n){
					add(now,now+m+1);
					add(now,now+2*m+1);
				}
			}
			if(i<n){
				now=(i-1)*m*3+j+m;
				dian[now]=b2[i][j];
				if(j>1){
					add(now,now-m-1);
					add(now,now+m-1);
				}
				if(j<m){
					add(now,now+m);
					add(now,now+2*m);
				}
			}
			if(i<n&&j<m){
				now=(i-1)*m*3+j+2*m;
				dian[now]=b3[i][j];
				add(now,now-2*m);
				add(now,now-m);
				add(now,now+m);
				add(now,now-m+1);
			}
		}
	}
	memset(d,0x3f,sizeof d);
	for(int i=1;i<n;i++){
		d[3*(i-1)*m+m+1]=dian[3*(i-1)*m+m+1];
		q.push(N(3*(i-1)*m+m+1,d[3*(i-1)*m+m+1]));
	}
	for(int i=1;i<m;i++){
		d[(n-1)*m*3+i]=dian[(n-1)*m*3+i];
		q.push(N((n-1)*m*3+i,d[(n-1)*m*3+i]));
	}
	int x;
	while(!q.empty()){
		x=q.top().x;q.pop();
		for(int i=H[x];i;i=X[i]){
			if(d[P[i]]>d[x]+dian[P[i]]){
				d[P[i]]=d[x]+dian[P[i]];
				q.push(N(P[i],d[P[i]]));
			}
		}
		while(!q.empty()&&d[q.top().x]!=q.top().w) q.pop();
	}
	int ans=inf;
	for(int i=1;i<m;i++){
		ans=min(ans,d[i]);
	}
	for(int i=1;i<n;i++){
		ans=min(ans,d[(i-1)*3*m+2*m]);
	}
	printf("%d\n",ans);
	return 0 ;
}
