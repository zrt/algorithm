#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
using namespace std;
typedef long long LL;
const long long inf=1e17;
LL head[100000],ver[100000],nex[100000],edge[100000],tot;
LL d[3010];
LL a[50][50],n,m;
LL b[50][50];
int S=0,T=44*44+1;
LL s1=0,s2=0,cnt1=0,cnt2=0;
void add(int x,int y,LL w){
	ver[++tot]=y; edge[tot]=w; nex[tot]=head[x]; head[x]=tot;
	ver[++tot]=x; edge[tot]=0; nex[tot]=head[y]; head[y]=tot; 
}
bool bfs(){
	queue<int> que;
	while(!que.empty()) que.pop();
	memset(d,0,sizeof d);
	que.push(S);
	d[S]=1;
	while(!que.empty()){
		int now=que.front();
		que.pop();
		for(int i=head[now];i;i=nex[i]){
			int v=ver[i];
			if(!d[v]&&edge[i]){
				d[v]=d[now]+1;
				que.push(v);
				if(v==T) return 1;
			}
		}
	}
	return 0;
}
LL dinic(int now,LL f){
	LL temp=f;
	if(now==T) return f;
	for(int i=head[now];i;i=nex[i]){
		int v=ver[i];
		if(d[v]==d[now]+1&&edge[i]&&temp){
			LL k=dinic(v,min(edge[i],temp));
			if(!k) d[v]=0;
			edge[i]-=k;
			edge[i^1]+=k;
			temp-=k;
		}
	}
	return f-temp;
}
bool cal(LL x){
	tot=1;
	LL sum=x*cnt1-s1;
	memset(head,0,sizeof(head));
	memset(d,0,sizeof(d));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			if(x<a[i][j]) return 0;
			if((i+j)&1){
				add(S,b[i][j],x-a[i][j]);
			}
			else add(b[i][j],T,x-a[i][j]);
			if((i+j)&1){
				if(i+1>=1&&i+1<=n) add(b[i][j],b[i+1][j],inf);
				if(i-1>=1&&i-1<=n) add(b[i][j],b[i-1][j],inf);
				if(j+1>=1&&j+1<=m) add(b[i][j],b[i][j+1],inf);
				if(j-1>=1&&j-1<=m) add(b[i][j],b[i][j-1],inf);
			}
		}
	LL maxflow=0,temp;	
	while(bfs())
		while(temp=dinic(S,inf)) maxflow+=temp;
	return maxflow==sum;	 
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		LL p=0,l=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				scanf("%lld",&a[i][j]),b[i][j]=++p,l=max(l,a[i][j]);
		s1=0,s2=0,cnt1=0,cnt2=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				if((i+j)%2==0){
					cnt1++;
					s1+=a[i][j];
				}
				else cnt2++,s2+=a[i][j];
			}
		if(cnt1!=cnt2){
			if((s1-s2)%(cnt1-cnt2)!=0) puts("-1");
			else{
				LL x=(s1-s2)/(cnt1-cnt2);
				if(x>=l&&cal(x))
					printf("%lld\n",cnt1*x-s1);
				else puts("-1");
			}
			continue;
		}
		if(s1!=s2){
			puts("-1");
			continue;
		}
		LL r=inf;
		LL ans=-1;
		while(l<=r){
			LL mid=(l+r)>>1;
			if(cal(mid)) ans=mid,r=mid-1;
			else l=mid+1;
		}
		if(ans==-1) puts("-1");
		else printf("%lld\n",ans*cnt1-s1);
	}
	return 0;
}
