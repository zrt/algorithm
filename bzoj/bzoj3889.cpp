#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<map>
using namespace std;
map<int,int> mp;
typedef long long LL;
int S,T,m;
LL dis[1005][1005];
int dis2[1005][1005];
int a[1005];
int n;
struct N{
	int x;LL w;
	N(int a=0,LL b=0){
		x=a,w=b;
	}
	friend bool operator < (const N&a,const N&b){
		return a.w>b.w;
	}
};
priority_queue<N> q;
LL d[1005];
LL ans;
void dijkstra(){
	memset(d,0x3f,sizeof d);
	d[S]=0;q.push(N(S,0));
	while(!q.empty()){
		int x=q.top().x;q.pop();
		for(int i=1;i<=n;i++){
			if(d[i]>d[x]+dis[x][i]){
				d[i]=d[x]+dis[x][i];
				q.push(N(i,d[i]));
			}
		}
	}
}
int main(){
	scanf("%d%d%d",&S,&T,&m);
	memset(dis,0x3f,sizeof dis);
	memset(dis2,0x3f,sizeof dis2);
	mp[S]=++n;mp[T]=++n;
	S=mp[S],T=mp[T];
	for(int i=0,x;i<m;i++){
		LL y;
		scanf("%lld%d",&y,&x);
		for(int j=0;j<x;j++){
			scanf("%d",&a[j]);
			if(mp.find(a[j])==mp.end()) mp[a[j]]=++n;
			a[j]=mp[a[j]];
		}
		for(int j=0;j<x;j++){
			for(int k=j+1;k<x;k++){
			//	dis[a[j]][a[k]]=min(dis[a[j]][a[k]],y);
				if(y<dis[a[j]][a[k]]){
					dis[a[j]][a[k]]=y;
					dis2[a[j]][a[k]]=k-j;
				}
				if(dis[a[j]][a[k]]==y){
					dis2[a[j]][a[k]]=min(dis2[a[j]][a[k]],k-j);
				}
			}
		}
	}
	for(int i=1;i<=n;i++) dis[i][i]=0,dis2[i][i]=0;
	dijkstra();
	ans=d[T];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) dis[i][j]=0;
			else{
				if(d[i]+dis[i][j]==d[j]){
					dis[i][j]=dis2[i][j];
				}else dis[i][j]=0x3f3f3f3f3f3f3f3fLL;
			}
		}
	}

	dijkstra();
	if(ans!=0x3f3f3f3f3f3f3f3f) printf("%lld %lld\n",ans,d[T]);
	else puts("-1 -1");
	return 0;
}
