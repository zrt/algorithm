/*
ID: zrtdrea1
PROG:
LANG: C++
*/
//ÓÀÔ¶×ö×Ô¼º»á×öµÄÌâ¾ÍÓÀÔ¶»¹ÊÇÔ­À´µÄÑù×Ó
#include<cstdio>
#include<cstring>
#include<queue>
//by zrt
//problem:
using namespace std;
int n,r;
int H[5005],X[200005],P[200005],E[200005],tot;
int ds[5005],dt[5005];
inline void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;E[tot]=z;
}
struct N{
	int x,w;
	friend bool operator < (N a,N b){
		return a.w>b.w;
	}
	N(int a=0,int b=0){
		x=a,w=b;
	}
}t;
priority_queue<N> q;
int st,ans=~0U>>1;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	memset(ds,0x3f,sizeof ds);
	memset(dt,0x3f,sizeof dt);
	scanf("%d%d",&n,&r);
	ds[1]=0;dt[n]=0;
	for(int i=0;i<r;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);add(y,x,z);
	}
	q.push(N(1,0));
	while(!q.empty()){
		t=q.top();q.pop();
		if(t.w!=ds[t.x]) continue;
		for(int i=H[t.x];i;i=X[i]){
			if(ds[P[i]]>ds[t.x]+E[i]){
				ds[P[i]]=ds[t.x]+E[i];
				q.push(N(P[i],ds[P[i]]));
			}
		}
	}
	st=ds[n];
	q.push(N(n,0));
	while(!q.empty()){
		t=q.top();q.pop();
		if(t.w!=dt[t.x]) continue;
		for(int i=H[t.x];i;i=X[i]){
			if(dt[P[i]]>dt[t.x]+E[i]){
				dt[P[i]]=dt[t.x]+E[i];
				q.push(N(P[i],dt[P[i]]));
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=H[i];j;j=X[j]){
			if(ds[i]+dt[P[j]]+E[j]!=st){
				if(ds[i]+dt[P[j]]+E[j]<ans){
					ans=ds[i]+dt[P[j]]+E[j];
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
