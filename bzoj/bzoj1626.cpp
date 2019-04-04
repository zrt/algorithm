/*
ID: zrtdrea1
PROG: PRIM
LANG: C++
*/
//ÓÀÔ¶×ö×Ô¼º»á×öµÄÌâ¾ÍÓÀÔ¶»¹ÊÇÔ­À´µÄÑù×Ó
#include<cstdio>
#include<cmath>
//by zrt
//problem:
using namespace std;
int p,q,z,n,m;double x[1005],y[1005];double map[1005][1005],ans;
double Dis(int i,int j){
	return sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
}
double dis[1005];
bool vis[1005];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lf%lf",&x[i],&y[i]);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			map[i][j]=map[j][i]=Dis(i,j);
		}
	}
	for(int i=0;i<m;i++){
		scanf("%d%d",&p,&q);
		map[p][q]=map[q][p]=0.0;
	}
	for(int i=2;i<=n;i++) dis[i]=1e100;
	dis[1]=0.0;
	for(int i=0;i<n;i++){
		int k;
		double minn=1e100;
		for(int j=1;j<=n;j++){
			if((!vis[j])&&dis[j]<minn){
				minn=dis[j];k=j;
			}
		}
		vis[k]=1;
		ans+=dis[k];
		for(int j=1;j<=n;j++){
		//	if(j==k) continue;
			if(!vis[j]&&dis[j]>map[k][j]){
				dis[j]=map[k][j];
			}
		}
	}
	printf("%.2f",ans);
	return 0;
}
